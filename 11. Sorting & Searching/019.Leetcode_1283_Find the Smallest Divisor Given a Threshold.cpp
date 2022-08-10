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
	int smallestDivisor(vector<int>& nums, int threshold) {

		int st = 1, end = (1e6);

		int n = nums.size();

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2);

			int val = 0;

			for (int i = 0; i < n; i++) {
				val += ceil(nums[i] / (mid * (1.0)));
			}

			if (val > threshold) {
				st = mid;
			} else {
				end = mid;
			}
		}

		// cout << st << " " << end << endl;

		int val = 0;

		for (int i = 0; i < n; i++) {
			val += ceil(nums[i] / (st * (1.0)));
		}

		if (val <= threshold) {
			return st;
		}

		return end;
	}
};