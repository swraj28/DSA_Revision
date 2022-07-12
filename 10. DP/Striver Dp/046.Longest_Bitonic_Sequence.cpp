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

int longestBitonicSequence(vector<int>& nums, int n) {

	// The key idea is to find lis and lds

	vector<int> lis(n);
	lis[0] = 1;

	for (int i = 1; i < n; i++) { // Longest Increasing Subsequence Ending at i

		lis[i] = 1;

		for (int j = i - 1; j >= 0; j--) {
			if (nums[j] >= nums[i]) {
				continue;
			}

			lis[i] = max(lis[i], lis[j] + 1);
		}
	}

	vector<int> lds(n, 0);
	lds[n - 1] = 1;

	for (int i = n - 2; i >= 0; i--) { // Longest Incrreasing Subsequnce Ending at i from end

		lds[i] = 1;

		for (int j = i + 1; j < n; j++) {
			if (nums[j] >= nums[i]) {
				continue;
			}

			lds[i] = max(lds[i], lds[j] + 1);
		}
	}

	int mx = (lis[0] + lds[0]) - 1;

	for (int i = 1; i < n; i++) {
		mx = max({mx, (lis[i] + lds[i]) - 1});
	}

	return mx;
}
