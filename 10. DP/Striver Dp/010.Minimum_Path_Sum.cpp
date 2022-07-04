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

// Iterative Dynamic Programming:-

int minSumPath(vector<vector<int>> &grid) {

	int n = grid.size(), m = grid[0].size();

	vector<vector<int>> dp(n, vector<int>(m, 0));

	dp[0][0] = grid[0][0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = (dp[i - 1][0] + grid[i][0]);
	}

	for (int i = 1; i < m; i++) {
		dp[0][i] = (dp[0][i - 1] + grid[0][i]);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}

	return dp[n - 1][m - 1];
}

// Space Optimization:- Dynamic Programming

int minSumPath(vector<vector<int>> &grid) {

	int n = grid.size(), m = grid[0].size();

	vector<int> prev(m, 0);

	for (int i = 0; i < n; i++) {

		vector<int> curr(m, 0);

		for (int j = 0; j < m; j++) {

			if (i == 0 && j == 0) {
				curr[j] = grid[i][j];
				continue;
			}

			int up = grid[i][j], left = grid[i][j];

			if (i > 0) {
				up += prev[j];
			} else {
				up += (1e8);
			}

			if (j > 0) {
				left = (curr[j - 1]);
			} else {
				left += (1e8);
			}

			curr[j] = min(up, left);
		}

		prev = curr;
	}

	return prev[m - 1];
}