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

	int recur(vector<int> &nums1, vector<int> &nums2, int n, int prev1, int prev2, int si, int swap, vector<vector<int>> &dp) {
		if (si >= n) {
			return 0;
		}

		if (dp[si][swap] != -1) {
			return dp[si][swap];
		}

		int ans = (1e8);

		if (nums1[si] > prev1 && nums2[si] > prev2) {
			ans = min(ans, recur(nums1, nums2, n, nums1[si], nums2[si], si + 1, 0, dp));
		}

		if (nums1[si] > prev2 && nums2[si] > prev1) {
			ans = min(ans, 1 + recur(nums1, nums2, n, nums2[si], nums1[si], si + 1, 1, dp));
		}

		return dp[si][swap] = ans;
	}

	int minSwap(vector<int>& nums1, vector<int>& nums2) {

		int n = nums1.size();

		vector<vector<int>> dp(n + 1, vector<int>(2, -1));

		return recur(nums1, nums2, n, -1, -1, 0, 0, dp);

		//****************************Iterative DP Solution ******************************************************

		vector<vector<int> > dp(n + 1, vector<int>(2, 0));

		for (int index = n - 1; index >= 0; index--) {
			for (int swapped = 0; swapped < 2; swapped++) {

				int prev1 = -1, prev2 = -1;
				if (index - 1 >= 0) {

					prev1 = nums1[index - 1];
					prev2 = nums2[index - 1];
				}

				int ans = INT_MAX;
				//if elements at last index were swapped then we need to swap our prev1 and prev2, logically.
				if (swapped) swap(prev1, prev2);

				//check if swap needed for elements at 'index'.
				if (nums1[index] > prev1 && nums2[index] > prev2) {
					//no need of swap
					ans = min(ans, dp[index + 1][0]) ;
				}
				if (nums1[index] > prev2 && nums2[index] > prev1) {
					//swap, count +1;
					ans = min(ans, 1 + dp[index + 1][1]);
				}

				dp[index][swapped] = ans;
			}
		}

		return dp[0][0];

		//*********************** Space Optimized Iterative DP********************************************

		vector<int> prev(2, 0);

		for (int index = n - 1; index >= 0; index--) {

			vector<int> curr(2, 0);

			for (int swapped = 0; swapped < 2; swapped++) {

				int prev1 = -1, prev2 = -1;
				if (index - 1 >= 0) {

					prev1 = nums1[index - 1];
					prev2 = nums2[index - 1];
				}

				int ans = INT_MAX;
				//if elements at last index were swapped then we need to swap our prev1 and prev2, logically.
				if (swapped) swap(prev1, prev2);

				//check if swap needed for elements at 'index'.
				if (nums1[index] > prev1 && nums2[index] > prev2) {
					//no need of swap
					ans = min(ans, prev[0]) ;
				}
				if (nums1[index] > prev2 && nums2[index] > prev1) {
					//swap, count +1;
					ans = min(ans, 1 + prev[1]);
				}

				curr[swapped] = ans;
			}

			prev = curr;
		}

		return prev[0];
	}
};