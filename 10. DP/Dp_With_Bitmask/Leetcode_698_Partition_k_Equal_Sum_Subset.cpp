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

	bool recur(vector<int>& nums, int n, int si, int req, int c_sm, int k, int &mask, vector<vector<int>> &dp) {

		if (k == 1) {
			return true;
		}

		if (dp[si][mask] != -1) {
			return dp[si][mask];
		}

		if (c_sm == req) {
			return dp[si][mask] = recur(nums, n, 0, req, 0, k - 1, mask, dp);
		}

		for (int i = si; i < n; i++) {
			if ((mask & (1 << i)) == 0) {

				if ((c_sm + nums[i]) <= req) {

					mask |= (1 << i);

					bool rec_res = recur(nums, n, i + 1, req, c_sm + nums[i], k, mask, dp);

					if (rec_res == true) {
						return dp[si][mask] = true;
					}

					mask ^= (1 << i);
				}
			}
		}

		return dp[si][mask] = false;
	}

	bool canPartitionKSubsets(vector<int>& nums, int k) {

		if (k == 1) {
			return true;
		}

		int n = nums.size();
		int sm = 0;

		for (int i = 0; i < n; i++) {
			sm += nums[i];
		}

		if (sm % k) {
			return false;
		}

		int req = (sm / k);

		int mask = 0;

		vector<vector<int>> dp(n + 1, vector<int>((1 << n) + 1, -1));

		return recur(nums, n, 0, req, 0, k, mask, dp);
	}
};