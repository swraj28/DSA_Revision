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

// Watch Striver Lecture to understand the concept:-

class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {

		int n = matrix.size(), m = matrix[0].size();

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (matrix[i][j] == 0) {
					continue;
				}

				int mn = min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});

				matrix[i][j] = (mn + 1);
			}
		}

		int total = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				total += matrix[i][j];
			}
		}

		return total;
	}
};