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

	int recur(vector<int> &prices, int n, int si, int k, vector<vector<int>> &dp) {
		if (si >= n || k == 0) {
			return 0;
		}

		if (dp[si][k] != -1) {
			return dp[si][k];
		}

		int &ans = dp[si][k];

		int ans1 = recur(prices, n, si + 1, k, dp);

		int ans2 = 0;

		bool buy = (k % 2 == 0);

		if (buy == true) {
			ans2 += (- prices[si]) + recur(prices, n, si + 1, k - 1, dp);
		} else {
			ans2 += (prices[si]) + recur(prices, n, si + 1, k - 1, dp);
		}

		return ans = max(ans1, ans2);
	}

	int maxProfit(vector<int>& prices) {

		int n = prices.size();
		int k = 4;

		vector<vector<int>> dp(n + 1, vector<int>(5, -1));

		return recur(prices, n, 0, k, dp);

		//**************************Iterative DP Solution ************************

		vector<vector<int>> dp(n + 1, vector<int>(5, 0));

		for (int day = (int) prices.size() - 1; day >= 0; day--) {

			for (int transactionsLeft = 1; transactionsLeft <= 4; transactionsLeft++) {

				int &ans = dp[day][transactionsLeft];

				// choice 1
				// no transaction today
				int ans1 = dp[day + 1][transactionsLeft];

				// choice 2
				// doing the possible transaction today
				int ans2 = 0;
				bool buy = (transactionsLeft % 2 == 0);

				if (buy == true) { // buy
					ans2 = -prices[day] + dp[day + 1][transactionsLeft - 1];
				} else { // sell
					ans2 = prices[day] + dp[day + 1][transactionsLeft - 1];
				}

				ans = max(ans1, ans2);

			}
		}
		return dp[0][4];

		//*************************************** Space Optimized Iteartive DP********************

		vector<int> prev(5, 0);

		for (int day = (int) prices.size() - 1; day >= 0; day--) {

			vector<int> curr(5, 0);

			for (int transactionsLeft = 1; transactionsLeft <= 4; transactionsLeft++) {

				int &ans = curr[transactionsLeft];

				// choice 1
				// no transaction today
				int ans1 = prev[transactionsLeft];

				// choice 2
				// doing the possible transaction today
				int ans2 = 0;
				bool buy = (transactionsLeft % 2 == 0);

				if (buy == true) { // buy
					ans2 = -prices[day] + prev[transactionsLeft - 1];
				} else { // sell
					ans2 = prices[day] + prev[transactionsLeft - 1];
				}

				ans = max(ans1, ans2);
			}

			prev = curr;
		}
		return prev[4];
	}
};