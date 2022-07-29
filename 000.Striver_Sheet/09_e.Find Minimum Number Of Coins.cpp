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

int findMinimumCoins(int amount)  {

	vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

	int n = 9;

	int cnt = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (amount >= coins[i]) {

			int x = (amount / coins[i]);

			cnt += x;

			amount -= (x * coins[i]);
		}
	}

	return cnt;
}