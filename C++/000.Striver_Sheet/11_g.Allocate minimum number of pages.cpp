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
	int findPages(int A[], int N, int M) {

		int n = N, m = M;

		vector<int> v(n);

		for (int i = 0; i < n; i++) {
			v[i] = A[i];
		}

		ll st = v[0], end = accumulate(all(v), 0ll);

		while (st + 1 < end) {

			ll mid = (st + (end - st) / 2);

			ll idx = 0, cnt = 0;

			ll val = 0;

			while (idx < n && cnt < m) {

				val += (ll) v[idx];

				if (val > mid) {
					cnt++;
					val = 0;
				} else if (val == mid) {
					cnt++;
					val = 0;
					idx++;
				} else {
					idx++;
				}
			}

			if (cnt <= m && idx >= n) {
				end = mid;
			} else {
				st = mid;
			}
		}

		ll idx = 0, cnt = 0;

		ll val = 0;

		while (idx < n && cnt < m) {

			val += (ll) v[idx];

			if (val > st) {
				cnt++;
				val = 0;
			} else if (val == st) {
				cnt++;
				val = 0;
				idx++;
			} else {
				idx++;
			}
		}

		if (cnt <= m && idx >= n) {
			return st;
		}

		return end;
	}
};