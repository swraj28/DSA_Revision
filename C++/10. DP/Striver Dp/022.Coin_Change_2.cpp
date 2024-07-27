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
	int recur(vector<int>& coins, int si, int amount, vector<vector<int>>&dp) {
		if (amount == 0)return 1;

		if (si >= coins.size())return 0;

		if (dp[si][amount] != -1)return dp[si][amount];

		int not_taken = recur(coins, si + 1, amount, dp);

		int taken = 0;
		if (amount >= coins[si]) {
			taken += recur(coins, si, amount - coins[si], dp);
		}

		return dp[si][amount] = (taken + not_taken);
	}

	int change(int amount, vector<int>& coins) {

		int n = coins.size();

		vector<vector<int>>dp(n + 1, vector<int>(amount + 1, -1));

		return recur(coins, 0, amount, dp);

		//******************************* Iterative DP*************************************

		vector<vector<int>>dp(n + 1, vector<int>(amount + 1, 0));

		for (int i = 0; i <= n; i++) {
			dp[i][0] = 1;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= amount; j++) {

				int not_taken = dp[i - 1][j];

				int taken = 0;

				if (j >= coins[i - 1]) {
					taken = dp[i][j - coins[i - 1]];
				}

				dp[i][j] = (taken + not_taken);
			}
		}

		return dp[n][amount];

		//************************************Space Optimized Iterative DP*********************

		vector<int> prev(amount + 1, 0);
		prev[0] = 1;

		for (int i = 1; i <= n; i++) {

			vector<int> curr(amount + 1, 0);
			curr[0] = 1;

			for (int j = 1; j <= amount; j++) {

				int not_taken = prev[j];

				int taken = 0;

				if (j >= coins[i - 1]) {
					taken = curr[j - coins[i - 1]];
				}

				curr[j] = (taken + not_taken);
			}

			prev = curr;
		}

		return prev[amount];
	}
};