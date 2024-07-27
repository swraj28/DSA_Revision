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


template<typename T>

class Graph {

	map<T, list<T>> adjList;

public:

	// Default Constructor
	Graph() {

	}

	void addEdge(T u, T v, bool bidir = true) {

		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	void print() {
		//Iterate over the map
		for (auto i : adjList) {
			cout << i.first << "->";

			//i.second is LL
			for (T entry : i.second) {
				cout << entry << ",";
			}
			cout << endl;
		}
	}

	//Dfs Recursive:-(Implict Stack)

	void dfsHelper(T node, map<T, bool> &visited) {
		//Whenever to come to a node, mark it visited
		visited[node] = true;
		cout << node << " ";

		//Try to find out a node which is neigbour of current node and not yet visited
		for (T neighbour : adjList[node]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited);
			}
		}
	}

	void dfs(T src) {
		map<T, bool> visited;
		//Mark all the nodes as not visited in the beginning
		for (auto p : adjList) {
			T node = p.first;
			visited[node] = false;
		}
		dfsHelper(src, visited);  // Assuming the graph has only one connected component.
	}

	// Iterative Depth First Search:- (It is similar to BFS if we replace queue with a stack)

	void iterative_dfs(T src) {

		map<T, bool> visited;
		//Mark all the nodes as not visited in the beginning
		for (auto p : adjList) {
			T node = p.first;
			visited[node] = false;
		}

		stack<T> s;
		s.push(src);
		visited[src] = true;

		while (!s.empty()) {
			T node = s.top();
			s.pop();

			cout << node << " ";

			for (auto nbr : adjList[node]) {
				if (!visited[nbr]) {
					s.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}
};

int main() {

	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	cout << "The required Graph is " << endl;
	g.print();
	cout << "Dfs Recursive Implementaion" << endl;
	g.dfs(0);
	cout << endl;

	cout << "Dfs Iterative Implementaion" << endl;
	g.iterative_dfs(0);
	cout << endl;


	return 0;
}