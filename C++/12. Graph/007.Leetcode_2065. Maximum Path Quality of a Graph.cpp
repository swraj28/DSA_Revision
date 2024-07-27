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

	void dfs(int src, vector<pair<int, int>> gr[], vector<int> &visited, vector<int> &values, int time, int &maxTime, int val, int &ans) {

		if (time > maxTime) {
			return;
		}

		if (visited[src] == 0) {
			val += values[src];
		}

		if (src == 0) {
			ans = max(ans, val);
		}

		visited[src]++;

		for (auto &nbr : gr[src]) {

			dfs(nbr.ff, gr, visited, values, time + nbr.ss, maxTime, val, ans);
		}

		visited[src]--; // Backtracking
	}

	int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {

		int n = values.size();
		vector<pair<int, int>> gr[n];

		for (auto &e : edges) {
			int u = e[0], v = e[1], wt = e[2];

			gr[u].pb({v, wt});
			gr[v].pb({u, wt});
		}

		vector<int> visited(n, 0);

		int ans = 0;

		dfs(0, gr, visited, values, 0, maxTime, 0, ans);

		return ans;
	}
};