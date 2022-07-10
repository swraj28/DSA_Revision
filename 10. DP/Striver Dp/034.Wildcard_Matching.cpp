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

	bool recur(string &p, int &n, int si, string &s, int &m, int si1, vector<vector<int>> &dp) {
		if (si >= n) {
			return si1 >= m;
		}

		if (dp[si][si1] != -1) {
			return dp[si][si1];
		}

		if (si1 >= m) {
			if (p[si] == '*') {
				return dp[si][si1] = recur(p, n, si + 1, s, m, si1, dp);
			}

			return dp[si][si1] = false;
		}

		if (p[si] == s[si1] || p[si] == '?') {
			return dp[si][si1] = recur(p, n, si + 1, s, m, si1 + 1, dp);
		}

		if (p[si] == '*') {
			return dp[si][si1] = recur(p, n, si + 1, s, m, si1, dp) || recur(p, n, si, s, m, si1 + 1, dp);
		}

		return dp[si][si1] = false;
	}

	bool isMatch(string s, string p) {

		int n = p.length(), m = s.length();

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

		return recur(p, n, 0, s, m, 0, dp);

		//******************************Iterative DP********************************************

		vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

		//  Base Condition:-

		dp[0][0] = true;

		for (int i = 1; i <= n; i++) {
			if (p[i - 1] == '*') {
				dp[i][0] = true;
			} else {
				break;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
					dp[i][j] = dp[i - 1][j - 1];
				} else if (p[i - 1] == '*') {
					dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
				}
			}
		}

		return dp[n][m];

		//*************************************** Space Optimized Iterative DP*********************

		vector<bool> prev(m + 1, false);
		prev[0] = 1;

		for (int i = 1; i <= n; i++) {

			vector<bool> curr(m + 1, 0);

			if (prev[0] == 1 && p[i - 1] == '*') {
				curr[0] = 1;
			}

			for (int j = 1; j <= m; j++) {
				if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
					curr[j] = prev[j - 1];
				} else if (p[i - 1] == '*') {
					curr[j] = (prev[j] || curr[j - 1]);
				}
			}

			prev = curr;
		}

		return prev[m];
	}
};