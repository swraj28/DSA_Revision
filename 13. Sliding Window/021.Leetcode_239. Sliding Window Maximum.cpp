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

// Similar to Constrained Subsequence Sum (1425)

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {

		vector<int> ans;

		int n = nums.size();

		priority_queue<pair<int, int>> pq;

		for (int i = 0; i < k; i++) {
			pq.push({nums[i], i});
		}

		ans.pb({pq.top().ff});

		int j = k;

		for (int i = 1; i <= (n - k); i++) {

			while (!pq.empty() && pq.top().ss < i) {
				pq.pop();
			}

			pq.push({nums[j], j});

			j++;

			ans.pb(pq.top().ff);
		}

		return ans;
	}
};

// Using Deque:- (Using monotonic decreasing deque) Accepted

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {

		vector<int> ans;

		int n = nums.size();

		deque<int> dq;

		for (int i = 0; i < n; i++) {

			if ((i - k) >= 0 && dq.front() == (i - k)) {
				dq.pop_front();
			}

			while (!dq.empty() && nums[i] > nums[dq.back()]) {
				dq.pop_back();
			}

			dq.push_back(i);

			if (i >= k - 1) {
				ans.pb(nums[dq.front()]);
			}
		}

		return ans;
	}
};
