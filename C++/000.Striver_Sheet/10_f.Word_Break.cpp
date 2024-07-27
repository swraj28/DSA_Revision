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

	bool recur(string &s, int n, int si, unordered_set<string> &st, vector<int> &dp) {
		if (si >= n) {
			return true;
		}

		if (dp[si] != -1) {
			return dp[si];
		}

		for (int i = si; i < n; i++) {

			string temp = s.substr(si, (i - si) + 1);

			if (st.count(temp)) {

				bool rec_res = recur(s, n, i + 1, st, dp);

				if (rec_res == true) {
					return dp[si] = true;
				}
			}
		}

		return dp[si] = false;
	}

	bool wordBreak(string s, vector<string>& wordDict) {

		unordered_set<string> st;

		for (auto word : wordDict) {
			st.insert(word);
		}

		int n = s.length();

		vector<int> dp(n + 1, -1);

		return recur(s, n, 0, st, dp);
	}
};
