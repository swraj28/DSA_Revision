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

#define INF INT_MAX


// Why Topological Sort is Working ? (Reason)

// T.c:- O(v+e)


void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[]) {

	vis[node] = 1;

	for (auto it : adj[node]) {
		if (!vis[it.first]) {
			findTopoSort(it.first, vis, st, adj);
		}
	}

	st.push(node);
}


void shortestPath(int src, int N, vector<pair<int, int>> adj[]) {
	int vis[N] = {0};
	stack<int> st;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			findTopoSort(i, vis, st, adj);
		}
	}

	int dist[N];
	for (int i = 0; i < N; i++) {
		dist[i] = 1e9;
	}

	// From Here is same as finding sssp in an undirected graph

	dist[src] = 0;

	while (!st.empty())  {

		int node = st.top();
		st.pop();

		if (dist[node] != INF) {
			for (auto it : adj[node]) {
				if (dist[node] + it.second < dist[it.first]) {
					dist[it.first] = dist[node] + it.second;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
		(dist[i] == 1e9) ? cout << "INF " : cout << dist[i] << " ";
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> adj[n];

	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
	}

	shortestPath(0, n, adj);

	return 0;
}