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

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
	for (int k = 0; k < n; k++) {
		if (k != node && graph[node][k] == 1 && color[k] == col) {
			return false;
		}
	}
	return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
	if (node == N) {
		return true;
	}

	for (int i = 1; i <= m; i++) {
		if (isSafe(node, color, graph, N, i)) {
			color[node] = i;
			if (solve(node + 1, color, m, N, graph)) return true;
			color[node] = 0;
		}

	}

	return false;
}

bool graphColoring(bool graph[101][101], int m, int N) {
	int color[N] = {0};
	if (solve(0, color, m, N, graph)) return true;
	return false;
}