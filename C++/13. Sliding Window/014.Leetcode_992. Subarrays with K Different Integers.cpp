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

/*
First you may have feeling of using sliding window.
Then this idea get stuck in the middle.

This problem will be a very typical sliding window,
if it asks the number of subarrays with at most K distinct elements.

Just need one more step to reach the folloing equation:

-->exactly(K) = atMost(K) - atMost(K-1)
*/

class Solution {
public:

	int cnt_subarrays_with_given_no_distinct_elements(vector<int> & nums, int k) {

		int n = nums.size(), j = 0, total = 0;

		unordered_map<int, int> m;

		int sze = 0;

		for (int i = 0; i < n; i++) {

			if (m[nums[i]] == 0) {
				sze++;
			}

			m[nums[i]]++;

			while (sze > k ) {

				m[nums[j]] -= 1;

				if (m[nums[j]] == 0) {
					sze--;
				}

				j++;
			}

			total += ((i - j) + 1);
		}

		return total;
	}

	int subarraysWithKDistinct(vector<int>& nums, int k) {

		return (cnt_subarrays_with_given_no_distinct_elements(nums, k) - cnt_subarrays_with_given_no_distinct_elements(nums, k - 1));
	}
};