#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

/*
   https://cs.stackexchange.com/questions/121293/time-complexity-for-the-restore-ip-addresses-problem

   ************************

   The time complexity in the worst case is bounded below by the number of decompositions of s

   T(n,k)=T(n−1,k−1)+T(n−2,k−1)+T(n−3,k−1) --> The highest number can be 255 and an ip address has atmax 4 parts (k=4)

   We can roughly replace this by T(n,k)=3T(n−3,k−1) (a lower bound) which leads to

   T(n,k)=min(3^(n/3),3^k).

   s=11111111

    1.111.1.111
	1.111.11.11
	1.111.111.1
	11.11.1.111
	11.11.11.11
	11.11.111.1
	111.1.1.111
	111.1.11.11
	111.1.111.1

	On an approximate basis we can say that the time complexity is around O(3^n).
*/

class Solution {
public:

	void recur(string &s, int n, int si, vector<string> &v, vector<string> &ans) {
		if (si >= n) {
			if ((int)v.size() == 4) {
				string s1 = "";
				for (auto &str : v) {
					s1 += str;
					s1 += '.';
				}

				s1.pop_back();

				ans.pb(s1);
			}

			return;
		}

		for (int i = si; i < n; i++) {

			string temp = s.substr(si, (i - si) + 1);
			int x = stoi(temp);
			string temp1 = to_string(x);

			if ((temp != temp1) || x > 255) {
				break;
			}

			v.pb(temp1);

			recur(s, n, i + 1, v, ans);

			v.pop_back();
		}
	}

	vector<string> restoreIpAddresses(string s) {

		int n = s.length();

		vector<string> v, ans;

		recur(s, n, 0, v, ans);

		return ans;
	}
};