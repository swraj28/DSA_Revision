#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define PI 3.1415926535897932384626
#define mod 1000000007
#define mod1 998244353
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define deb(x) cout<<x<<"\n";
#define deB(x,y) cout<<x<<" "<<y<<"\n";
#define Deb(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define mk(arr,n,type)  type *arr=new type[n];
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
// cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)

/*-------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
/*--------------------------------------------------------------------------------------------*/

/*
      Some Important Observation:-

      1.It is worth noting that reversing a subarray of odd length is not going to increase the sum on even positions.
      2.Only Reversing a even length subarray of the array will lead to increase the overall sum on the even positions.

      3. We need to understand that the even length subarray which will maximize the overall sum at the even position may start from the odd index or from the even index.

      4. If we observe carefully reversing an even length array.
         3,4,5,6 --> Currently the sum of even positions elements= 3+5=8

         After Reversal:- 6,5,4,3 --> The sum of even positions elements 6+4=10.

         The Increment in the sum if we observe carefully is the overall sum of differece of element of (odd_Position-even_Positions) that subarry which yied maximum sum.
         We can find that subarray using Kadane's Algo .
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		ll mx_sm = 0;
		mk(arr, n, ll);

		for (ll i = 0; i < n; i++) {
			cin >> arr[i];

			if (i % 2 == 0) {
				mx_sm += (ll) arr[i];
			}
		}

		ll c_max = 0, mx = 0;

		// Even Position:-

		for (ll i = 0; i < n - 1; i += 2) {

			ll d = (arr[i + 1] - arr[i]);

			c_max = max(d, c_max + (ll) d);
			mx = max(mx, c_max);
		}


		// Odd Positions:-

		c_max = 0;
		ll mx1 = 0;

		for (ll i = 1; i < n - 1; i += 2) {

			ll d = (arr[i] - arr[i + 1]);

			c_max = max(d, c_max + (ll) d);
			mx1 = max(mx1, c_max);
		}

		cout << mx_sm + max(mx, mx1) << endl;
	}

	return 0;
}