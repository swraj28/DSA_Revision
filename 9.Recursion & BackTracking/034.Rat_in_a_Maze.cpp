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

/*
   Time and Space Complexity Analysis:-

   On an average if i have to say for every cell we have 4 possiblities (Approximation). And total number of cell (n*n)

   T.c:- O(4^(n^2))
   s.c:- O(4*n) --> Auxiliary Space --> Recursive Call Stack. (Top-->bottom->top->bottom)
*/

class Solution {
public:

	vector<string> ans;
	int dx[4] = { 1, 0, 0, -1};
	int dy[4] = {0, -1, 1, 0};

	string dir = "DLRU"; // The directions are assigned for iterating on a matrix

	void recur(vector<vector<int>> &matrix, int n, int x, int y, vector<vector<int>> &visited, string &s) {
		if (x == n - 1 && y == n - 1) {
			ans.push_back(s);
			return;
		}

		for (int i = 0; i < 4; i++) {

			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) {
				continue;
			}

			if (visited[new_x][new_y] == 1 || matrix[new_x][new_y] == 0) {
				continue;
			}

			visited[x][y] = 1;
			s += dir[i];

			recur(matrix, n, new_x, new_y, visited, s);

			// Backtracking:-

			visited[x][y] = 0;
			s.pop_back();
		}

	}

	vector<string> findPath(vector<vector<int>> &m, int n) {

		vector<vector<int>> visited(n, vector<int>(n, 0));

		string s = "";

		if (m[0][0] == 1) {
			recur(m, n, 0, 0, visited, s);
		}

		if ((int)ans.size() == 0) {
			return { "-1"};
		}

		return ans;
	}
};