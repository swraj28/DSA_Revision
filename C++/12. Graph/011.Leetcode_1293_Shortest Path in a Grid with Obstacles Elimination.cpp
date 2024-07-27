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

// DFS --> Exploring All the Path and trying to find the minimum Path (TLE)

class Solution {
public:

	int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

	int dp[41][41][1700];

	int dfs(int x, int y, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& visited, int k) {

		if ((x == n - 1) && (y == m - 1)) {
			return 0;
		}

		if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] == 1) {
			return (1e6);
		}

		if (grid[x][y] == 1 && k == 0) {
			return (1e6);
		}

		if (dp[x][y][k] != -1) {
			return dp[x][y][k];
		}

		if (grid[x][y] == 1) {
			k -= 1;
		}

		visited[x][y] = 1;

		int ans = INT_MAX;

		for (int i = 0; i < 4; i++) {

			int rec_res = 1 + dfs(x + dx[i], y + dy[i], n, m, grid, visited, k);

			ans = min(ans, rec_res);
		}



		/*
		I used dfs so even after visiting one there may be smallest way reach there so
		you have to unvisited that position after your work is done
		so that if we came here again from another way we should take this path to see if ot gives the minimum distance
		*/

		visited[x][y] = 0;

		return (dp[x][y][k] == -1) ? ans : min(ans, dp[x][y][k]);

		// return dp[x][y][k]=ans;
	}

	int shortestPath(vector<vector<int>>& grid, int k) {

		int n = grid.size(), m = grid[0].size();

		vector<vector<int>> visited(n, vector<int>(m, 0));

		ms(dp, -1);

		int ans = dfs(0, 0, n, m, grid, visited, k);

		return (ans >= (1e6)) ? -1 : ans;
	}
};

// BFS:-

class Solution {
public:
	int solve(vector<vector<int>>& grid, int k) {

		// At a particular cell we will store the number of obstacles that we can still remove after walking through that cell
		vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));

		queue<vector<int>> q;

		// queue stores (x,y,current path length,number of obstacles we can still remove)
		q.push({0, 0, 0, k});

		while (!q.empty()) {

			auto t = q.front();

			int x = t[0], y = t[1];

			q.pop();

			// Exit if current position is outside of the grid
			if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
				continue;
			}

			// Destination found
			if (x == grid.size() - 1 && y == grid[0].size() - 1) {
				return t[2];
			}

			if (grid[x][y] == 1) {
				if (t[3] > 0) {// If we encounter an obstacle and we can remove it
					t[3]--;
				} else {
					continue;
				}
			}

			/*
			   vis[x][y] tells how many more obstacles we can remove if we continue on the current path.
			   So if vis[x][y]>="current obstacle removing capacity" then it means that the cell [x][y] was previously visited by some path
			   whose removing capacity was greater after passing through this cell.
			   So we don't need to continue on this path since it has already been visited by some other more optimal path.
			*/

			if (vis[x][y] != -1 && vis[x][y] >= t[3]) {  // Euqual to ??
				continue;
			}

			vis[x][y] = t[3];

			q.push({x + 1, y, t[2] + 1, t[3]});
			q.push({x, y + 1, t[2] + 1, t[3]});
			q.push({x - 1, y, t[2] + 1, t[3]});
			q.push({x, y - 1, t[2] + 1, t[3]});

		}
		return -1;
	}

	int shortestPath(vector<vector<int>>& grid, int k) {
		return solve(grid, k);
	}
};