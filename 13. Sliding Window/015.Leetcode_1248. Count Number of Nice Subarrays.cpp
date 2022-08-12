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

	// Exactly(k)= atMost(k)-atmost(k-1).

	int cnt_subarry_atmost_k_odd_numbers(vector<int> &nums, int n, int k) {

		int odd_cnt = 0, total = 0, j = 0;

		for (int i = 0; i < n; i++) {
			odd_cnt += (nums[i] % 2);

			while (odd_cnt > k) {
				odd_cnt -= nums[j++] % 2;
			}

			total += ((i - j) + 1);
		}

		return total;
	}

	int numberOfSubarrays(vector<int>& nums, int k) {

		int n = nums.size();

		return cnt_subarry_atmost_k_odd_numbers(nums, n, k) - cnt_subarry_atmost_k_odd_numbers(nums, n, k - 1);
	}
};