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

	int recur(string &a, string &b, int &n, int &m, int si1, int si2, vector<vector<int>> &dp) {
		if (si1 >= n) {
			return (m - si2);
		}

		if (si2 >= m) {
			return (n - si1);
		}

		if (dp[si1][si2] != -1) {
			return dp[si1][si2];
		}

		if (a[si1] == b[si2]) {
			return dp[si1][si2] = recur(a, b, n, m, si1 + 1, si2 + 1, dp);
		}

		int Delete = recur(a, b, n, m, si1 + 1, si2, dp);
		int Insert = recur(a, b, n, m, si1, si2 + 1, dp);
		int Replace = recur(a, b, n, m, si1 + 1, si2 + 1, dp);

		return dp[si1][si2] = 1 + min({Delete, Insert, Replace});
	}

	int minDistance(string word1, string word2) {

		int n = word1.length(), m = word2.length();

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

		return recur(word1, word2, n, m, 0, 0, dp);

		//*****************************Iterative DP***********************************

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		// Base Condition:-

		for (int j = 0; j <= m; j++) {
			dp[0][j] = j;
		}

		for (int i = 0; i <= n; i++) {
			dp[i][0] = i;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {

				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = 0 + (dp[i - 1][j - 1]);
				} else {
					int Delete = dp[i - 1][j];
					int Insert = dp[i][j - 1];
					int Replace = dp[i - 1][j - 1];

					dp[i][j] = 1 + min({Delete, Insert, Replace});
				}
			}
		}

		return dp[n][m];

		//*************************************** Space Optimized Iterative DP*********************

		vector<int> prev(m + 1, 0);

		for (int j = 0; j <= m; j++) {
			prev[j] = j;
		}

		for (int i = 1; i <= n; i++) {

			vector<int> curr(m + 1, 0);
			curr[0] = i;

			for (int j = 1; j <= m; j++) {

				if (word1[i - 1] == word2[j - 1]) {
					curr[j] = 0 + (prev[j - 1]);
				} else {
					int Delete = prev[j];
					int Insert = curr[j - 1];
					int Replace = prev[j - 1];

					curr[j] = 1 + min({Delete, Insert, Replace});
				}
			}

			prev = curr;
		}

		return prev[m];
	}
};