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

// Recursion + Memoization :-

class Solution {
public:

	int dp[205][205];

	int recur(vector<vector<int>>& triangle, int n, int r, int c) { // This Function will return the minimum value
		if (r == (n - 2)) {
			return triangle[r][c] + min({triangle[r + 1][c], triangle[r + 1][c + 1]});
		}

		if (dp[r][c] != -1) {
			return dp[r][c];
		}

		return dp[r][c] = triangle[r][c] + min({recur(triangle, n, r + 1, c), recur(triangle, n, r + 1, c + 1)});
	}

	int minimumTotal(vector<vector<int>>& triangle) {

		int n = triangle.size();

		if (n == 1) {
			return triangle[0][0];
		}

		ms(dp, -1);

		return recur(triangle, n, 0, 0);
	}
};

// Iterative DP :-

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {

		int n = triangle.size();

		if (n == 1) {
			return triangle[0][0];
		}

		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

		dp[0][0] = triangle[0][0];

		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if ((j - 1) >= 0) {
					dp[i][j] = triangle[i][j] + min({dp[i - 1][j], dp[i - 1][j - 1]});
				} else {
					dp[i][j] = triangle[i][j] + dp[i - 1][j];
				}
			}
		}

		// cout<<dp[1][0]<<" "<<dp[1][1]<<endl;

		return *min_element(all(dp[n - 1]));
	}
};

// Space Optimization :-

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {

		int n = triangle.size();

		if (n == 1) {
			return triangle[0][0];
		}

		vector<int> prev(n, INT_MAX);

		for (int i = 0; i < n; i++) {

			vector<int> curr(n, INT_MAX);

			for (int j = 0; j <= i; j++) {

				if (i == 0 && j == 0) {
					curr[j] = triangle[0][0];
					continue;
				}

				if ((j - 1) >= 0) {
					curr[j] = triangle[i][j] + min({prev[j], prev[j - 1]});
				} else {
					curr[j] = triangle[i][j] + prev[j];
				}
			}

			prev = curr;
		}

		return *min_element(all(prev));
	}
};
