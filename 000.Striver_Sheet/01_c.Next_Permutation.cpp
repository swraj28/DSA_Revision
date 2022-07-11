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

// https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/

// It is sure that from the last there will be an increasing subarray of length atleast 1.

class Solution {
public:
	void nextPermutation(vector<int>& nums) {

		int n = nums.size(), idx;

		for (idx = n - 2; idx >= 0; idx--) {
			if (nums[idx] < nums[idx + 1]) {
				break;
			}
		}

		if (idx < 0) {
			reverse(all(nums));
		} else {

			int idx1;

			for (idx1 = n - 1; idx1 > idx; idx1--) {
				if (nums[idx1] > nums[idx]) {
					break;
				}
			}

			swap(nums[idx], nums[idx1]);

			reverse(nums.begin() + idx + 1, nums.end());
		}
	}
};