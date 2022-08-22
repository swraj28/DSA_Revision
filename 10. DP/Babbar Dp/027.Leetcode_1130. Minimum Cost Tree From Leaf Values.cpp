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

	int recur(vector<int> &nums, int st, int end, vector<vector<int>> &dp) {
		if (st >= end) {
			return 0;
		}

		if (dp[st][end] != -1) {
			return dp[st][end];
		}

		int res = (1e8);

		for (int i = st; i < end; i++) {

			int mx1 = 0, mx2 = 0;

			for (int j = st; j <= i; j++) {
				mx1 = max(mx1, nums[j]);
			}

			for (int j = i + 1; j <= end; j++) {
				mx2 = max(mx2, nums[j]);
			}

			int rec_res = (mx1 * mx2) + recur(nums, st, i, dp) + recur(nums, i + 1, end, dp);

			res = min(res, rec_res);
		}

		return dp[st][end] = res;
	}

	int mctFromLeafValues(vector<int>& nums) {

		int n = nums.size();

		// vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

		// return recur(nums, 0, n - 1, dp);

		//*************************Iterative Bottom Up DP***************************************

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

		for (int st = n - 2; st >= 0; st--) {
			for (int end = st + 1; end < n; end++) {

				int res = (1e8);

				for (int i = st; i < end; i++) {

					int mx1 = 0, mx2 = 0;

					for (int j = st; j <= i; j++) {
						mx1 = max(mx1, nums[j]);
					}

					for (int j = i + 1; j <= end; j++) {
						mx2 = max(mx2, nums[j]);
					}

					int rec_res = (mx1 * mx2) + dp[st][i] + dp[i + 1][end];

					res = min(res, rec_res);
				}

				dp[st][end] = res;
			}
		}

		return dp[0][n - 1];
	}
};