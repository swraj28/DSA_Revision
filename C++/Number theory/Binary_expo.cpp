#include    <iostream>
#include    <string>
#include    <algorithm>
#include    <map>
#include    <unordered_map>
#include    <vector>
#include    <set>
#include    <list>
#include    <iomanip>
#include    <queue>
#include    <stack>
#include    <math.h>
#include    <climits>
#include    <bitset>
#include    <cstring>
#include    <numeric>
#include    <array>
#include    <deque>
#include    <cstdlib>
#include    <cstdio>
#include    <stdlib.h>
#include    <cerrno>
#include    <ctime>
#include    <unordered_set>
#include    <cstring>
#include    <cmath>
#include    <random>
#include    <functional>
#include    <cassert>
#include    <bitset>
#include    <chrono>
 
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define PI 3.1415926535897932384626
#define mod 1000000007
#define mod1 998244353
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define mk(arr,n,type)  type *arr=new type[n];

//Recursive approach for binary expo-(o(logb))
ll bin_expo_rec(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	ll res = bin_expo_rec(a, b / 2);

	if (b % 2) {
		return res * res * a;
	} else {
		return res * res;
	}
}

//Iterative approach for binary expo
ll bin_expo_itr(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res *= a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}

//Modular exponentation-((a^b)%m)
//((a*b)%m)=((a%m)*(b%m))%m
ll modular_expo(ll a, ll b) {
	a %= mod;
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res = res * a;
			res %= mod;
		}
		a = a * a;
		a %= mod;
		b >>= 1;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll a, b;
	cin >> a >> b;
	// cout << bin_expo_rec(a, b) << endl;
	// cout << bin_expo_itr(a, b) << endl;
	// cout << modular_expo(a, b) << endl;

	return 0;
}