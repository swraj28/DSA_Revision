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

	int recur(vector<int> &satisfaction, int n, int si, int time, vector<vector<int>> &dp) {
		if (si >= n) {
			return 0;
		}

		if (dp[si][time] != -1) {
			return dp[si][time];
		}

		int not_taken = recur(satisfaction, n, si + 1, time, dp);

		int taken = (time * satisfaction[si]) + recur(satisfaction, n, si + 1, time + 1, dp);

		return dp[si][time] = max(taken, not_taken);
	}

	int maxSatisfaction(vector<int>& satisfaction) {

		int n = satisfaction.size();

		sort(all(satisfaction));

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

		return recur(satisfaction, n, 0, 1, dp);
	}
};