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

	ll recur(int n, int &k, int target, vector<vector<int>> &dp) {

		if (n == 0 || target == 0) {
			return (n == target);
		}

		if (dp[n][target] != -1) {
			return dp[n][target];
		}

		ll total = 0;

		for (int i = 1; i <= k; i++) {
			if (target - i >= 0) {
				total = ((total) % mod + (recur(n - 1, k, target - i, dp)) % mod) % mod;
			}
		}

		return dp[n][target] = total;
	}

	int numRollsToTarget(int n, int k, int target) {

		vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

		return recur(n, k, target, dp);

		//****************************Iterative DP Solution**********************************

		vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

		dp[0][0] = 1;

		for (int i = 1; i <= n; i++) {
			for (int tar = 1; tar <= target; tar++) {

				ll total = 0;

				for (int j = 1; j <= k; j++) {
					if (tar - j >= 0) {
						total = ((total) % mod + (dp[i - 1][tar - j] % mod) ) % mod;
					}
				}

				dp[i][tar] = total;
			}
		}

		return dp[n][target];

		//*******************************Space Optimized Iterative DP Solution************************

		vector<ll> prev(target + 1, 0);

		prev[0] = 1;

		for (int i = 1; i <= n; i++) {
			vector<ll> curr(target + 1, 0);
			for (int tar = 1; tar <= target; tar++) {

				ll total = 0;

				for (int j = 1; j <= k; j++) {
					if (tar - j >= 0) {
						total = ((total) % mod + (prev[tar - j] % mod) ) % mod;
					}
				}

				curr[tar] = total;
			}

			prev = curr;
		}

		return prev[target];
	}
};