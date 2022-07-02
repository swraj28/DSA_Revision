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

	// int recur(vector<int> &nums, int n, int si, vector<int> &dp) { // This function will return the maximum amount the theif can earn.
	// 	if (si >= n) {
	// 		return 0;
	// 	}

	// 	if (dp[si] != -1) {
	// 		return dp[si];
	// 	}

	// 	return dp[si] = max({nums[si] + recur(nums, n, si + 2, dp), recur(nums, n, si + 1, dp)});
	// }

	int rob(vector<int>& nums) {

		int n = nums.size();

		if (n == 1) return nums[0];

		if (n == 2) return max(nums[0], nums[1]);

		// vector<int> dp(n + 1, -1);

		// int ans1 = recur(nums, n, 1, dp);

		// dp.assign(n + 1, -1);

		// int ans2 = recur(nums, n - 1, 0, dp);

		// return max(ans1, ans2);

		//************ Space Optimization Soluting of House Robber*******************************

		vector<int> v1(nums.begin(), nums.end() - 1);
		vector<int> v2(nums.begin() + 1, nums.end());

		// for(auto ele:v1){
		//     cout<<ele<<" ";
		// }
		// cout<<endl;

		int a = 0, b = v1[0];
		int mx = max(a, b);

		for (int i = 2; i <= v1.size(); i++) {
			mx = max({mx, a + v1[i - 1], b});
			a = b;
			b = mx;
		}

		a = 0, b = v2[0];

		int mx1 = max(a, b);

		for (int i = 2; i <= v2.size(); i++) {
			mx1 = max({mx1, a + v2[i - 1], b});
			a = b;
			b = mx1;
		}

		// cout<<mx<<" "<<mx1<<endl;

		return max(mx, mx1);
	}
};