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

	// same Question dp 18.

	int recur(vector<int> &nums, int n, int si, int target, vector<vector<int>> &dp) {
		if (si >= n) {
			return (target == 0);
		}

		if (dp[si][target] != -1) {
			return dp[si][target];
		}

		int not_taken = recur(nums, n, si + 1, target, dp);

		int taken = 0;

		if (target >= nums[si]) {
			taken = recur(nums, n, si + 1, target - nums[si], dp);
		}

		return dp[si][target] = (taken + not_taken) % mod;;
	}

	int findTargetSumWays(vector<int>& nums, int d) {

		int n = nums.size();

		int sum = 0;
		for (auto &ele : nums) {
			sum += ele;
		}

		if ((sum - d) < 0) {
			return 0;
		}

		if ((sum - d) % 2 == 1) {
			return 0;
		}

		int target = (sum - d) / 2; // Analyse the question for better understanding.

		vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

		return recur(nums, n, 0, target, dp);

		//********************************Iterative DP*********************************************

		vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

		//  DP[i][j] denotes the number of ways to form a subset of sum j if we only consider 1st i elements.

		dp[0][0] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= target; j++) {

				int not_taken = dp[i - 1][j];

				int taken = 0;

				if (j >= nums[i - 1]) {
					taken = dp[i - 1][j - nums[i - 1]];
				}

				dp[i][j] = (taken + not_taken) % mod;
			}
		}

		return dp[n][target];

		//******************************* Space Optimization Iterative DP***************************************

		vector<int> prev(target + 1, 0);

		prev[0] = 1;

		for (int i = 1; i <= n; i++) {

			vector<int> curr(target + 1, 0);
			curr[0] = 1;

			for (int j = 0; j <= target; j++) {

				int not_taken = prev[j];

				int taken = 0;

				if (j >= nums[i - 1]) {
					taken = prev[j - nums[i - 1]];
				}

				curr[j] = (taken + not_taken) % mod;
			}

			prev = curr;
		}

		return prev[target];
	}
};