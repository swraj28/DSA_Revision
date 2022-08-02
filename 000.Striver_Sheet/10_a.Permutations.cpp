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

	void recur(vector<int> &nums, int n, int si, vector<vector<int>> &ans) {
		if (si >= n) {
			ans.pb(nums);
			return;
		}

		for (int i = si; i < n; i++) {
			swap(nums[i], nums[si]);
			recur(nums, n, si + 1, ans);

			swap(nums[i], nums[si]);
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {

		vector<vector<int>> ans;

		int n = nums.size();

		recur(nums, n, 0, ans);

		return ans;
	}
};