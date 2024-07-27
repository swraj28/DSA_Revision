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

int fib(int n) {
	if (n == 1 or n == 0) {
		return n;
	}

	int fibn1 = fib(n - 1);
	int fibn2 = fib(n - 2);

	int fibn = fibn1 + fibn2;
	return fibn;
}

int fibMemo(int n, int dp[]) {
	if (n == 1 or n == 0) {
		dp[n] = n;
		return n;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int fibn1 = fibMemo(n - 1, dp);
	int fibn2 = fibMemo(n - 2, dp);

	int fibn = fibn1 + fibn2;

	dp[n] = fibn;

	for (int i = 0; i <= 5; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "*******************" << endl;

	return fibn;
}

int fibPureDP(int n) {
	int dp[n + 1];

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}
//bottom up approach with space optimization

int fibospaceopt(int n)  //space_complexity-o(1);
{
	if (n == 0 or n == 1)
	{
		return n;
	}

	int a = 0;
	int b = 1;
	int c;

	for (int i = 2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}