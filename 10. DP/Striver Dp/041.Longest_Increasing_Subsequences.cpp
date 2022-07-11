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

	int recur(vector<int>& nums, int i, int prev_i, vector<vector<int>> &dp) {
		if (i >= size(nums)) {
			return 0;
		}

		if (dp[i][prev_i + 1] != -1) {
			return dp[i][prev_i + 1];
		}

		int take = 0, dontTake = recur(nums, i + 1, prev_i, dp);

		if (prev_i == -1 || nums[i] > nums[prev_i]) { // try picking current element if no previous element is chosen or current > nums[prev_i]
			take = 1 + recur(nums, i + 1, i, dp);
		}

		return dp[i][prev_i + 1] = max(take, dontTake);
	}

	int lengthOfLIS(vector<int>& nums) {

		int n = nums.size();

		// vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

		// return recur(nums, 0, -1, dp);

		//***********************************Iterative Dynamic Programming Solution**********************

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

		for (int i = n - 1; i >= 0; i--) {
			for (int j = i - 1; j >= -1; j--) {

				int dontTake = dp[i + 1][j + 1];

				int take = 0;

				if (j == -1 || nums[i] > nums[j]) { // try picking current element if no previous element is chosen or current > nums[prev_i]
					take = 1 + dp[i + 1][i + 1];
				}

				dp[i][j + 1] = max(take, dontTake);
			}
		}

		return dp[0][-1 + 1];

		//******************************** Space Optimized Iteartive DP Solution****************************

		vector<int> prev(n + 1, 0);

		for (int i = n - 1; i >= 0; i--) {

			vector<int> curr(n + 1, 0);

			for (int j = i - 1; j >= -1; j--) {

				int dontTake = prev[j + 1];

				int take = 0;

				if (j == -1 || nums[i] > nums[j]) { // try picking current element if no previous element is chosen or current > nums[prev_i]
					take = 1 + prev[i + 1];
				}

				curr[j + 1] = max(take, dontTake);
			}

			prev = curr;
		}

		return prev[-1 + 1];

	}
};