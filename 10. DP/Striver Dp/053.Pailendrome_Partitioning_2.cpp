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

	int recur(string s, int st, int end, vector<vector<bool>> &is_pailendrome, vector<vector<int>> &dp) { // This Function will return the minimum number of cut required

		if (st == end) {
			return 0;
		}

		if (is_pailendrome[st][end] == 1) { // If s[st..end] is a pailendrome
			return 0;
		}

		if (dp[st][end] != -1) {
			return dp[st][end];
		}

		int mn = INT_MAX;

		for (int i = st; i < end; i++) {

			if (is_pailendrome[st][i] == 1) {
				int rec_res = 1 + recur(s, i + 1, end, is_pailendrome, dp);
				mn = min(mn, rec_res);
			}
		}

		return dp[st][end] = mn;
	}

	int minCut(string s) {

		int n = s.length();


		//************ To check for Pailendrome***************************************************

		vector<vector<bool>> is_pailendrome(n + 1, vector<bool>(n + 1, 0));


		for (int i = 0; i < n; i++) { // A single character will always be a pailendrome (sz=1).
			is_pailendrome[i][i] = 1;
		}

		for (int sze = 2; sze <= n; sze++) {

			for (int i = 0; i <= (n - sze); i++) {

				int start = i, end = (i + sze - 1);

				if (sze == 2) {
					if (s[start] == s[end]) {
						is_pailendrome[start][end] = 1;
					}
				} else {
					if ((s[start] == s[end]) and (is_pailendrome[start + 1][end - 1])) {
						is_pailendrome[start][end] = 1;
					}
				}
			}
		}

		//********************************************************************************************

		// vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

		// return recur(s, 0, n - 1, is_pailendrome, dp);

		//********************************Iterative DP Solution************************************

		vector<int> dp(n + 1, 0);

		for (int st = n - 1; st >= 0; st--) {

			if (is_pailendrome[st][n - 1]) {
				continue;
			}

			int mn = INT_MAX;

			for (int i = st; i < n - 1; i++) {

				if (is_pailendrome[st][i] == 1) {
					int rec_res = 1 + dp[i + 1];
					mn = min(mn, rec_res);
				}
			}

			dp[st] = mn;
		}

		return dp[0];
	}
};