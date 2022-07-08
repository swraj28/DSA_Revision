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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s, t;
	cin >> s >> t;

	int n = s.length();
	int m = s.length();

	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	string ans = "";

	int x = n, y = m;

	while (x > 0 and y > 0) {

		if (s[x - 1] == t[y - 1]) {
			ans += s[x - 1];
			x--, y--;
		} else if (dp[x - 1][y] >= dp[x][y - 1]) {
			x--;
		} else {
			y--;
		}
	}

	reverse(all(ans));

	cout << ans << endl;

	return 0;
}