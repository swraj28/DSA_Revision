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

	int recur(vector<int> &nums, int n, int st, int end, vector<vector<int>> &dp) { // This Function will return max points gained by bursting the ballons
		if (st > end) {
			return 0;
		}

		if (dp[st][end] != -1) {
			return dp[st][end];
		}

		int mx = INT_MIN;

		for (int i = st; i <= end; i++) {
			int val = nums[i];

			// Why we are multiplying with(st-1) and (end+1) and not with (i-1) and not with (i+1)??

			/*
			   Watch Striver Video On Burst Ballon to get the answer.

			   Answer:- Start bursting the Ballons from the Bottom for the intervals to be non-overlapping.
			*/

			if ((st - 1) >= 0) {
				val *= nums[st - 1];
			}

			if ((end + 1) < n) {
				val *= nums[end + 1];
			}

			int rec_res_1 = recur(nums, n, st, i - 1, dp);
			int rec_res_2 = recur(nums, n, i + 1, end, dp);

			val += (rec_res_1 + rec_res_2);

			mx = max({mx, val});
		}

		return dp[st][end] = mx;
	}

	int maxCoins(vector<int>& nums) {

		int n = nums.size();

		// vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

		// return recur(nums, n, 0, n - 1, dp);

		//****************************Itearative DP Solution***************************

		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

		for (int st = n - 1; st >= 0; st--) {
			for (int end = 0; end < n; end++) {

				int mx = INT_MIN;

				for (int i = st; i <= end; i++) {

					int val = nums[i];

					if ((st - 1) >= 0) {
						val *= nums[st - 1];
					}

					if ((end + 1) < n) {
						val *= nums[end + 1];
					}

					int rec_res_1 = dp[st][i - 1];
					int rec_res_2 = dp[i + 1][end];

					val += (rec_res_1 + rec_res_2);

					mx = max({mx, val});
				}

				dp[st][end] = max(mx, dp[st][end]);
			}
		}

		return dp[0][n - 1];
	}
};