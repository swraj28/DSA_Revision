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

	int mcm(vector<int>& cuts, int st, int end, vector<vector<int>> &dp) {
		if (end - st <= 1) {
			return 0;
		}

		if (dp[st][end] != -1) {
			return dp[st][end];
		}

		int mn = INT_MAX;

		for (int i = st + 1; i < end; i++) {

			int rec_res = mcm(cuts, st, i, dp) + mcm(cuts, i, end, dp) + (cuts[end] - cuts[st]);

			mn = min(mn, rec_res);
		}

		return dp[st][end] = mn;
	}

	int minCost(int sze, vector<int>& cuts) {

		cuts.pb(0);
		cuts.pb(sze);

		sort(all(cuts));

		int n = cuts.size();

		// vector<vector<int>> dp(n, vector<int>(n, -1));

		// return mcm(cuts, 0, n - 1, dp);

		//************************Iterative DP Solution***********************************

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

		for (int st = n - 1; st >= 0; st--) {
			for (int end = st + 1; end < n; end++) {

				int mn = (1e8);

				for (int k = st + 1; k < end; k++) {

					int rec_res = dp[st][k] + dp[k][end] + (cuts[end] - cuts[st]);

					mn = min(mn, rec_res);
				}

				if (mn < 1e8) {
					dp[st][end] = mn;
				}
			}
		}

		return dp[0][n - 1];
	}
};