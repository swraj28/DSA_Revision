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

ll recur(string &s, int st, int end, bool is_true, vector<vector<vector<int>>> &dp) {
	if (st > end) {
		return 0;
	}

	if (st == end) {
		if (is_true) {
			return s[st] == 'T';
		}

		return s[st] == 'F';
	}

	if (dp[st][end][is_true] != -1) {
		return dp[st][end][is_true];
	}

	ll val = 0;

	for (int k = st + 1; k <= end - 1; k += 2) {

		ll t1 = recur(s, st, k - 1, true, dp);
		ll f1 = recur(s, st, k - 1, false, dp);

		ll t2 = recur(s, k + 1, end, true, dp);
		ll f2 = recur(s, k + 1, end, false, dp);

		if (s[k] == '&') {
			if (is_true == true) {
				val += (ll) (t1 * t2) % mod;
			} else {
				val += (ll) ((t1 * (ll) f2) % mod + (f1 * (ll) t2) % mod + (f1 * (ll) f2) % mod) % mod;
			}
		} else if (s[k] == '^') {
			if (is_true == true) {
				val += (ll) ((t1 * (ll) f2) % mod + (f1 * (ll) t2) % mod) % mod;
			} else {
				val += (ll) ((t1 * (ll) t2) % mod + (f1 * (ll) f2) % mod) % mod;
			}
		} else {
			if (is_true == true) {
				val += (ll) ((t1 * (ll) t2) % mod + (t1 * (ll) f2) % mod + (t2 * (ll) f1) % mod) % mod;
			} else {
				val += (ll) (f1 * (ll) f2) % mod;
			}
		}
	}

	return dp[st][end][is_true] = val % mod;
}

int evaluateExp(string & s) {

	int n = s.length();

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));

	return recur(s, 0, n - 1, true, dp);

	//********************* Iterative DP Solution**************************************


}