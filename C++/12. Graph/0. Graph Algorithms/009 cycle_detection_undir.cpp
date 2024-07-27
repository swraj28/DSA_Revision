#include    <iostream>
#include    <string>
#include    <algorithm>
#include    <map>
#include    <unordered_map>
#include    <vector>
#include    <set>
#include    <list>
#include    <iomanip>
#include    <queue>
#include    <stack>
#include    <math.h>
#include    <climits>
#include    <bitset>
#include    <cstring>
#include    <numeric>
#include    <array>
#include    <deque>
#include    <cstdlib>
#include    <cstdio>
#include    <stdlib.h>
#include    <cerrno>
#include    <ctime>
#include    <unordered_set>
#include    <cstring>
#include    <cmath>
#include    <random>
#include    <functional>
#include    <cassert>
#include    <bitset>
#include    <chrono>
 
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define PI 3.1415926535897932384626
#define mod 1000000007
#define mod1 998244353
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()


class Graph {

	map<int, vector<int>> adj;
public:
	// Default Constructor
	Graph() {

	}

	void add_edges(int src, int dest, bool bidir = true) {
		adj[src].push_back(dest);
		if (bidir) {
			adj[dest].push_back(src);
		}
	}

	//Dfs:-

	bool cycle_helper(int node, bool*visited, int parent) {

		visited[node] = true;

		for (auto nbr : adj[node]) {
			//two cases
			if (!visited[nbr]) {

				//go and recursively visit the nbr
				//the nbr may lead to a node which may form a cycle.

				bool cycle_mila = cycle_helper(nbr, visited, node);
				if (cycle_mila) {
					return true;
				}
			} else if (nbr != parent) {//nbr is visted but nbr should not be the parent
				return true;
			}
		}

		return false;
	}

	bool contains_cycle() {
		int n = adj.size();
		bool*visited = new bool[n];
		//Mark all the visited node as false
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}

		//Assuming that we have only one component
		//we can do it for multiple components.
		return cycle_helper(0, visited, -1);
	}
	

	//Bfs:-
	bool is_cycle(int src, map<int, bool> &visited, map<int, int> &parent) {

		queue<int> q;

		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (auto nbr : adj[node]) {
				if (visited.count(nbr) and nbr != parent[node]) {
					return true;
				} else if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr] = node;

				}
			}
		}

		return false;
	}

	bool bfs_cycle_helper() {

		int n = adj.size();

		map<int, bool> visited;
		map<int, int> parent;

		for (int i = 0; i < n; i++) {
			visited[i] = false;
			parent[i] = -1;
		}

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				if (is_cycle(i, visited, parent)) {
					return true;
				}
			}
		}

		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Graph g;
	g.add_edges(0, 1);
	g.add_edges(1, 2);
	g.add_edges(2, 3);
	g.add_edges(3, 4);
	g.add_edges(4, 0);
	g.add_edges(0, 3);

	// g.add_edges(0, 1);
	// g.add_edges(0, 3);
	// g.add_edges(0, 2);
	// g.add_edges(1, 2);
	// g.add_edges(2, 3);


	if (g.contains_cycle()) {
		cout << "Cycle_Present" << endl;
	} else {
		cout << "Cycle_not_Present" << endl;
	}


	return 0;
}