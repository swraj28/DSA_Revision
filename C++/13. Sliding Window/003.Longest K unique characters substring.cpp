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
	int longestKSubstr(string s, int k) {

		int n = s.length(), j = 0, mx = 0;

		int unique = 0;

		vector<int> cnt(256, 0);

		for (int i = 0; i < n; i++) {
			if (cnt[s[i]] == 0) {
				unique++;
			}

			cnt[s[i]]++;

			while (unique > k) {
				if (cnt[s[j]] == 1) {
					unique--;
				}

				cnt[s[j]]--;
				j++;
			}

			if (unique == k) {
				mx = max(mx, (i - j) + 1);
			}
		}

		return mx;
	}
};