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

	int recur(string &s, int &n, int si, string &t, int &m, int si1, vector<vector<int>> &dp) {
		if (si1 >= m) {
			return 1;
		}

		if (si >= n) {
			return 0;
		}

		if (dp[si][si1] != -1) {
			return dp[si][si1];
		}

		int not_taken = recur(s, n, si + 1, t, m, si1, dp);

		int taken = 0;

		if (s[si] == t[si1]) {
			taken += recur(s, n, si + 1, t, m, si1 + 1, dp);
		}

		return dp[si][si1] = (taken + not_taken);
	}

	int numDistinct(string s, string t) {

		int n = s.length(), m = t.length();

		// vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

		// return recur(s, n, 0, t, m, 0, dp);

		//****************************Iterative DP******************************

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for (int i = 0; i <= n; i++) {
			dp[i][0] = 1;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {

				int not_taken = dp[i - 1][j];

				int taken = 0;
				if (s[i - 1] == t[j - 1]) {
					taken = dp[i - 1][j - 1];
				}

				dp[i][j] = (taken + (ll) not_taken);
			}
		}

		return dp[n][m];

		//******************************* Space Optimized Iterative DP************************

		vector<int> prev(m + 1, 0);
		prev[0] = 1;

		for (int i = 1; i <= n; i++) {

			vector<int> curr(m + 1, 0);
			curr[0] = 1;

			for (int j = 1; j <= m; j++) {

				int not_taken = prev[j];

				int taken = 0;
				if (s[i - 1] == t[j - 1]) {
					taken = prev[j - 1];
				}

				curr[j] = (taken + (ll) not_taken);
			}

			prev = curr;
		}

		return prev[m];
	}
};