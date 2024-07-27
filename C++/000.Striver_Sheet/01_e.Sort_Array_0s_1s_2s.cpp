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

// The key Idea is to try to place 0 and 2 at its correct place and 1 will automatically get placed at its correct positions.

class Solution {
public:
	void sortColors(vector<int>& nums) {

		int n = nums.size();

		int st = 0, end = n - 1;

		int mid = 0;

		while (mid <= end) {
			if (nums[mid] == 1) {
				mid++;
			} else if (nums[mid] == 2) {
				swap(nums[mid], nums[end]);
				end--;
			} else {
				swap(nums[mid], nums[st]);
				st++;
				mid++;
			}
		}
	}
};