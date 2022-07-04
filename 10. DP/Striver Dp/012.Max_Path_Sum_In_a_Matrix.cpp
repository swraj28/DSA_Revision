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

class Solution {
public:

	int recur(vector<vector<int>>& matrix, int n, int m, int i, int j, vector<vector<int>> &dp) { // This function will min cost from a particular index(i,j) of first row
		if (i >= n) {
			return 0;
		}

		if (j<0 or j >= m) {
			return 0;
		}

		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		int v1 = INT_MAX, v2 = INT_MAX, v3 = INT_MAX;

		if ((j - 1) >= 0) {
			v1 = matrix[i][j] + recur(matrix, n, m, i + 1, j - 1, dp);
		}

		if (j >= 0 and j < m) {
			v2 = matrix[i][j] + recur(matrix, n, m, i + 1, j, dp);
		}

		if ((j + 1) < m) {
			v3 = matrix[i][j] + recur(matrix, n, m, i + 1, j + 1, dp);
		}

		return dp[i][j] = min({v1, v2, v3});
	}

	int minFallingPathSum(vector<vector<int>>& matrix) {

		int n = matrix.size();
		int m = matrix[0].size();

		int ans = INT_MAX;

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

		for (int i = 0; i < m; i++) {
			ans = min(ans, recur(matrix, n, m, 0, i, dp));
		}

		return ans;
	}
};

// Iterative Dynamic Programming:-


class Solution {
public:

	int minFallingPathSum(vector<vector<int>>& matrix) {

		int n = matrix.size();
		int m = matrix[0].size();

		vector<vector<int>> dp(n, vector<int>(m, 0));

		for (int i = 0; i < m; i++) {
			dp[0][i] = matrix[0][i];
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {

				int v1 = INT_MAX, v2 = INT_MAX, v3 = INT_MAX;

				v2 = dp[i - 1][j] + matrix[i][j];

				if ((j - 1) >= 0) {
					v1 = matrix[i][j] + dp[i - 1][j - 1];
				}

				if ((j + 1) < m) {
					v3 = matrix[i][j] + dp[i - 1][j + 1];
				}

				dp[i][j] = min({v1, v2, v3});
			}
		}

		return *min_element(all(dp[n - 1]));
	}
};

// Space Optimization :-

class Solution {
public:

	int minFallingPathSum(vector<vector<int>>& matrix) {

		int n = matrix.size();
		int m = matrix[0].size();

		vector<int> prev(m, 0);

		for (int i = 0; i < m; i++) {
			prev[i] = matrix[0][i];
		}

		for (int i = 1; i < n; i++) {

			vector<int> curr(m, 0);

			for (int j = 0; j < m; j++) {

				int v1 = INT_MAX, v2 = INT_MAX, v3 = INT_MAX;

				v2 = prev[j] + matrix[i][j];

				if ((j - 1) >= 0) {
					v1 = matrix[i][j] + prev[j - 1];
				}

				if ((j + 1) < m) {
					v3 = matrix[i][j] + prev[j + 1];
				}

				curr[j] = min({v1, v2, v3});
			}

			prev = curr;
		}

		return *min_element(all(prev));
	}
};