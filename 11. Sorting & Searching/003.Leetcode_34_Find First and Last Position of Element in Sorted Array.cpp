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

	int lower_bound(vector<int>& nums, int target) {

		int st = 0, end = nums.size() - 1;

		while (st + 1 < end) {
			int mid = (st + (end - st) / 2);

			if (nums[mid] >= target) {
				end = mid;
			} else {
				st = mid;
			}
		}

		if (nums[st] == target)return st;
		if (nums[end] == target)return end;

		return -1;
	}

	int upper_bound(vector<int>& nums, int target) {

		int st = 0, end = nums.size() - 1;

		while (st + 1 < end) {
			int mid = (st + (end - st) / 2);

			if (nums[mid] <= target) {
				st = mid;
			} else {
				end = mid;
			}
		}

		if (nums[end] == target)return end;
		if (nums[st] == target)return st;

		return -1;
	}

	vector<int> searchRange(vector<int>& nums, int target) {

		int n = nums.size();
		if (n == 0) {
			return { -1, -1};
		}

		return {lower_bound(nums, target), upper_bound(nums, target)};
	}
};