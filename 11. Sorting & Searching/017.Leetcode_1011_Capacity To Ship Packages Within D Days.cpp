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
	int shipWithinDays(vector<int>& weights, int days) {

		int n = weights.size();

		int st = 1, end = (1e7);

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2); // least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days

			int val = 0;

			int temp = 0;

			bool f = true;

			for (int i = 0; i < n; i++) {

				if (weights[i] > mid) {
					f = false;
					break;
				}

				if ((temp + weights[i]) <= mid) {
					temp += weights[i];
				} else {
					temp = weights[i];
					val++;
				}
			}

			if (f == false) {
				st = mid;
				continue;
			}

			if (temp) {
				val++;
			}

			if (val <= days) {
				end = mid;
			} else {
				st = mid;
			}
		}

		// cout<<st<<" "<<end<<endl;

		return end;
	}
};