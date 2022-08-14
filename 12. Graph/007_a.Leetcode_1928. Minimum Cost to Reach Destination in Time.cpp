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

	int recur(int src, int maxTime, vector<pair<int, int>> gr[], vector<int> &passingFees, vector<vector<int>> &dp) {

		if (maxTime < 0 ) {
			return (1e8);
		}

		if (src == passingFees.size() - 1) {
			return passingFees[src];
		}

		if (dp[src][maxTime] != -1) {
			return dp[src][maxTime];
		}

		int mn = (1e8);

		for (auto &nbr : gr[src]) {

			int rec_res = passingFees[src] + recur(nbr.ff, maxTime - nbr.ss, gr, passingFees, dp);

			mn = min(mn, rec_res);
		}

		if (mn >= (1e8)) {
			return dp[src][maxTime] = (1e8);
		}

		return dp[src][maxTime] = mn;
	}

	int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {

		int n = passingFees.size();

		vector<pair<int, int>> gr[n];

		for (auto &e : edges) {
			int u = e[0], v = e[1], wt = e[2];

			gr[u].pb({v, wt});
			gr[v].pb({u, wt});
		}

		// Here the maxTime is less therefore instead of creating visiting node we will track using the maxTime.

		vector<vector<int>> dp(n + 1, vector<int>(maxTime + 1, -1));

		int ans = recur(0, maxTime, gr, passingFees, dp);

		return (ans >= (1e8)) ? -1 : ans;
	}
};