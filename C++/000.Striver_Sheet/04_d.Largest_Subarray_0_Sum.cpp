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
	int solution(vector<int> & arr) {

		int n = arr.size();
		unordered_map<int, int> m;

		int sm = 0;

		int mx = INT_MIN;

		for (int i = 0; i < n; i++) {
			sm += arr[i];

			if (sm == 0) {
				mx = (i + 1);
				continue;
			}

			if (m.find(sm) != m.end()) {
				int len = (i - m[sm]);

				mx = max(mx, len);
			} else {
				m[sm] = i;
			}
		}

		return mx == INT_MIN ? 0 : mx;
	}

	int maxLen(vector<int>&A, int n) {
		return solution(A);
	}
};