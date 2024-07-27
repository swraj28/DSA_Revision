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

	bool isBipartite(vector<int> graph[], vector<int> &visited, int n) {

		//There can be multiple compnent in the graph

		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0) {
				if (is_Bipartite(graph, i, visited, -1, 1) == false) {
					return false;
				}
			}
		}
		return true;
	}
	//Dfs:-
	bool is_Bipartite(vector<int> graph[], int src, vector<int> &visited, int parent, int color) {

		visited[src] = color;

		for (auto nbr : graph[src]) {
			if (visited[nbr] == 0) {
				bool rec_result = is_Bipartite(graph, nbr, visited, src, 3 - color);
				if (rec_result == false) {
					return false;
				}
			} else if (nbr != parent and color == visited[nbr]) {
				return false;
			}
		}

		return true;
	}
	bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

		vector<int> gr[n + 1];

		for (int i = 0; i < dislikes.size(); i++) {
			int u = dislikes[i][0];
			int v = dislikes[i][1];

			gr[u].pb(v);
			gr[v].pb(u);
		}

		vector<int> visited(n + 1, 0);

		return isBipartite(gr, visited, n);
	}
};