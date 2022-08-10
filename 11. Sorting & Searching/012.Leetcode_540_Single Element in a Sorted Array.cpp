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
	int singleNonDuplicate(vector<int>& nums) {

		int n = nums.size();

		if (n == 1) {
			return nums[0];
		}

		int st = 0, end = (n - 1);

		while (st + 1 < end) {
			int mid = (st + (end - st) / 2);

			if (nums[mid] == nums[mid - 1]) {
				int x = (mid - st) + 1;

				if (x % 2 == 0) {
					st = mid + 1;
				} else {
					end = mid;
				}
			} else if (nums[mid] == nums[mid + 1]) {
				int x = ((mid + 1) - st) + 1;

				if (x % 2 == 0) {
					st = mid + 2;
				} else {
					end = mid;
				}
			} else {
				return nums[mid];
			}
		}

		return nums[st];
	}
};