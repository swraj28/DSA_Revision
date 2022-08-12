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
	int numberOfSubstrings(string s) {

		int n = s.length();

		int total = 0, j = 0;

		int c_a = 0, c_b = 0, c_c = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == 'a') {
				c_a++;
			} else if (s[i] == 'b') {
				c_b++;
			} else {
				c_c++;
			}

			while (c_a > 0 && c_b > 0 && c_c > 0) {
				total += (n - i);

				if (s[j] == 'a') {
					c_a--;
				} else if (s[j] == 'b') {
					c_b--;
				} else {
					c_c--;
				}

				j++;
			}
		}

		return total;
	}
};