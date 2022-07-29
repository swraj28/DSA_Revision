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

int countPlatforms(int n, int arr[], int dep[]) {
	sort(arr, arr + n);
	sort(dep, dep + n);

	int ans = 1;
	int count = 1;
	int i = 1, j = 0;
	while (i < n && j < n)
	{
		if (arr[i] <= dep[j]) //one more platform needed
		{
			count++;
			i++;
		}
		else //one platform can be reduced
		{
			count--;
			j++;
		}
		ans = max(ans, count); //updating the value with the current maximum
	}

	return ans;
}

int findPlatform(int arr[], int dep[], int n) {

	return countPlatforms(n, arr, dep);
}