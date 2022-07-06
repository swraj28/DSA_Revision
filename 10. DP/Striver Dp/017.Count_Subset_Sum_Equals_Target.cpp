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

// The reccurance will fail if we consider nums[idx]>=0. As per the question nums[idx]>=1.

// The recurrances will be same only thing we need to manage is the base condition.

// if (si >= n) {
// 	if (target == 0) {
// 		return 1;
// 	}
// }

int recur(vector<int> &nums, int n, int si, int target, vector<vector<int>> &dp) {
	if (target == 0) {
		return 1;
	}

	if (si >= n) {
		return 0;
	}

	if (dp[si][target] != -1) {
		return dp[si][target];
	}

	int not_taken = recur(nums, n, si + 1, target, dp);

	int taken = 0;

	if (target >= nums[si]) {
		taken = recur(nums, n, si + 1, target - nums[si], dp);
	}

	return dp[si][target] = (taken + not_taken);
}

int findWays(vector<int> &nums, int target) {

	int n = nums.size();

	vector<vector<int>> dp(n + 1, vector<int>(tar + 1, -1));

	return recur(nums, n, 0, tar, dp);

	//**************Iterative DP*******************************************

	vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= target; j++) {

			int not_taken = dp[i - 1][j];

			int taken = 0;

			if (j >= nums[i - 1]) {
				taken = dp[i - 1][j - nums[i - 1]];
			}

			dp[i][j] = (taken + not_taken);
		}
	}

	return dp[n][target];

	//****************************Space Optimized DP********************************

	vector<int> prev(target + 1, 0);
	prev[0] = 1;

	for (int i = 1; i <= n; i++) {

		vector<int> curr(target + 1, 0);
		curr[0] = 1;

		for (int j = 1; j <= target; j++) {

			int not_taken = prev[j];

			int taken = 0;

			if (j >= nums[i - 1]) {
				taken = prev[j - nums[i - 1]];
			}

			curr[j] = (taken + not_taken);
		}

		prev = curr;
	}

	return prev[target];
}