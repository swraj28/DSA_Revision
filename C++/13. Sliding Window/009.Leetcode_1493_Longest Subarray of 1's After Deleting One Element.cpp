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
	int longestSubarray(vector<int>& nums) {

		int n = nums.size(), j = 0, mx = 0, cnt = 0;

		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) {
				cnt++;
			}

			while (cnt > 1) {
				if (nums[j] == 0) {
					cnt--;
				}

				j++;
			}

			mx = max(mx, (i - j) + 1);
		}

		return mx - 1;
	}
};