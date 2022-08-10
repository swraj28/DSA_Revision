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

// Just Remember the fact that we don't need to minimize the heaters, we actually need to minimize the radius at which each heater is going to warm the house.

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {

		int n = houses.size(), m = heaters.size();

		sort(all(houses)), sort(all(heaters));

		int st = 0, end = (1e9);

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2); // Minimum radius required to cover every house

			bool f = true;

			for (int i = 0; i < n; i++) {

				int idx = lower_bound(all(heaters), (houses[i] - mid)) - heaters.begin(); // Minimum idx where heater needs to be placed.

				if (idx == m) { // if the index is out of bound then return false.
					f = false;
					break;
				}

				if ((houses[i] + mid) < heaters[idx]) {  // if the index is beyond the reach of the house then also return false.
					f = false;
					break;
				}
			}

			if (f) {
				end = mid;
			} else {
				st = mid;
			}
		}

		bool f = true;

		for (int i = 0; i < n; i++) {
			int idx = lower_bound(all(heaters), (houses[i] - st)) - heaters.begin();

			if (idx == m) {
				f = false;
				break;
			}

			if ((houses[i] + st) < heaters[idx]) {
				f = false;
				break;
			}
		}

		if (f) {
			return st;
		}

		return end;
	}
};