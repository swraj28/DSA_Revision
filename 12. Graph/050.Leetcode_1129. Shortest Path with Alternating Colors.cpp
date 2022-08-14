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

	pair<bool, int> bfs(int n, int src, int dest, int cur, vector<int> red[], vector<int> blue[]) {

		queue<int> q;
		q.push(src);

		vector<int> visited_red(n, 0);
		vector<int> visited_blue(n, 0);

		int dist = 0;

		visited_blue[0] = 1;
		visited_red[0] = 1;

		while (!q.empty()) {

			int sze = q.size();

			while (sze--) {

				auto node = q.front();
				q.pop();

				if (node == dest) {
					return {true, dist};
				}

				if (cur == 0) {
					for (auto &nbr : red[node]) {
						if (!visited_red[nbr]) {
							visited_red[nbr] = 1;
							q.push(nbr);
						}
					}
				} else {
					for (auto &nbr : blue[node]) {
						if (!visited_blue[nbr]) {
							visited_blue[nbr] = 1;
							q.push(nbr);
						}
					}
				}
			}

			dist++;
			cur ^= 1;
		}

		return {false, INT_MAX};
	}

	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

		vector<int> red[n];
		vector<int> blue[n];

		for (auto &e : redEdges) {
			if (e[0] == e[1])continue;
			red[e[0]].pb(e[1]);
		}

		for (auto &e : blueEdges) {
			if (e[0] == e[1])continue;
			blue[e[0]].pb(e[1]);
		}

		vector<int> ans(n);


		for (int i = 1; i < n; i++) {

			int src = 0, dest = i;

			// curr=0--> red edge required
			// curr=1--> blue edge required

			pair<bool, int> p1 = bfs(n, src, dest, 0, red, blue);
			pair<bool, int> p2 = bfs(n, src, dest, 1, red, blue);

			if (p1.ff || p2.ff) {
				ans[i] = min(p1.ss, p2.ss);
			} else {
				ans[i] = -1;
			}
		}

		return ans;
	}
};