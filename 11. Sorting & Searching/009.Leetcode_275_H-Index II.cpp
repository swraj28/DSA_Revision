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
	int hIndex(vector<int>& citations) {

		int n = citations.size();

		int st = -1, end = 1e3;

		while (st + 1 < end) {
			int mid = (st + (end - st) / 2); // The maximum h-index

			int idx = upper_bound(all(citations), mid - 1) - citations.begin();

			int cnt = (n - idx);

			if (cnt < mid) {
				end = mid;
			} else {
				st = mid;
			}
		}

		// cout << st << " " << end << endl;

		return st;
	}
};