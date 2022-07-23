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

class Solution {
public:

	bool recur(string s, ll val) {
		if (s.length() == 0) {
			return true;
		}

		for (int i = 0; i < s.length(); i++) {

			string temp = s.substr(0, (i + 1));

			ll val1 = stoll(temp);

			if (val1 > val) {
				return false;
			}

			if ((val - val1) == 1) {

				bool rec_res = recur(s.substr(i + 1), val1);

				if (rec_res == true) {
					return true;
				}
			}
		}

		return false;
	}

	bool splitString(string s) {

		int n = s.length();

		for (int i = 0; i < n - 1; i++) {

			string temp = s.substr(0, (i + 1));

			if (temp.length() >= 18) {
				return false;
			}

			ll val = stoll(temp);

			if (recur(s.substr(i + 1), val)) {
				return true;
			}
		}

		return false;
	}
};