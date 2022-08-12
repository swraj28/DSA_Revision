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
	int findLengthOfShortestSubarray(vector<int>& arr) {

		if (is_sorted(all(arr))) {
			return 0;
		}

		int n = arr.size();

		int i;

		for (i = 1; i < n; i++) {
			if (arr[i] < arr[i - 1]) {
				break;
			}
		}

		int j;

		for (j = n - 2; j >= 0; j--) {
			if (arr[j] > arr[j + 1]) {
				break;
			}
		}

		int mn = INT_MAX;

		for (int k = n - 1; k > j; k--) {

			int idx = upper_bound(arr.begin(), arr.begin() + i, arr[k]) - arr.begin();
			idx--;

			int d = (k - idx) - 1;

			if (d >= 0) {
				mn = min(mn, d);
			}
		}

		mn = min({mn, (n - i), j + 1});

		return mn ;
	}
};