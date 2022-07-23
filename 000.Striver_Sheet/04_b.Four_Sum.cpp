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

// Time complexity to solve k sum problem is --> (n^(k-1))

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		int n = nums.size();

		vector<vector<int>> ans;

		sort(all(nums)); // Sorting is necessary to apply the two pointer approach to solve the problem

		for (int i = 0; i < n; i++) {

			if (i != 0 && nums[i] == nums[i - 1]) { // To avoid Duplicates
				continue;
			}

			for (int j = i + 1; j < n; j++) {

				if (j != (i + 1) && nums[j] == nums[j - 1]) { // To avoid Duplicates
					continue;
				}

				int st = (j + 1), end = (n - 1);

				while (st < end) {

					ll x = (nums[i] + (ll) nums[j] + (ll) nums[st] + (ll) nums[end]);

					if (x == target) {

						ans.pb({nums[i], nums[j], nums[st], nums[end]});

						st++;

						while ((st < end) && (nums[st] == nums[st - 1])) { // To avoid Duplicates
							st++;
						}

					} else if (x < target) {
						st++;
					} else {
						end--;
					}
				}
			}
		}

		return ans;
	}
};