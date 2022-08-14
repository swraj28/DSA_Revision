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

	bool ans;

	int visit[501][501], dis[501][501], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

	void dfs(int x, int y, int n, int m, int len, int pre, char ch, vector<vector<char>>&grid) {

		if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != ch) {
			return;
		}

		if (visit[x][y]) {
			if (abs(dis[x][y] - pre) >= 3) {
				ans = true;
			}

			return;
		}

		visit[x][y] = 1;
		dis[x][y] = len;
		for (int i = 0; i < 4; i++) {
			dfs(x + dx[i], y + dy[i], n, m, len + 1, dis[x][y], ch, grid);
		}

		// We don't need to Backtrack. Make a Dry run on any example everything will be clear.

		// Reason:- from a particular cell we are only moving to a cell whose value is same as that of the current cell .
	}

	bool containsCycle(vector<vector<char>>& grid) {

		int n = grid.size(), m = grid[0].size();

		memset(visit, 0, sizeof(visit));
		memset(dis, 0, sizeof(dis));

		ans = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (!visit[i][j]) {
					dfs(i, j, n, m, 1, 1, grid[i][j], grid);
				}
			}
		}
		return ans;
	}
};