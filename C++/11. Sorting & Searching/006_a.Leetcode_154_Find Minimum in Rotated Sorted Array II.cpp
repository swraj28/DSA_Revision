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
	int findMin(vector<int>& nums) {

		int n = nums.size();

		int st = 0, end = (n - 1);

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2);

			// Here either we can make st++ or end-- but we cannot make st=mid or end=mid.

			// Reason :- [10,1,10,10,10],[3,3,3,1,2,3] --> As we are not sure that the answer is present in which part either [st,mid] or [mid,end]

			if (nums[mid] == nums[st] && nums[mid] == nums[end]) { // Extra Condition from Search in Rotated Sorted Array
				st++;
				continue;
			}

			if (nums[end] >= nums[mid]) {
				end = mid;
			} else {
				st = mid;
			}
		}

		return min({nums[st], nums[end]});
	}
};