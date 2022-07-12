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
	int findNumberOfLIS(vector<int>& nums) {

		int n = nums.size();

		vector<int> dp(n), cnt(n, 1);
		dp[0] = 1;

		int mx = 1;

		for (int i = 1; i < n; i++) { // Longest Increasing Subsequence Ending at i

			dp[i] = 1;

			for (int j = i - 1; j >= 0; j--) {
				if (nums[j] >= nums[i]) {
					continue;
				}

				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					cnt[i] = cnt[j];
				} else if (dp[j] + 1 == dp[i]) {
					cnt[i] += cnt[j];
				}
			}

			mx = max(mx, dp[i]);
		}

		int total = 0;

		for (int i = 0; i < n; i++) {
			if (dp[i] == mx) {
				total += cnt[i];
			}
		}

		return total;
	}
};