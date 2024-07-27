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

	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n));
		return dfs(dp, 0, 0);
	}

	int dfs(vector<vector<int>>& dp, int i, int j) {
		if (i >= size(dp)   || j >= size(dp[0]))   return 0;    // out of bounds - invalid

		if (i == size(dp) - 1 && j == size(dp[0]) - 1) return 1; // reached end - valid path

		if (dp[i][j]) return dp[i][j];                          // directly return if already calculated

		return dp[i][j] = dfs(dp, i + 1, j) + dfs(dp, i, j + 1); // store the result in dp[i][j] and then return
	}
};

class Solution {
public:
	int uniquePaths(int m, int n) {

		int dp[m][n];

		for (int i = 0; i < m; i++) {
			dp[i][0] = 1;
		}
		for (int i = 0; i < n; i++) {
			dp[0][i] = 1;
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}

		return dp[m - 1][n - 1];

	}
};

// Iterative --> Space Optimization

//  dp matrix from m x n grid to 2 x n grid denoting the values for current and previous row

class Solution {
public:
	int uniquePaths(int m, int n) {

		vector<int> prev(n, 0);

		for (int i = 0; i < m; i++) {

			vector<int> curr(n, 0);

			for (int j = 0; j < n; j++) {

				if (i == 0 && j == 0) {
					curr[j] = 1;
					continue;
				}

				int up = 0;
				int left = 0;

				if (i > 0)
					up = prev[j];
				if (j > 0)
					left = curr[j - 1];

				curr[j] = up + left;
			}

			prev = curr;
		}

		return prev[n - 1];
	}
};