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
	int minSwaps(string s) {

		int n = s.length();

		int o_c = 0, z_c = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				z_c++;
			} else {
				o_c++;
			}
		}

		int d = abs(o_c - z_c);

		if (d > 1) {
			return -1;
		}

		string a = "", b = ""; // Try to generate the possible correct string and count the mismatch characters.

		a += '1';
		b += '0';

		for (int i = 1; i < n; i++) {
			if (i % 2) {
				a += '0';
				b += '1';
			} else {
				a += '1';
				b += '0';
			}
		}

		if (o_c == z_c) {

			int c_a = 0, c_b = 0;

			for (int i = 0; i < n; i++) {
				if (s[i] != a[i]) {
					c_a++;
				}

				if (s[i] != b[i]) {
					c_b++;
				}
			}

			c_a = min(c_a, c_b);

			return c_a / 2;
		}

		if (z_c > o_c) {
			a = b;
		}

		int c = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] != a[i]) {
				c++;
			}
		}

		return (c / 2);
	}
};