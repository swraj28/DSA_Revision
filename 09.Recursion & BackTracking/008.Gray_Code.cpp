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

// Watch Sumit Malik Lecture to understand the recurrence

class Solution {
public:

	vector<int> recur(int n) {
		if (n == 1) {
			return {0, 1};
		}

		vector<int> rec_res = recur(n - 1);

		vector<int> res = rec_res;

		for (int i = rec_res.size() - 1; i >= 0; i--) {

			int val = rec_res[i];
			val ^= (1 << (n - 1));

			res.pb(val);
		}

		return res;
	}

	vector<int> grayCode(int n) {
		if (n == 1) {
			return {0, 1};
		}

		return recur(n);
	}
};

// ith gray code is given as

int gray(int n) {
	return n ^ (n >> 1);
}