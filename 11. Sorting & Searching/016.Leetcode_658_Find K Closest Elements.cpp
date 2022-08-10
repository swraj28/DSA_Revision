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

// O(nlog(n))

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {

		multiset<pair<int, int>> s;

		int n = arr.size();

		for (int i = 0; i < n; i++) {
			int d = abs(x - arr[i]);

			s.insert({d, arr[i]});
		}

		vector<int> ans;

		for (auto ele : s) {
			if (k == 0) {
				break;
			}

			ans.pb(ele.ss);
			k -= 1;
		}

		sort(all(ans));

		return ans;
	}
};

/*
Time Complexity : O(n-k), we will keep reducing the window size from initial n to final k which will require a total of n-k comparisons.
Space Complexity : O(1)
*/


class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int L = 0, R = size(arr) - 1;
		while (R - L >= k) {
			if (x - arr[L] <= arr[R] - x) R--;
			else L++;
		}

		return vector<int>(begin(arr) + L, begin(arr) + R + 1);
	}
};

/*
Time Complexity : O(logn + k), We need O(logn) time complexity to find r at the start. Then we need another O(k) time to expand our window to fit k elements
Space Complexity : O(1)
*/

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int n = size(arr), R = lower_bound(begin(arr), end(arr), x) - begin(arr), L = R - 1;
		// expand the [L, R] window till its size becomes equal to k
		while (k--) {
			if (R >= n || L >= 0 && x - arr[L] <= arr[R] - x) L--; // expand from left
			else R++;
		}
		// expand from right
		return vector<int>(begin(arr) + L + 1, begin(arr) + R);
	}
};
