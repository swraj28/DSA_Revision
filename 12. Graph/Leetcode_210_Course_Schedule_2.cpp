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

	// Cycle Detection in a Directed Graph:-

	bool contain_cycle(int src, map<int, set<int>> &adj, vector<int> &visited1, vector<int> &stack) {
		visited1[src] = 1;
		stack[src] = 1;

		for (auto nbr : adj[src]) {
			if (!visited1[nbr]) {
				bool cycle_mila = contain_cycle(nbr, adj, visited1, stack);
				if (cycle_mila) {
					return true;
				}
			} else if (stack[nbr] == 1) {
				return true;
			}
		}

		stack[src] = 0;

		return false;
	}

	// Topological Sorting Using DFS:-

	void dfs(int src, map<int, set<int>> &adj, vector<int> &visited, list<int> &l) {

		visited[src] = 1;

		for (auto nbr : adj[src]) {
			if (!visited[nbr]) {
				dfs(nbr, adj, visited, l);
			}
		}

		l.push_front(src);
	}

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

		int n = numCourses;

		// vector<int>adj[n];

		map<int, set<int>> adj;

		vector<int> res;

		int m = prerequisites.size();

		for (int i = 0; i < m; i++) {

			int x = prerequisites[i][0];
			int y = prerequisites[i][1];

			//to complete the course x we need to complete the course y.
			adj[x].insert(y);

			if ((adj.count(y)) and (adj[y].find(x) != adj[y].end())) {
				return res;
			}
		}

		vector<int> visited1(n, 0);
		vector<int> stack(n, 0);

		for (int i = 0; i < n; i++) {
			if (!visited1[i]) {
				if (contain_cycle(i, adj, visited1, stack)) {
					return res;
				}
			}
		}

		vector<int> visited(n, 0);

		list<int> l;

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfs(i, adj, visited, l);
			}
		}
		reverse(all(l));

		for (auto ele : l) {
			res.pb(ele);
		}

		return res;
	}
};