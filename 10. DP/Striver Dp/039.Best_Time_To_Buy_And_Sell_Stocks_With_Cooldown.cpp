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

	int recur(vector<int> &prices, int n, int si, vector<vector<int>> &dp, bool buy = false) { // This Function will return the maximum profit gained
		if (si >= n) {
			return 0;
		}

		if (dp[si][buy] != -1) {
			return dp[si][buy];
		}

		if (buy == false) {
			return dp[si][buy] = max({recur(prices, n, si + 1, dp, true) - prices[si], recur(prices, n, si + 1,  dp, buy)});
		}

		return dp[si][buy] = max({prices[si] + recur(prices, n, si + 2, dp, false), recur(prices, n, si + 1, dp, buy)});
	}

	int maxProfit(vector<int>& prices) {

		int n = prices.size();

		if (n == 1) {
			return 0;
		}

		// vector<vector<int>>dp(n + 1, vector<int>(2, -1));

		// return recur(prices, n, 0, dp);

		//************************Iterative DP Solution***************************************

		vector<vector<int>>dp(n + 2, vector<int>(2, 0));

		for (int i = n - 1; i >= 0; i--) {
			for (int buy = 0; buy <= 1; buy++) {

				if (buy == 0) {
					dp[i][0] = max(dp[i + 1][1] - prices[i], dp[i + 1][0]);
				}

				if (buy == 1) {
					dp[i][1] = max(prices[i] + dp[i + 2][0], dp[i + 1][1]);
				}
			}
		}

		return dp[0][0];

		//***********************Space Optimized Iterative DP*********************************

		vector<int> prev1(2, 0);
		vector<int> prev2(2, 0);

		for (int i = n - 1; i >= 0; i--) {

			vector<int> curr(2, 0);

			for (int buy = 0; buy <= 1; buy++) {

				if (buy == 0) {
					curr[0] = max(prev1[1] - prices[i], prev1[0]);
				}

				if (buy == 1) {
					curr[1] = max(prices[i] + prev2[0], prev1[1]);
				}
			}

			prev2 = prev1;
			prev1 = curr;
		}

		return prev1[0];
	}
};