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
	vector<vector<int>> res;

	void recur(int n, int start, int k, vector<int> &ans) {
		if (start > n) {
			if (ans.size() == k) {
				res.push_back(ans);
			}
			return;
		}

		ans.push_back(start);
		recur(n, start + 1, k, ans);
		ans.pop_back();
		recur(n, start + 1, k, ans);
	}

	vector<vector<int>> combine(int n, int k) {

		vector<int> ans;

		recur(n, 1, k, ans);

		return res;
	}
};