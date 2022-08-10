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

// Error :-

class Solution {
public:

	//recursive implementation
	ll LcmOfArray(vector<ll> arr, int idx) {
		// lcm(a,b) = (a*b/gcd(a,b))
		if (idx == arr.size() - 1) {
			return arr[idx];
		}
		int a = arr[idx];
		int b = LcmOfArray(arr, idx + 1);
		return (a * (ll) b / __gcd(a, b)); // __gcd(a,b) is inbuilt library function
	}

	int nthUglyNumber(int n, int a, int b, int c) {

		ll st = 1, end = (1e18);

		ll lcm = LcmOfArray({(ll)a, (ll) b, (ll) c}, 0);

		while (st + 1 < end) {

			ll mid = (st + (end - st) / 2);

			ll cnt = 0;

			cnt += (ll)(mid / a);
			cnt += (ll)(mid / b);
			cnt += (ll)(mid / c);
			cnt -= (ll)(mid / ((a * (ll) b) / __gcd(a, b))); // Division is done by lcm
			cnt -= (ll)(mid / ((b * (ll) c) / __gcd(b, c))); // Division is done by lcm
			cnt -= (ll)(mid / ((c * (ll) a) / __gcd(a, c))); // Division is done by lcm
			// cnt += (ll)(mid / ((a * (ll) b * (ll) c) / __gcd(a, __gcd(b, c)))); // Wrong

			cnt += (ll)(mid / lcm);

			if (cnt >= n) {
				end = mid;
			} else {
				st = mid;
			}
		}

		// cout << st << " " << end << endl;

		ll cnt = 0;

		cnt += (ll)(st / a);
		cnt += (ll)(st / b);
		cnt += (ll)(st / c);
		cnt -= (ll)(st / ((a * (ll) b) / __gcd(a, b))); // Division is done by lcm
		cnt -= (ll)(st / ((b * (ll) c) / __gcd(b, c))); // Division is done by lcm
		cnt -= (ll)(st / ((c * (ll) a) / __gcd(a, c))); // Division is done by lcm
		// cnt += (ll)(st / ((a * (ll) b * (ll) c) / __gcd(a, __gcd(b, c))));  // Wrong

		cnt += (ll)(st / lcm);



		if (cnt >= n) {
			return st;
		}

		return end;
	}
};

// Similar Logic :-

class Solution {
public:
	int nthUglyNumber(int k, int A, int B, int C) {
		int st = 1, end = 2 * (int) 1e9;
		long a = long(A), b = long(B), c = long(C);
		long ab = a * b / __gcd(a, b);
		long bc = b * c / __gcd(b, c);
		long ac = a * c / __gcd(a, c);
		long abc = a * bc / __gcd(a, bc);
		while (st < end) {
			int mid = st + (end - st) / 2;
			int cnt = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc; // (a U b U c)
			if (cnt < k) {
				st = mid + 1;
			} else {
				//the condition: F(N) >= k
				end = mid;
			}
		}
		return st;
	}
};