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

// T.c:- O(n^3)

class Solution {
public:

	bool find(long long n1, long long n2, string s, vector<int> &ans) {
		if (s.length() == 0) {
			return true;
		}

		string n3 = to_string(n1 + n2);
		int len_rem = min(s.length(), n3.length());

		if (s.substr(0, len_rem) == n3) {

			ll val = stol(n3);

			if (val > INT_MAX) {
				return false;
			}

			ans.pb((int)val);

			return find(n2, stol(n3), s.substr(len_rem), ans);
		}

		return false;
	}

	vector<int> splitIntoFibonacci(string num) {

		int n = num.length();

		// length of n1
		for (int i = 1; i < n - 1; i++) {

			long long n1 = stol(num.substr(0, i));

			if (num.substr(0, i) != to_string(n1)) {
				break;
			}
			if (n1 > INT_MAX) {
				break;
			}

			// Length of n2
			for (int j = i + 1; j < n; j++) {

				long long  n2 = stol(num.substr(i, (j - i)));

				if (to_string(n2) != num.substr(i, j - i)) {
					break;
				}
				if (n2 > INT_MAX) {
					break;
				}

				vector<int> ans;
				ans.pb((int)n1);
				ans.pb((int)n2);

				bool found = find(n1, n2, num.substr(j), ans);

				if (found)return ans;
			}
		}

		return {};
	}
};