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
	double myPow(double x, int n) {

		double ans = 1.0;

		if (n == 0) {
			return ans;
		}

		bool f = false;

		if (n < 0) {
			f = true;;
			n = abs(n);
		}

		while (n > 0) {
			if (n & 1) {
				ans *= (double)x;
			}

			x *= (double)x;
			n >>= 1;
		}

		if (f) {
			return (1.0 / ans);
		}

		return ans;
	}
};