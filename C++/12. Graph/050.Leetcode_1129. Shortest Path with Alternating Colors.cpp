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

	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

		// 0--> Red Edge
		// 1--> Blue Edge.

		vector<pair<int, int>> gr[n];

		for (auto &e : redEdges) {
			gr[e[0]].pb({e[1], 0});
		}

		for (auto &e : blueEdges) {
			gr[e[0]].pb({e[1], 1});
		}

		vector<vector<int>> dist(n, vector<int>(2, -1));

		dist[0][0] = 0, dist[0][1] = 0;

		queue<pair<int, int>> q;

		q.push({0, 0}); // we arrived at 0 from some imaginary node using red edge .
		q.push({0, 1}); // we arrived at 0 from some imaginary node using blue edge.

		while (!q.empty()) {

			auto node = q.front();
			q.pop();

			for (auto &nbr : gr[node.ff]) {

				if (dist[nbr.ff][nbr.ss] != -1 || nbr.ss == node.ss) {
					// either visited or same color
					continue;
				}

				dist[nbr.ff][nbr.ss] = 1 + dist[node.ff][node.ss];
				q.push({nbr.ff, nbr.ss}); // Basically in the queue we are storing that at the paritcular node what color edge did we take to arrive from the previou node .
			}
		}

		vector<int> ans(n, 0);

		for (int i = 1; i < n; i++) {
			sort(all(dist[i]));

			ans[i] = (dist[i][0] == -1) ? dist[i][1] : dist[i][0];
		}

		return ans;
	}
};