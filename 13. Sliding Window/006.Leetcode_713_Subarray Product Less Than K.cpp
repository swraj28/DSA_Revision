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
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {

		if (k == 0) {
			return 0;
		}

		int n = nums.size();

		int st = 0;

		int ans = 1;

		int total = 0;

		for (int i = 0; i < n; i++) {

			ans *= nums[i];

			while (ans >= k && st <= i) { // [1,1,1] 1
				ans /= nums[st];
				st++;
			}

			total += (i - st) + 1;
		}

		return total;
	}
};