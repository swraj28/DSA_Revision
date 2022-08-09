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
	int kthSmallest(vector<vector<int>>& matrix, int k) {

		int n = matrix.size();

		int st = matrix[0][0] - 1, end = matrix[n - 1][n - 1];

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2);

			int cnt = 0;

			for (int i = 0; i < n; i++) {

				int idx = upper_bound(all(matrix[i]), mid) - matrix[i].begin();
				cnt += idx;
			}

			if (cnt >= k) {
				end = mid;
			} else {
				st = mid;
			}
		}

		// cout << st << " " << end << endl;

		return end;
	}
};