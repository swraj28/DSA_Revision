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
	int lengthOfLIS(vector<int>& nums) {

		int n = nums.size();

		vector<int> sub;

		for (int i = 0; i < n; i++) {

			if (sub.empty() || sub[sub.size() - 1] < nums[i]) {
				sub.pb(nums[i]);
			} else {
				auto itr = lower_bound(all(sub), nums[i]);
				*itr = nums[i];
			}
		}

		return (int)sub.size();
	}
};