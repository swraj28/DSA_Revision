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

int recur(vector<int> &weight, vector<int> &value, int n, int si, int maxWeight, vector<vector<int>> &dp) {
	if (si >= n || maxWeight == 0) {
		return 0;
	}

	if (dp[si][maxWeight] != -1) {
		return dp[si][maxWeight];
	}

	int not_taken = 0 + recur(weight, value, n, si + 1, maxWeight, dp);

	int taken = INT_MIN;

	if (maxWeight >= weight[si]) {
		taken = value[si] + recur(weight, value, n, si, maxWeight - weight[si], dp);
	}

	return dp[si][maxWeight] = max(taken , not_taken);
}

int unboundedKnapsack(int n, int maxWeight, vector<int> &value, vector<int> &weight) {

	vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1));

	return recur(weight, value, n, 0, maxWeight, dp);

	//****************************Iterative DP********************************************

	vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= maxWeight; j++) {

			int not_taken = dp[i - 1][j];

			int taken = INT_MIN;

			if (j >= weight[i - 1]) {
				taken = value[i - 1] + dp[i][j - weight[i - 1]];
			}

			dp[i][j] = max(taken, not_taken);
		}
	}

	return dp[n][maxWeight];

	//**************************** Space Optimized Iterative DP********************************

	vector<int> prev(maxWeight + 1, 0);

	for (int i = 1; i <= n; i++) {

		vector<int> curr(maxWeight + 1, 0);

		for (int j = 1; j <= maxWeight; j++) {

			int not_taken = prev[j];

			int taken = INT_MIN;

			if (j >= weight[i - 1]) {
				taken = value[i - 1] + curr[j - weight[i - 1]];
			}

			curr[j] = max(taken, not_taken);
		}

		prev = curr;
	}

	return prev[maxWeight];
}
