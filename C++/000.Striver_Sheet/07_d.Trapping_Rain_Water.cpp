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

// The Brute Force approach is that for every building we will find the largest building size on the left and right .


// Approach 1:- using 2 vectors to store maximum elevation from left and right

class Solution {
public:
	int trap(vector<int>& height) {

		int n = height.size();

		vector<int> peak_left(n, 0);
		vector<int> peak_right(n, 0);

		int c_max = height[0];

		for (int i = 1; i < n; i++) {
			peak_left[i] = c_max;
			c_max = max(c_max, height[i]);
		}

		c_max = height[n - 1];

		for (int i = n - 2; i >= 0; i--) {
			peak_right[i] = c_max;
			c_max = max(c_max, height[i]);
		}

		int ans = 0;

		for (int i = 1; i < n - 1; i++) {

			int val = min(peak_left[i], peak_right[i]);

			if (val > height[i]) {
				ans += (val - height[i]);
			}
		}

		return ans;
	}
};

// Approach 2 :- Using only one vector.

class Solution {
public:
	int trap(vector<int>& height) {

		int n = height.size();

		vector<int> dp(n, 0);

		int c_max = height[0];

		for (int i = 1; i < n; i++) {
			dp[i] = c_max;
			c_max = max(c_max, height[i]);
		}

		int ans = 0;

		c_max = height[n - 1];

		for (int i = n - 2; i > 0; i--) {
			int val = min(dp[i], c_max);

			if (val > height[i]) {
				ans += (val - height[i]);
			}

			c_max = max(c_max, height[i]);
		}

		return ans;
	}
};


// Appraoch 3: Using Constant Space.

class Solution {
public:
	int trap(vector<int>& height) {

		int n = height.size();
		if (n < 3) {
			return 0;
		}

		int st = 1, end = n - 2;  // We have not started from 0 and n-1 as they are not going to store any water.

		int mx_left = height[0], mx_right = height[n - 1];

		int ans = 0;

		while (st <= end) {

			if (mx_left <= mx_right) {
				int val = height[st];

				if (val < mx_left) {
					ans += (mx_left - val);
				} else {
					mx_left = max(mx_left, val);
				}

				st++;
			} else {
				int val = height[end];

				if (val < mx_right) {
					ans += (mx_right - val);
				} else {
					mx_right = max(mx_right, val);
				}

				end--;
			}
		}

		return ans;
	}
};