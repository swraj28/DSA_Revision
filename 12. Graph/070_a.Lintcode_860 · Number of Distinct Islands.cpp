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

	vector<int> dx = { -1, 1, 0, 0}, dy = {0, 0, -1, 1};

	void recur(int x, int y, int n, int m, int x0, int y0, vector<vector<int>> &grid, vector<pair<int, int>> &v) {

		if (x < 0 || x >= n || y < 0 || y >= m) {
			return ;
		}

		if (grid[x][y] == 0 || grid[x][y] == -1) {
			return;
		}

		grid[x][y] *= -1;

		v.pb({x - x0, y - y0});

		for (int i = 0; i < 4; i++) {
			recur(x + dx[i], y + dy[i], n, m, x0, y0, grid, v);
		}
	}

	int numberofDistinctIslands(vector<vector<int>> &grid) {

		int n = grid.size(), m = grid[0].size();

		set <vector<pair<int, int>>> s;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (grid[i][j] == 1) {

					vector<pair<int, int>> v;

					recur(i, j, n, m, i, j, grid, v);

					s.insert(v);
				}
			}
		}

		return (int)s.size();
	}
};