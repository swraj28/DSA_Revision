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

	int recur(string &a, string &b, int n, int m, int si1, int si2, vector<vector<int>> &dp) {

		if (si1 >= n or si2 >= m) {
			return 0;
		}

		if (dp[si1][si2] != 0) {
			return dp[si1][si2];
		}

		if (a[si1] == b[si2]) {
			return dp[si1][si2] = 1 + recur(a, b, n, m, si1 + 1, si2 + 1, dp);
		}

		return dp[si1][si2] = max({recur(a, b, n, m, si1 + 1, si2, dp), recur(a, b, n, m, si1, si2 + 1, dp)});
	}

	int longestCommonSubsequence(string text1, string text2) {

		int n = text1.length();
		int m = text2.length();

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

		return recur(text1, text2, n, m, 0, 0, dp);

		//*********************************Iterative DP***********************************

		vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (text1[i - 1] == text2[j - 1]) {
					dp[i][j] = (dp[i - 1][j - 1] + 1);
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		return dp[n][m];

		//**************************** Space Optimized Iterative DP*****************************

		vector<int> prev(m + 1, 0);

		for (int i = 1; i <= n; i++) {

			vector<int> curr(m + 1, 0);

			for (int j = 1; j <= m; j++) {
				if (text1[i - 1] == text2[j - 1]) {
					curr[j] = (prev[j - 1] + 1);
				} else {
					curr[j] = max(prev[j], curr[j - 1]);
				}
			}

			prev = curr;
		}

		return prev[m];
	}
};