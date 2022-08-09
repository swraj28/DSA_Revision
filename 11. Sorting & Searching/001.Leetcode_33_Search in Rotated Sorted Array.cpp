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

// All the elements are distinct :-

class Solution {
public:
	int search(vector<int>& nums, int target) {

		int st = 0, end = nums.size() - 1;

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2);

			if (nums[mid] == target) {
				return mid;
			}

			if (nums[mid] > nums[st]) {
				if (target >= nums[st] && target <= nums[mid]) {
					end = mid;
				} else {
					st = mid;
				}
			} else if (nums[mid] < nums[end]) {
				if (target >= nums[mid] && target <= nums[end]) {
					st = mid;
				} else {
					end = mid;
				}
			}
		}

		if (nums[st] == target) return st;
		if (nums[end] == target) return end;
		return -1;
	}
};