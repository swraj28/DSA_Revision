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

	int recur(vector<int> &v, int si, int n, int k, vector<int> &dp) { // This funtion will return the max sum
		if (si >= n) {
			return 0;
		}

		if (dp[si] != -1) {
			return dp[si];
		}

		int ans = 0;
		int mx_so_far = INT_MIN;

		for (int i = 0; i < k && (si + i) < n; i++) {

			mx_so_far = max(mx_so_far, v[si + i]);
			int sze = ((si + i) - si) + 1;

			int rec_res = (sze * mx_so_far) + recur(v, si + i + 1, n, k, dp);

			ans = max(ans, rec_res);
		}

		return dp[si] = ans;
	}

	int maxSumAfterPartitioning(vector<int>& arr, int k) {

		int n = arr.size();

		// vector<int> dp(n + 1, -1);

		// return recur(arr, 0, n, k, dp);

		//**********************Iterative DP Solution**************************************

		vector<int> dp(n + 1, 0);

		for (int si = n - 1; si >= 0; si--) {

			int ans = 0;
			int mx_so_far = INT_MIN;

			for (int i = 0; i < k && (si + i) < n; i++) {

				mx_so_far = max(mx_so_far, arr[si + i]);
				int sze = ((si + i) - si) + 1;

				int rec_res = (sze * mx_so_far) + dp[si + i + 1];

				ans = max(ans, rec_res);
			}

			dp[si] = ans;
		}

		return dp[0];
	}
};