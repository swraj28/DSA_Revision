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

void print_LIS(vector<int> &nums) {

	int n = nums.size();

	vector<int> dp(n);
	dp[0] = 1;

	int mx = 1;

	for (int i = 1; i < n; i++) { // Longest Increasing Subsequence Ending at i

		dp[i] = 1;

		for (int j = i - 1; j >= 0; j--) {
			if (nums[j] >= nums[i]) {
				continue;
			}

			dp[i] = max(dp[i], dp[j] + 1);
		}

		mx = max(mx, dp[i]);
	}

	vector<int> lis;

	for (int i = n - 1; i >= 0 && mx > 0; i--) {
		if (dp[i] == mx) {
			lis.pb(nums[i]);
			mx--;
		}
	}

	reverse(all(lis));

	// The Lis vector will contain one of the probable LIS
}