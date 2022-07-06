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

bool recur(vector<int> &nums, int n, int si, int sm, vector<vector<int>> &dp) {
	if (sm == 0) {
		return true;
	}

	if (si >= n) {
		return false;
	}

	if (dp[si][sm] != -1) {
		return dp[si][sm];
	}

	bool not_taken = recur(nums, n, si + 1, sm, dp);

	bool taken = false;

	if (sm >= nums[si]) {
		taken = recur(nums, n, si + 1, sm - nums[si], dp);
	}


	return dp[si][sm] = (taken || not_taken);
}

int minDifference(int arr[], int n)  {

	vector<int> v;

	for (int i = 0; i < n; i++) {
		v.push_back(arr[i]);
	}

	int sm = 0;

	for (int i = 0; i < n; i++) {
		sm += v[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(sm + 1, -1));

	int mn = INT_MAX;

	for (int i = 0; i <= sm / 2; i++) {
		if (recur(v, n, 0, i, dp)) {
			int val = sm - i;
			val = abs(val - i);
			if (val < mn) {
				mn = val;
			}
		}
	}

	return mn;
}