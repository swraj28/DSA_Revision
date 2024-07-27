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

// Intuition: Sort and only keep unique elements.
// The problem is the same as "get the length of the longest subarray whose difference between min and max elements is less than or equal to  (N - 1)".



class Solution {
public:
	int minOperations(vector<int>& nums) {

		int mx = 0;

		int sze = nums.size();

		int req = nums.size() - 1;

		sort(all(nums));

		nums.erase(unique(all(nums)), nums.end()); // Removing the duplicates of nums

		int j = 0;

		int n = nums.size();

		for (int i = 0; i < n; i++) {

			while ((nums[i] - nums[j]) > req) {
				j++;
			}

			if ((nums[i] - nums[j]) == req) {
				mx = max(mx, (i - j) + 1);
			}
		}

		return (sze - mx);
	}
};