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

// T.c:- O(2^n)

class Solution {
public:

	void recur(vector<string> &arr, int n, int si, vector<string> &v, int &mx) {
		if (si >= n) {
			vector<int> cnt(26, 0);

			int x = 0;

			for (auto & word : v) {
				for (auto & ch : word) {
					if (cnt[ch - 'a']) {
						return;
					}
					x++;
					cnt[ch - 'a'] = 1;
				}
			}

			mx = max(mx, x);

			return;
		}

		v.pb(arr[si]);
		recur(arr, n, si + 1, v, mx);
		v.pop_back();
		recur(arr, n, si + 1, v, mx);
	}

	int maxLength(vector<string>& arr) {

		int n = arr.size();

		int mx = 0;

		vector<string> v;

		recur(arr, n, 0, v, mx);

		return mx;
	}
};