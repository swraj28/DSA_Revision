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

// The Brute Force Approach is to use three loops .

// Using Two Pointers:-

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		int n = nums.size();

		vector<vector<int>> ans;

		sort(all(nums));

		for (int i = 0; i < n; i++) {

			if (i != 0 && nums[i] == nums[i - 1]) { // To avoid Duplicates
				continue;
			}

			int j = i + 1, k = n - 1;

			while (j < k) {

				if (nums[i] + nums[j] + nums[k] == 0) {
					ans.pb({nums[i], nums[j], nums[k]});

					j++;

					while (j < k && nums[j] == nums[j - 1]) { // To avoid Duplicates
						j++;
					}
				} else if (nums[i] + nums[j] + nums[k] < 0) {
					j++;
				} else {
					k--;
				}
			}
		}

		return ans;
	}
};