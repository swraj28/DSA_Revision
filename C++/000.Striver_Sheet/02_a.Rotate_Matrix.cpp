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

// Take the Transpose and reverse each row respectively.

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		int n = matrix.size(), m = matrix[0].size();

		for (int i = 0; i < n; i++) {
			for (int j = i; j < m; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}

		for (int i = 0; i < n; i++) {
			reverse(all(matrix[i]));
		}
	}
};