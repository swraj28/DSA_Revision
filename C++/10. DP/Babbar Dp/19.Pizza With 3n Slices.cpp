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

// Similar to House Robber 2 .

class Solution {
public:

	int recur(vector<int> &slices, int n, int si, int req, vector<vector<int>> &dp) {

		if (req == 0) {
			return 0;
		}

		if (si >= n) {
			return (-1e7);
		}

		if (dp[si][req] != -1) {
			return dp[si][req];
		}

		int not_taken = recur(slices, n, si + 1, req, dp);

		int taken = 0;

		if (req > 0) {
			taken = slices[si] + recur(slices, n, si + 2, req - 1, dp);
		}

		return dp[si][req] = max(taken, not_taken);
	}

	int solve_iteratively(vector<int> &slices, int n, int si, int req) {

		vector<vector<int>> dp(n + 2, vector<int> (req + 1, 0));

		for (int i = n - 1; i >= si; i--) {
			for (int j = 1; j <= req; j++) {

				int not_taken = dp[i + 1][j];

				int taken = slices[i] + dp[i + 2][j - 1];

				dp[i][j] = max(taken, not_taken);
			}
		}

		return dp[n][req];
	}

	int maxSizeSlices(vector<int>& slices) {

		int n = slices.size();

		int req = (n / 3);

		// vector<vector<int>> dp(n + 1, vector<int> (req + 1, -1));

		// int val1 = recur(slices, n, 1, req, dp);

		// dp = vector<vector<int>>(n + 1, vector<int>(req + 1, -1));

		// int val2 = recur(slices, n - 1, 0, req, dp);

		// return max(val1, val2);

		//*************************Iterative DP Solution *************************************

		int val1 = solve_iteratively(slices, n, 1, req);
		int val2 = solve_iteratively(slices, n - 1, 0, req);

		return max(val1, val2);
	}
};