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

int mcm(vector<int> &nums, int st, int end, vector<vector<int>> &dp) {
	if (st == end) {
		return 0;
	}

	if (dp[st][end] != -1) {
		return dp[st][end];
	}

	int mn = INT_MAX;

	for (int i = st; i < end; i++) {

		int rec_res = mcm(nums, st, i, dp) + mcm(nums, i + 1, end, dp) + (nums[st - 1] * nums[i] * nums[end]);

		mn = min(mn, rec_res);
	}

	return dp[st][end] = mn;
}


int matrixMultiplication(vector<int> &nums, int n) {

	// vector<vector<int>> dp(n, vector<int>(n, -1));

	// return mcm(nums, 1, n - 1, dp);

	//**********************************Iterative DP Solution*************************************

	vector<vector<int>> dp(n , vector<int>(n , 0));

	for (int st = n - 1; st >= 1; st--) {
		for (int end = st + 1; end < n; end++) {

			int mn = INT_MAX;

			for (int k = st; k < end; k++) {

				int rec_res = dp[st][k] + dp[k + 1][end] + (nums[st - 1] * nums[k] * nums[end]);

				mn = min(mn, rec_res);
			}

			dp[st][end] = mn;
		}
	}

	return dp[1][n - 1];
}