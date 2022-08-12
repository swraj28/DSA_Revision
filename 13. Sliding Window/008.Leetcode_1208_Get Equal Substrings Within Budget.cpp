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
	int equalSubstring(string s, string t, int maxCost) {

		int n = s.length(), j = 0, cost = 0;

		int mx = 0;

		for (int i = 0; i < n; i++) {

			cost += abs(s[i] - t[i]);

			while (cost > maxCost) {
				cost -= abs(s[j] - t[j]);
				j++;
			}

			mx = max(mx, (i - j) + 1);
		}

		return mx;
	}
};