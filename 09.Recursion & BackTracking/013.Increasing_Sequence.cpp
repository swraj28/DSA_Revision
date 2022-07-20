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

/*

    Let n be the length of the vector .

    worst case :- if the array is completly sorted then at every point we have 2 possiblities . T.c:- O(n*2^n).

*/

class Solution {
public:

	void recur(vector<int> &nums, int n, int si, vector<int> &v, set<vector<int>> &ans) {
		if ((int)v.size() >= 2) {
			ans.insert(v);
		}

		unordered_set<int> s;

		for (int i = si; i < n; i++) {
			if (v.empty() || (v[v.size() - 1] <= nums[i] && s.count(nums[i]) == 0)) {
				v.pb(nums[i]);

				recur(nums, n, i + 1, v, ans);

				v.pop_back();
				s.insert(nums[i]);
			}
		}
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {

		int n = nums.size();

		vector<int> v;

		set<vector<int>> ans;

		recur(nums, n, 0, v, ans);

		vector<vector<int>> v1;

		for (auto &vec : ans) {
			v1.pb(vec);
		}

		return v1;
	}
};