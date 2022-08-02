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

// Similar to Matrix Median

int kthElement(int arr1[], int arr2[], int n, int m, int k) {

	int st = min(arr1[0], arr2[0]);
	int end = max(arr1[n - 1], arr2[m - 1]);

	while (st + 1 < end) {

		int mid = (st + (end - st) / 2);

		int cnt = 0;

		cnt += upper_bound(arr1, arr1 + n, mid) - arr1;
		cnt += upper_bound(arr2, arr2 + m, mid) - arr2;

		if (cnt >= k) {
			end = mid;
		} else {
			st = mid;
		}
	}

	int cnt = 0;

	cnt += upper_bound(arr1, arr1 + n, st) - arr1;
	cnt += upper_bound(arr2, arr2 + m, st) - arr2;

	if (cnt == k) {
		return st;
	}

	return end;
}