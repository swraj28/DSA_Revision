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
	int smallestDistancePair(vector<int>& nums, int k) {

		int n = nums.size();

		int st = 0, end = (1e6);

		sort(all(nums));

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2);

			int cnt = 0, i = 0, j = 0;

			while (i < n || j < n) {

				while (j < n && (nums[j] - nums[i]) <= mid) {
					j++;
				}

				cnt += (j - i - 1);

				i += 1;
			}

			if (cnt >= k) {
				end = mid;
			} else {
				st = mid;
			}
		}

		int cnt = 0, i = 0, j = 0;

		while (i < n || j < n) {

			while (j < n && (nums[j] - nums[i]) <= st) {
				j++;
			}

			cnt += (j - i - 1);

			i += 1;
		}

		if (cnt >= k) {
			return st;
		}

		return end;
	}
};