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
	int maxConsecutiveAnswers(string answerKey, int k) {

		int n = answerKey.size();

		int mx = 0, t_c = 0, f_c = 0, j = 0;

		for (int i = 0; i < n; i++) {

			if (answerKey[i] == 'T') {
				t_c++;
			} else {
				f_c++;
			}

			while (min(t_c, f_c) > k) {
				if (answerKey[j] == 'T') {
					t_c--;
				} else {
					f_c--;
				}

				j++;
			}
			mx = max(mx, (i - j) + 1);
		}

		return mx;
	}
};