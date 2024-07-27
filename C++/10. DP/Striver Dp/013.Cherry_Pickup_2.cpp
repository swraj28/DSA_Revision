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

	int dp[80][80][80];

	int recur(vector<vector<int>>& grid, int n, int m, int r1, int c1, int c2) { // This Function will return the max value.

		if ((r1<0 or r1 >= n or c1<0 or c1 >= m) or (c2<0 or c2 >= m)) {
			return INT_MIN;
		}

		if (r1 == (n - 1)) {
			if ((c1 == c2)) {
				return grid[r1][c1];
			} else {
				return (grid[r1][c1] + grid[r1][c2]);
			}
		}


		if (dp[r1][c1][c2] != -1) {
			return dp[r1][c1][c2];
		}

		int val = 0;

		if ((c1 == c2)) {
			val += grid[r1][c1];
		} else {
			val = (grid[r1][c1] + grid[r1][c2]);
		}

		int a = recur(grid, n, m, r1 + 1, c1 - 1, c2 - 1);
		int b =  recur(grid, n, m, r1 + 1, c1 - 1, c2);
		int c =  recur(grid, n, m, r1 + 1, c1 - 1, c2 + 1);

		int d = recur(grid, n, m, r1 + 1, c1, c2 - 1);
		int e = recur(grid, n, m, r1 + 1, c1,  c2);
		int f = recur(grid, n, m, r1 + 1, c1,  c2 + 1);

		int g = recur(grid, n, m, r1 + 1, c1 + 1,  c2 - 1);
		int h = recur(grid, n, m, r1 + 1, c1 + 1,  c2);
		int i = recur(grid, n, m, r1 + 1, c1 + 1, c2 + 1);

		val += max({a, b, c, d, e, f, g, h, i});

		return dp[r1][c1][c2] = val;
	}



	int cherryPickup(vector<vector<int>>& grid) {

		int n = grid.size();
		int m = grid[0].size();

		memset(dp, -1, sizeof(dp));

		return recur(grid, n, m, 0, 0, m - 1);
	}
};


// Iterative Dp:-

class Solution {
public:

	int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
		// Write your code here.
		vector < vector < vector < int >>> dp(n, vector < vector < int >> (m,
		                                      vector < int > (m, 0)));

		for (int j1 = 0; j1 < m; j1++) {
			for (int j2 = 0; j2 < m; j2++) {
				if (j1 == j2)
					dp[n - 1][j1][j2] = grid[n - 1][j1];
				else
					dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
			}
		}

		//Outer Nested Loops for travering DP Array
		for (int i = n - 2; i >= 0; i--) {
			for (int j1 = 0; j1 < m; j1++) {
				for (int j2 = 0; j2 < m; j2++) {

					int maxi = INT_MIN;

					//Inner nested loops to try out 9 options
					for (int di = -1; di <= 1; di++) {
						for (int dj = -1; dj <= 1; dj++) {

							int ans;

							if (j1 == j2)
								ans = grid[i][j1];
							else
								ans = grid[i][j1] + grid[i][j2];

							if ((j1 + di < 0 || j1 + di >= m) ||
							        (j2 + dj < 0 || j2 + dj >= m))

								ans += -1e9;
							else
								ans += dp[i + 1][j1 + di][j2 + dj];

							maxi = max(ans, maxi);
						}
					}
					dp[i][j1][j2] = maxi;
				}
			}
		}

		return dp[0][0][m - 1];

	}

	int cherryPickup(vector<vector<int>>& grid) {

		int n = grid.size();
		int m = grid[0].size();

		return maximumChocolates(n, m, grid);
	}
};

// Space Optimized Dynamic programming:-

class Solution {
public:

	int maximumChocolates(int n, int m, vector < vector < int >> & grid) {

		// 1dp--> 2 variable
		// 2dp---> 2 vectors
		// 3dp--> 2d dp

		// Space Optimization Appraoch that we have followed previously:-


		vector<vector<int>> front(m, vector<int>(m, 0));
		vector<vector<int>> curr(m, vector<int>(m, 0));

		for (int j1 = 0; j1 < m; j1++) {
			for (int j2 = 0; j2 < m; j2++) {
				if (j1 == j2)
					front[j1][j2] = grid[n - 1][j1];
				else
					front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
			}
		}

		//Outer Nested Loops for travering DP Array
		for (int i = n - 2; i >= 0; i--) {
			for (int j1 = 0; j1 < m; j1++) {
				for (int j2 = 0; j2 < m; j2++) {

					int maxi = INT_MIN;

					//Inner nested loops to try out 9 options
					for (int di = -1; di <= 1; di++) {
						for (int dj = -1; dj <= 1; dj++) {

							int ans;

							if (j1 == j2)
								ans = grid[i][j1];
							else
								ans = grid[i][j1] + grid[i][j2];

							if ((j1 + di < 0 || j1 + di >= m) ||
							        (j2 + dj < 0 || j2 + dj >= m))

								ans += -1e9;
							else
								ans += front[j1 + di][j2 + dj];

							maxi = max(ans, maxi);
						}
					}
					curr[j1][j2] = maxi;
				}
			}

			front = curr;
		}

		return front[0][m - 1];

	}

	int cherryPickup(vector<vector<int>>& grid) {

		int n = grid.size();
		int m = grid[0].size();

		return maximumChocolates(n, m, grid);
	}
};