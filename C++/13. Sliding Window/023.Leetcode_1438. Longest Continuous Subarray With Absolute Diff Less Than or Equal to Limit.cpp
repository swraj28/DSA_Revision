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
	int longestSubarray(vector<int>& nums, int limit) {

		int n = nums.size();

		int mx = 0, j = 0;

		multiset<int> s;

		for (int i = 0; i < n; i++) {
			s.insert(nums[i]);

			while (*(--s.end()) - *s.begin() > limit) {

				s.erase(s.find(nums[j]));

				j++;
			}

			mx = max(mx, (i - j) + 1);
		}

		return mx;
	}
};

// Using Monotonic Dequue--> Storing the element in decreasing order for maximum and increasing order for minimum

int longestSubarray(vector<int>& A, int limit) {
	deque<int> maxd, mind;
	int i = 0, j;
	for (j = 0; j < A.size(); ++j) {

		while (!maxd.empty() && A[j] > maxd.back()) maxd.pop_back(); // Maintaining the monotonic behaviour.
		while (!mind.empty() && A[j] < mind.back()) mind.pop_back(); // Maintaining the monotonic behaviour.

		maxd.push_back(A[j]);
		mind.push_back(A[j]);

		if (maxd.front() - mind.front() > limit) {
			if (maxd.front() == A[i]) maxd.pop_front();
			if (mind.front() == A[i]) mind.pop_front();
			++i;
		}
	}

	return j - i;
}