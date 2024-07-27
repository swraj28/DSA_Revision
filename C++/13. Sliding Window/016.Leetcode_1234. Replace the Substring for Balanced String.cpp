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
	int balancedString(string s) {

		int n = s.length();
		unordered_map<char, int> m;

		m['Q'] = 0, m['W'] = 0, m['E'] = 0, m['R'] = 0;

		for (int i = 0; i < n; i++) {
			m[s[i]]++;
		}

		int req = (n / 4);

		m['Q'] -= req, m['W'] -= req, m['E'] -= req, m['R'] -= req;

		m['Q'] = max(m['Q'], 0);
		m['W'] = max(m['W'], 0);
		m['E'] = max(m['E'], 0);
		m['R'] = max(m['R'], 0);

		if (m['Q'] == 0 && m['W'] == 0 && m['E']  == 0 && m['R'] == 0) {
			return 0;
		}

		int j = 0, mn = n;

		int q_c = 0, w_c = 0, e_c = 0, r_c = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == 'Q') {
				q_c++;
			} else if (s[i] == 'W') {
				w_c++;
			} else if (s[i] == 'E') {
				e_c++;
			} else {
				r_c++;
			}

			while (q_c >= m['Q'] && w_c >= m['W'] && e_c >= m['E'] && r_c >= m['R']) {
				mn = min(mn, (i - j) + 1);

				if (s[j] == 'Q') {
					q_c--;
				} else if (s[j] == 'W') {
					w_c--;
				} else if (s[j] == 'E') {
					e_c--;
				} else {
					r_c--;
				}

				j++;
			}
		}

		return mn;
	}
};