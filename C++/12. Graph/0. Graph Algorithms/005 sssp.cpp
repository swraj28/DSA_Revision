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


//Single Source Shortest Path in an unweighted Graph and undirected graph.
//t.c-o(v+e)
class Graph {

	map<int, list<int>> adj;
public:

	void add_edges(int src, int dest, bool bidir = true) {
		adj[src].push_back(dest);
		if (bidir) {
			adj[dest].push_back(src);
		}
	}

	void print() {

		//Iterate over the map
		for (auto i : adj) {
			cout << i.first << "->";

			//i.second is LL
			for (auto entry : i.second) {
				cout << entry << ",";
			}
			cout << endl;
		}
	}

	void bfs_sssp(int src, int dest) {

		queue<int> q;
		map<int, bool>visited;
		int n = adj.size();
		vector<int> d(n);//it stores the distance of a node from src node
		vector<int> p(n);//it stores for each vertex the vertex from which we reached it(i.e,the parent)

		//Mark all the node visited as false

		for (auto i : adj) {
			int node = i.first;
			visited[node] = false;
		}

		q.push(src);
		visited[src] = true;
		p[src] = -1; //there will be no parent of src
		d[src] = 0; //distace from src to src is zero

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto i : adj[x]) {
				if (!visited[i]) {
					visited[i] = true;
					q.push(i);
					d[i] = d[x] + 1; //distace from x;
					p[i] = x; //Parent of i  will be x itself
				}
			}
		}


		if (visited[dest] == false) {  //if we are unable to reach the destination
			cout << "No path found" << endl;
		} else {

			cout << "distace of each node from src node" << endl;
			for (auto i : d) {
				cout << i << " ";
			}
			cout << endl;

			cout << "The predecessor(i.e.,parent) of each node" << endl;
			for (auto i : p) {
				cout << i << " ";
			}
			cout << endl;

			//minimum distace

			cout << "The minimum distace is" << endl;
			cout << d[dest] << endl;

			vector<int> path;
			int x = dest;
			path.push_back(dest);

			while (p[x] != -1) {
				path.push_back(p[x]);
				x = p[x];
			}

			reverse(path.begin(), path.end());

			cout << "The shortest path is" << endl;
			for (auto i : path) {
				cout << i << "->";
			}
			cout << endl;
		}
	}
};

int main() {

	Graph g;

	// g.add_edges(0, 1);
	// g.add_edges(0, 2);
	// g.add_edges(1, 2);
	// g.add_edges(1, 3);
	// g.add_edges(2, 3);
	// g.add_edges(2, 4);
	// g.add_edges(2, 5);
	// g.add_edges(3, 4);
	// g.add_edges(3, 5);
	// g.add_edges(4, 5);
	// g.add_edges(4, 6);
	// g.add_edges(5, 6);

	// g.add_edges(0, 1);
	// g.add_edges(1, 2);
	// g.add_edges(0, 4);
	// g.add_edges(2, 4);
	// g.add_edges(2, 3);
	// g.add_edges(3, 5);
	// g.add_edges(3, 4);

	g.add_edges(0, 1);
	g.add_edges(1, 2);
	g.add_edges(2, 3);
	g.add_edges(3, 4);
	g.add_edges(0, 3);
	g.add_edges(4, 5);

	cout << "The Required Graph representation is" << endl;
	g.print();
	g.bfs_sssp(0, 5);


	return 0;
}