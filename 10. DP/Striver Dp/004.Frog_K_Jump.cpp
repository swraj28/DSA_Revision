#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
const int mod = 1000000007;
#define fo1(i,a,b) for(int i=a;i<=b;i++)
#define deb(x) cout<<x<<"\n";
#define deB(x,y) cout<<x<<" "<<y<<"\n";
#define Deb(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define all(v) (v).begin(),(v).end()
#define mk(arr,n,type)  type *arr=new type[n];

int dp[100001];

int total_cost(int arr[], int n, int si, int k) {
	if (si == n - 1) {
		return 0;
	}

	if (dp[si] != -1) {
		return dp[si];
	}

	int ans = INT_MAX;

	for (int i = 1; i <= k; i++) {
		if (si + i < n) {
			int rec_res = abs(arr[si] - arr[si + i]) + total_cost(arr, n, si + i, k);
			ans = min(ans, rec_res);
		}
	}

	return dp[si] = ans;
}

// Iterative :-

int solveUtil(int n, vector<int>& height, vector<int>& dp, int k) {

	dp[0] = 0;

	for (int i = 1; i < n; i++) {

		int mmSteps = INT_MAX;

		for (int j = 1; j <= k; j++) {

			if (i - j >= 0) {

				int jump = dp[i - j] + abs(height[i] - height[i - j]);

				mmSteps = min(jump, mmSteps);
			}
		}

		dp[i] = mmSteps;
	}

	return dp[n - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	mk(arr, n, int);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << total_cost(arr, n, 0, k) << endl;

	return 0;
}