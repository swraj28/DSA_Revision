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

// 1. DFS:-

class Solution {
public:

	void dfs(int src, vector<int> gr[], vector<int> &visited) {
		visited[src] = 1;

		for (auto nbr : gr[src]) {
			if (!visited[nbr]) {
				dfs(nbr, gr, visited);
			}
		}
	}

	int findCircleNum(vector<vector<int>>& isConnected) {

		int n = isConnected.size();

		vector<int> gr[n + 1];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				if (isConnected[i][j] == 1) {
					gr[i + 1].pb(j + 1);
				}
			}
		}

		int cnt = 0;

		vector<int> visited(n + 1, 0);

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i, gr, visited);
				cnt++;
			}
		}

		return cnt;
	}
};

// 2. DSU:-

class Solution {
public:
	int find_parent(int v, vector<int> &parent) {
		if (v == parent[v]) {
			return v;
		}

		return parent[v] = find_parent(parent[v], parent);
	}

	int findCircleNum(vector<vector<int>>& isConnected) {

		int n = isConnected.size();

		int total_comp = n;

		vector<int> parent(n);
		vector<int> sze(n);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < n; i++) {
			sze[i] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}

				if (isConnected[i][j] == 0) {
					continue;
				}

				int p_i = find_parent(i, parent);
				int p_j = find_parent(j, parent);

				if (p_i != p_j) {
					total_comp -= 1;
					if (sze[p_i] >= sze[p_j]) {
						parent[p_j] = p_i;
						sze[p_i] += sze[p_j];
					} else {
						parent[p_i] = p_j;
						sze[p_j] += sze[p_i];
					}
				}
			}
		}

		return total_comp;
	}
};