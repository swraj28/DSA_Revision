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
	vector<vector<int>> ans;

	void dfs(int src, int dest, vector<vector<int>> &graph, vector<int> &path) {

		// Here we don't need to maintain a visited array as the graph is (DAG)

		path.push_back(src);

		if (src == dest) {
			ans.push_back(path);
			return;
		}

		for (auto nbr : graph[src]) {
			dfs(nbr, dest, graph, path);

			// After Every return statement control will reach here
			path.pop_back();
		}
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

		vector<int> path;

		int n = graph.size();

		int src = 0, dest = (n - 1);

		dfs(src, dest, graph, path);

		return ans;
	}
};