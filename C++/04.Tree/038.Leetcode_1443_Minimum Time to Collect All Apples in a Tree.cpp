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

	int dfs(int src, int par, vector<int> gr[], vector<bool> &hasApple) {

		int children_cost = 0;

		for (auto &nbr : gr[src]) {
			if (nbr != par) {
				children_cost += dfs(nbr, src, gr, hasApple);
			}
		}

		if (children_cost == 0 && hasApple[src] == 0) {
			return 0;
		}

		return (src == 0) ? children_cost : (children_cost + 2);
	}

	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

		vector<int> gr[n];

		for (auto &edge : edges) {
			gr[edge[0]].pb(edge[1]);
			gr[edge[1]].pb(edge[0]);
		}

		return dfs(0, -1, gr, hasApple);
	}
};