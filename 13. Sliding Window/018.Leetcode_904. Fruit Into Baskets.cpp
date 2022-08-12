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
	int totalFruit(vector<int>& fruits) {

		int n = fruits.size();

		int type1 = -1, type2 = -1, type1_cnt = 0, type2_cnt = 0;

		int mx = 0, j = 0;

		for (int i = 0; i < n; i++) {

			if (type1 == -1 && (fruits[i] != type2)) {
				type1 = fruits[i];
			} else if (type2 == -1 && (fruits[i] != type1)) {
				type2 = fruits[i];
			}

			if (fruits[i] == type1) {
				type1_cnt++;
			} else if (fruits[i] == type2) {
				type2_cnt++;
			}

			// cout << type1 << " " << type2 << " "<<fruits[i]<<endl;

			if ((fruits[i] != type1) && (fruits[i] != type2)) {

				// cout << "*" << " " << i << endl;

				while ((type1_cnt > 0) && (type2_cnt > 0)) {
					if (fruits[j] == type1) {
						type1_cnt--;
					} else if (fruits[j] == type2) {
						type2_cnt--;
					}

					j++;
				}

				if (type1_cnt == 0) {
					type1 = fruits[i];
					type1_cnt++;
				} else if (type2_cnt == 0) {
					type2 = fruits[i];
					type2_cnt++;
				}
			}

			// cout << mx << " " << ((i - j) + 1) << endl;

			mx = max(mx, ((i - j) + 1));
		}

		return mx;
	}
};