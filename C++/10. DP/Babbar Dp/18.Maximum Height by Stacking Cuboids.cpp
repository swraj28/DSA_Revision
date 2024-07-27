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

	int recur(vector<vector<int>>& cuboids, int n, int si, int prev, vector<vector<int>> &dp) {
		if (si >= n) {
			return 0;
		}

		if (dp[si][prev + 1] != -1) {
			return dp[si][prev + 1];
		}

		int not_taken = recur(cuboids, n, si + 1, prev, dp);

		int taken = 0;

		if (prev == -1 || cuboids[prev][0] >= cuboids[si][0] && cuboids[prev][1] >= cuboids[si][1] && cuboids[prev][2] >= cuboids[si][2]) {
			taken = cuboids[si][2] + recur(cuboids, n, si + 1, si, dp);
		}

		return dp[si][prev + 1] = max(taken, not_taken);
	}

	int maxHeight(vector<vector<int>>& cuboids) {

		int n = cuboids.size();

		for (auto &it : cuboids) {
			sort(all(it));
		}

		sort(all(cuboids), greater<vector<int>>());

		// vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

		// return recur(cuboids, n, 0, -1, dp);

		//*********************************Iterative DP Solution **********************************************************

		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

		for (int si = n - 1; si >= 0; si--) {
			for (int prev = si + 1; prev < n; prev++) {

				int not_taken = 0;

				if (prev != -1) {
					not_taken = dp[si + 1][prev];
				}

				int taken = 0;

				if (prev == -1 || cuboids[prev][0] >= cuboids[si][0] && cuboids[prev][1] >= cuboids[si][1] && cuboids[prev][2] >= cuboids[si][2]) {
					taken = cuboids[si][2] + dp[si + 1][si];
				}

				dp[si][prev + 1] = max(taken, not_taken);
			}
		}

		return dp[0][-1 + 1];
	}
};