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

// It is similar to best to buy and sell stocks 2 just only the transaction fee is included.

class Solution {
public:

	int recur(vector<int> &prices, int &n, int &fee, int si, int buy, vector<vector<int>> &dp) {
		if (si >= n) {
			return 0;
		}

		if (dp[si][buy] != -1) {
			return dp[si][buy];
		}

		int ans = 0;

		if (buy == 0) { // We can buy the stocks
			ans = max(0 + recur(prices, n, fee, si + 1, buy, dp), -prices[si] + recur(prices, n, fee, si + 1, buy ^ 1, dp));
		}

		if (buy == 1) { // We can sell the stocks
			ans = max(0 + recur(prices, n, fee, si + 1, buy, dp), (prices[si] - fee) + recur(prices, n, fee, si + 1, buy ^ 1, dp));
		}

		return dp[si][buy] = ans;
	}

	int maxProfit(vector<int>& prices, int fee) {

		int n = prices.size();

		vector<vector<int>> dp(n + 1, vector<int>(2, -1));

		return recur(prices, n, fee, 0, 0, dp);

		//*********************Iterative DP Solution**********************************

		vector<vector<int>> dp(n + 1, vector<int>(2, 0));

		for (int i = n - 1; i >= 0; i--) {
			for (int buy = 0; buy <= 1; buy++) {

				int ans = 0;

				if (buy == 0) {
					ans = max(0 + dp[i + 1][0], -prices[i] + dp[i + 1][1]);
				}

				if (buy == 1) {
					ans = max(0 + dp[i + 1][1], (prices[i] - fee) + dp[i + 1][0]);
				}

				dp[i][buy] = ans;
			}
		}

		return dp[0][0];

		//************************************** Space Optimized Iterative DP*************

		vector<int> prev(2, 0);

		for (int i = n - 1; i >= 0; i--) {

			vector<int> curr(2, 0);

			for (int buy = 0; buy <= 1; buy++) {

				int ans = 0;

				if (buy == 0) {
					ans = max(0 + prev[0], -prices[i] + prev[1]);
				}

				if (buy == 1) {
					ans = max(0 + prev[1], (prices[i] - fee) + prev[0]);
				}

				curr[buy] = ans;
			}

			prev = curr;
		}

		return prev[0];
	}
};