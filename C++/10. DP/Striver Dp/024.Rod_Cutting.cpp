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

int recur(int st_len, vector<int> &price, int mxLen, vector<vector<int>> &dp) {
	if (st_len > mxLen) {
		return 0;
	}

	if (dp[st_len][mxLen] != -1) {
		return dp[st_len][mxLen];
	}

	int not_taken = 0 + recur(st_len + 1, price, mxLen, dp);

	int taken = INT_MIN;
	if (mxLen >= st_len) {
		taken = price[st_len - 1] + recur(st_len, price, mxLen - st_len, dp);
	}

	return dp[st_len][mxLen] = max(taken , not_taken);
}

int cutRod(vector<int> &price, int mxLen) {

	vector<vector<int>> dp(mxLen + 1, vector<int>(mxLen + 1, -1));

	return recur(1, price, mxLen, dp);

	//*****************Iterative DP**************************************

	vector<vector<int>> dp(mxLen + 1, vector<int>(mxLen + 1, 0));

	for (int i = 1; i <= mxLen; i++) {
		for (int j = 1; j <= mxLen; j++) {

			int not_taken = 0 + dp[i - 1][j];

			int taken = INT_MIN;
			if (j >= i) {
				taken = price[i - 1] + dp[i][j - i];
			}

			dp[i][j] = max(taken, not_taken);
		}
	}

	return dp[mxLen][mxLen];

	//*********************** Space Optimized Iterative DP**********************

	vector<int> prev(mxLen + 1, 0);

	for (int i = 1; i <= mxLen; i++) {

		vector<int> curr(mxLen + 1, 0);

		for (int j = 1; j <= mxLen; j++) {

			int not_taken = 0 + prev[j];

			int taken = INT_MIN;
			if (j >= i) {
				taken = price[i - 1] + curr[j - i];
			}

			curr[j] = max(taken, not_taken);
		}

		prev = curr;
	}

	return prev[mxLen];
}


