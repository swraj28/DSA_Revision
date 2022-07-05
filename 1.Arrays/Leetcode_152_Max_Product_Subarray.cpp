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
	int maxProduct(vector<int>& nums) {

		int n = nums.size();
		if (n == 1) {
			return nums[0];
		}

		vector<vector<int>> dp(n, vector<int>(2, 0));

		// dp[i][0]--> max positive product till i;
		// dp[i][1]-->min negative product till i;

		int mx = 0;

		if (nums[0] > 0) {
			dp[0][0] = nums[0];
			mx = nums[0];
		} else if (nums[0] < 0) {
			dp[0][1] = nums[0];
		}

		for (int i = 1; i < n; i++) {
			if (nums[i] > 0) {
				int t_mx = max({dp[i - 1][0]*nums[i], nums[i]});

				dp[i][0] = t_mx;

				dp[i][1] = (dp[i - 1][1] * nums[i]);

				mx = max(mx, t_mx);
			} else if (nums[i] < 0) {
				dp[i][0] = (dp[i - 1][1] * nums[i]);

				dp[i][1] = min({nums[i], dp[i - 1][0]*nums[i]});

				mx = max(mx, dp[i][0]);
			}
		}

		return mx;
	}
};