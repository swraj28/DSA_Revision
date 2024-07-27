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

	int recur(vector<int> &coins, int n, int si, int amount, vector<vector<int>> &dp) {
		if (amount == 0) {
			return 0;
		}

		if (si >= n) {
			return (1e8);
		}

		if (dp[si][amount] != -1) {
			return dp[si][amount];
		}

		int not_taken = recur(coins, n, si + 1, amount, dp);

		int taken = (1e8);
		if (amount >= coins[si]) {
			taken = 1 + recur(coins, n, si, amount - coins[si], dp);
		}

		return dp[si][amount] = min(taken, not_taken);
	}

	int coinChange(vector<int>& coins, int amount) {

		int n = coins.size();

		vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

		int ans = recur(coins, n, 0, amount, dp);

		return (ans >= (1e8)) ? -1 : ans;

		//*****************************Iterative DP*************************************

		vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

		for (int i = 1; i <= amount; i++) {
			dp[0][i] = (1e8);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= amount; j++) {

				int not_taken = dp[i - 1][j];

				int taken = (1e8);

				if (j >= coins[i - 1]) {
					taken = 1 + dp[i][j - coins[i - 1]];
				}

				dp[i][j] = min(taken, not_taken);
			}
		}

		return dp[n][amount] >= 1e8 ? -1 : dp[n][amount];

		//********************************* Space Optimized Iterative dp***************************

		vector<int> prev(amount + 1, (1e8));
		prev[0] = 0;

		for (int i = 1; i <= n; i++) {

			vector<int> curr(amount + 1, 0);

			for (int j = 1; j <= amount; j++) {

				int not_taken = prev[j];

				int taken = (1e8);

				if (j >= coins[i - 1]) {
					taken = 1 + curr[j - coins[i - 1]];
				}

				curr[j] = min(taken, not_taken);
			}

			prev = curr;
		}

		return prev[amount] >= 1e8 ? -1 : prev[amount];
	}
};