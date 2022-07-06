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

// Recursion + Memoization :-

bool recur(vector<int> &nums, int n, int si, int k, vector<vector<int>> &dp) {
	if (k == 0) {
		return true;
	}

	if (si >= n) {
		return false;
	}

	if (dp[si][k] != -1) {
		return dp[si][k];
	}

	bool not_taken = recur(nums, n, si + 1, k, dp);

	bool taken = false;

	if (k >= nums[si]) {

		taken = recur(nums, n, si + 1, k - nums[si], dp);
	}

	return dp[si][k] = (taken || not_taken);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {

	// vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

	// return recur(arr, n, 0, k, dp);

	//*****************************Iterative DP***************************************

	vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

	for (int i = 0; i < n; i++) {
		dp[i][0] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {

			bool not_taken = dp[i - 1][j];

			bool taken = false;

			if (j >= arr[i - 1]) {
				taken = dp[i - 1][j - arr[i - 1]];
			}

			dp[i][j] = (taken || not_taken);
		}
	}

	return dp[n][k];

//  *********************** Space Optimization****************************************

	vector<bool> prev(k + 1, 0);

	prev[0] = true;

	for (int i = 1; i <= n; i++) {

		vector<bool> curr(k + 1, 0);

		curr[0] = true;

		for (int j = 1; j <= k; j++) {

			bool not_taken = prev[j];

			bool taken = false;

			if (j >= arr[i - 1]) {
				taken = prev[j - arr[i - 1]];
			}

			curr[j] = (taken || not_taken);
		}

		prev = curr;
	}

	return prev[k];
}

