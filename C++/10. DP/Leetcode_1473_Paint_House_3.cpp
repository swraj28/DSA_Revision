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

	int recur(vector<int> &houses, vector<vector<int>> &cost, int n, int m, int si, int target, int last_color, vector<vector<vector<int>>> &dp) {
		if (si >= m) {
			return target == 0 ? target : (1e7);
		}

		if (target < 0) {
			return (1e7);
		}

		if (dp[si][target][last_color] != -1) {
			return dp[si][target][last_color];
		}

		if (houses[si] != 0) {
			return recur(houses, cost, n, m, si + 1, target - (last_color != houses[si]), houses[si], dp);
		}

		int mn = (1e7);

		for (int clr = 1; clr <= n; clr++) {

			int rec_res = cost[si][clr - 1] + recur(houses, cost, n, m, si + 1, target - (last_color != clr), clr, dp);

			mn = min(mn, rec_res);
		}

		return dp[si][target][last_color] = mn;
	}

	int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

		vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(target + 1, vector<int>(n + 1, -1)));

		int ans = recur(houses, cost, n, m, 0, target, 0, dp);

		return (ans >= (1e7)) ? -1 : ans;

		//*****************************Iterative DP******************************************

		vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(target + 1, vector<int>(n + 1, 0)));

		// Base Case
	}
};