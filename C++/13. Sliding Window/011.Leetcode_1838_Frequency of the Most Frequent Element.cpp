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
	int maxFrequency(vector<int>& nums, int k) {

		sort(all(nums));

		ll n = nums.size(), j = 0, sum = 0;

		ll mx = 1;

		for (ll i = 0; i < n; i++) {

			sum += (ll)nums[i];

			while ((i - j + 1)*nums[i] - sum > k) {
				sum -= nums[j];
				j++;
			}

			mx = max(mx, (i - j) + 1);
		}

		return mx;
	}
};