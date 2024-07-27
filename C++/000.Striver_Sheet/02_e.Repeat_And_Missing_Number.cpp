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

// The brute force approach is simply sort the array and perform simple counting to find the result.

// Optimized Approach :- (using Bitmanipulation --> Similar to single number 3 leetcode)

int low_bit(int n) {
	int c = 0;
	while (n) {
		if (n & 1) {
			break;
		}
		c++;
		n >>= 1;
	}

	return (1 << c);
}

pair<int, int> missingAndRepeating(vector<int> &nums, int n) {

	int res = 0;

	for (int i = 0; i < n; i++) {
		res ^= nums[i];
	}

	for (int i = 1; i <= n; i++) {
		res ^= i;
	}


	//****************** Same as that of single number 3 logic **********************************

	int lb = low_bit(res);

	int p = 0, q = 0; //two containers;

	for (int i = 0; i < n; i++) {
		if (lb & nums[i]) {
			p ^= nums[i];
		} else {
			q ^= nums[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (lb & i) {
			p ^= i;
		} else {
			q ^= i;
		}
	}

	int p_cnt = 0;

	for (int i = 0; i < n; i++) {
		if (nums[i] == p) {
			p_cnt++;
		}
	}

	if (p_cnt == 2) {
		return {q, p};
	}

	return {p, q};
}
