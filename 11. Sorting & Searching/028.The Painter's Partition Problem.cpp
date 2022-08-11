#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 10000003
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

class Solution {
public:
	long long minTime(int arr[], int n, int k) {

		int B = 1;
		int A = k;

		vector<int> C(n);

		for (int i = 0; i < n; i++) {
			C[i] = arr[i];
		}

		ll st = 1, end = (1e15);

		while (st + 1 < end) {

			ll mid = (st + (end - st) / 2); //minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board.

// 			cout<<mid<<endl;

			ll idx = 0, p_c = 0;

			ll val = 0;

			while (idx < n && p_c < A) {

				val += (ll)(C[idx] * (ll)B);

				if (val > mid) {
					p_c++;
					val = 0;
				} else if (val == mid) {
					p_c++;
					val = 0;
					idx++;
				} else {
					idx++;
				}
			}

			if (p_c <= A && idx >= n) {
				end = mid;
			} else {
				st = mid;
			}
		}

		ll idx = 0, p_c = 0;

		ll val = 0;

		while (idx < n && p_c < A) {

			val += (ll)(C[idx] * (ll)B);

			if (val > st) {
				p_c++;
				val = 0;
			} else if (val == st) {
				p_c++;
				val = 0;
				idx++;
			} else {
				idx++;
			}
		}

		if (p_c <= A && idx >= n) {
			return st;
		}

		return end;
	}
};