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

	int recur(int st, int end, vector<vector<int>> &dp) {

		if (st >= end) {
			return 0;
		}

		if (dp[st][end] != -1) {
			return dp[st][end];
		}

		int mn = (1e8);

		for (int i = st; i < end; i++) {

			int rec_res = i + max({recur(st, i - 1, dp), recur(i + 1, end, dp)});

			mn = min(mn, rec_res);
		}

		return dp[st][end] = mn;
	}

	int getMoneyAmount(int n) {

		if (n == 1 || n == 2) {
			return (n - 1);
		}

		// vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

		// return recur(1, n, dp);

		//**********************Iterative DP****************************

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

		for (int st = n - 2; st >= 1; st--) {
			for (int end = st + 1; end < n; end++) {

				int mn = (1e8);

				for (int i = st; i < end; i++) {

					int rec_res = i + max({dp[st][i - 1], dp[i + 1][end]});

					mn = min(mn, rec_res);
				}

				dp[st][end] = mn;
			}
		}

		return dp[1][n];
	}
};