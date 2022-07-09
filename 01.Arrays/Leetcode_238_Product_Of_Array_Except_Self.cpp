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

// Brute force :- Time :- O(n) && Space:- O(n);

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {

		int n = nums.size();

		vector<int> pre(n, 1);
		vector<int> suff(n, 1);

		int p = 1;

		for (int i = 0; i < n; i++) {
			p *= nums[i];
			pre[i] = p;
		}

		p = 1;

		for (int i = n - 1; i >= 0; i--) {
			p *= nums[i];
			suff[i] = p;
		}

		vector<int> ans(n);

		for (int i = 0; i < n; i++) {
			int p = 1;
			if ((i - 1) >= 0) {
				p *= pre[i - 1];
			}

			if ((i + 1) < n) {
				p *= suff[i + 1];
			}

			ans[i] = p;
		}

		return ans;
	}
};

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {

		int n = nums.size();

		vector<int> ans(n);

		int p = 1;
		int z_c = 0;

		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) {
				z_c++;
			} else {
				p *= nums[i];
			}
		}

		for (int i = 0; i < n; i++) {

			if (z_c >= 2) {
				ans[i] = 0;
			} else {
				if (nums[i] == 0) {
					ans[i] = p;
				} else {
					if (z_c > 0) {
						ans[i] = 0;
					} else {
						ans[i] = (p / nums[i]);
					}
				}
			}
		}

		return ans;
	}
};

