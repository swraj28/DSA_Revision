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

// All the elements are distict

class Solution {
public:
	int findMin(vector<int>& nums) {

		int st = 0, end = nums.size() - 1;

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2);

			if (nums[end] > nums[mid]) {
				end = mid;
			} else {
				st = mid;
			}
		}

		return min({nums[st], nums[end]});
	}
};