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

int dp[100005][4];

int recur(vector<vector<int>> &points, int si, int n, int prev) {

	if (si >= n) {
		return 0;
	}

	if (dp[si][prev] != -1) {
		return dp[si][prev];
	}

	if (prev == 0) {
		return dp[si][prev] = max({points[si][0] + recur(points, si + 1, n, 1), points[si][1] + recur(points, si + 1, n, 2), points[si][2] + recur(points, si + 1, n, 3)});
	} else if (prev == 1) {
		return dp[si][prev] = max({points[si][1] + recur(points, si + 1, n, 2), points[si][2] + recur(points, si + 1, n, 3)});
	} else if (prev == 2) {
		return dp[si][prev] = max({points[si][0] + recur(points, si + 1, n, 1), points[si][2] + recur(points, si + 1, n, 3)});
	}

	return dp[si][prev] = max({points[si][0] + recur(points, si + 1, n, 1), points[si][1] + recur(points, si + 1, n, 2)});
}

int ninjaTraining(int n, vector<vector<int>> &points) {

	ms(dp, -1);

	return recur(points, 0, n, 0);

	//*******************************Iterative Solution**********************************************

	vector<vector<int>> dp(n, vector<int>(3, 0));

	dp[0][0] = points[0][0], dp[0][1] = points[0][1], dp[0][2] = points[0][2];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int val1 = 0, val2 = 0, val3 = 0;
			if (j == 0) {
				val1 = max(dp[i - 1][1], dp[i - 1][2]);
				dp[i][j] = val1 + points[i][j];
			} else if (j == 1) {
				val2 = max(dp[i - 1][0], dp[i - 1][2]);
				dp[i][j] = val2 + points[i][j];
			} else {
				val3 = max(dp[i - 1][0], dp[i - 1][1]);
				dp[i][j] = val3 + points[i][j];
			}
		}
	}

	return *max_element(all(dp[n - 1]));

	//*******************************************Space Optimization*****************************************

	int val1 = points[0][0], val2 = points[0][1], val3 = points[0][2];

	for (int i = 1; i < n; i++) {
		int v1 = max(val2, val3) + points[i][0];
		int v2 = max(val1, val3) + points[i][1];
		int v3 = max(val1, val2) + points[i][2];

		val1 = v1, val2 = v2, val3 = v3;
	}

	return max({val1, val2, val3});
}