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

int frogJump(int n, vector<int> &heights) {
    if (n <= 1) return 0;
    vector<int> dp(n + 1, 0);

    dp[2] = abs(heights[0] - heights[1]);

    for (int i = 3; i <= n; i++) {

        dp[i] = min({dp[i - 1] + abs(heights[i - 1] - heights[i - 2]), dp[i - 2] + abs(heights[i - 1] - heights[i - 3])});
    }

    return dp[n];
}