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

	bool recur(vector<int>& nums, int n, int si, int sm, vector<vector<int>> &dp) {
		if (sm == 0) {
			return true;
		}

		if (si >= n) {
			return false;
		}

		if (dp[si][sm] != -1) {
			return dp[si][sm];
		}

		bool not_taken = recur(nums, n, si + 1, sm, dp);

		bool taken = false;

		if (sm >= nums[si]) {
			taken = recur(nums, n, si + 1, sm - nums[si], dp);
		}


		return dp[si][sm] = (taken || not_taken);

	}

	bool canPartition(vector<int>& nums) {

		int n = nums.size();
		int sm = 0;

		for (int i = 0; i < n; i++) {
			sm += nums[i];
		}

		if (sm & 1) {
			return false;
		}

		sm = (sm / 2);

		// vector<vector<int>> dp(n + 1, vector<int>(sm + 1, -1));

		// return recur(nums, n, 0, sm, dp);

		//*********************Iterative DP****************************************************

		vector<vector<bool>> dp(n + 1, vector<bool>(sm + 1, false));

		for (int i = 0; i < n; i++) {
			dp[i][0] = true;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= sm; j++) {

				bool not_taken = dp[i - 1][j];

				bool taken = false;

				if (j >= nums[i - 1]) {
					taken = dp[i - 1][j - nums[i - 1]];
				}

				dp[i][j] = (taken || not_taken);
			}
		}

		return dp[n][sm];

		//************************************ Space Optimized Iterative DP****************************

		vector<bool> prev(sm + 1, false);

		prev[0] = true;

		for (int i = 1; i <= n; i++) {

			vector<bool> curr(sm + 1, false);
			curr[0] = true;

			for (int j = 1; j <= sm; j++) {

				bool not_taken = prev[j];

				bool taken = false;

				if (j >= nums[i - 1]) {
					taken = prev[j - nums[i - 1]];
				}

				curr[j] = (taken || not_taken);
			}

			prev = curr;
		}

		return prev[sm];
	}
};