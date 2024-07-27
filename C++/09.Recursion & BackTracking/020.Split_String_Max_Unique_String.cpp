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

// T.c:- O(2^n)

// S.c:- O(n)

class Solution {
public:

	void recur(string &s, int n, int si, vector<string> &v, unordered_set<string> &st, int &mx) {
		if (si >= n) {
			int x = v.size();
			mx = max(mx, x);

			return;
		}

		for (int i = si; i < n; i++) {

			string temp = s.substr(si, (i - si) + 1);

			if (st.count(temp) == 0) {
				st.insert(temp);
				v.pb(temp);

				recur(s, n, i + 1, v, st, mx);

				string x = v[v.size() - 1];
				st.erase(st.find(x));
				v.pop_back();
			}
		}
	}

	int maxUniqueSplit(string s) {

		int n = s.length();

		int mx = 0;
		vector<string> v;

		unordered_set<string> st;

		recur(s, n, 0, v, st, mx);

		return mx;
	}
};