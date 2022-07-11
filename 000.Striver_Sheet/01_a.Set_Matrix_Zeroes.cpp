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

// The Key Idea is to use the first row and first column to mark up the presence of zero.

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {

		int n = matrix.size(), m = matrix[0].size();

		bool f = false, f1 = false, f2 = false; // The flag 'f' will get true only if matrix[0][0] will be zero

		if (matrix[0][0] == 0) {
			f = true;
		}

		for (int i = 1; i < n; i++) {
			if (matrix[i][0] == 0) {
				f1 = true;
				break;
			}
		}

		for (int j = 1; j < m; j++) {
			if (matrix[0][j] == 0) {
				f2 = true;
				break;
			}
		}

		// We wil use the first row and first column to store wheathere the specific row or specific column will get zero or not.

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < n; i++) {
			if (matrix[i][0] == 0) {
				for (int j = 0; j < m; j++) {
					matrix[i][j] = 0;
				}
			}
		}

		for (int j = 1; j < m; j++) {
			if (matrix[0][j] == 0) {
				for (int i = 0; i < n; i++) {
					matrix[i][j] = 0;
				}
			}
		}

		if (f) {
			for (int i = 0; i < n; i++) {
				matrix[i][0] = 0;
			}

			for (int j = 0; j < m; j++) {
				matrix[0][j] = 0;
			}
		} else {
			if (f1) {
				for (int i = 0; i < n; i++) {
					matrix[i][0] = 0;
				}
			}

			if (f2) {
				for (int j = 0; j < m; j++) {
					matrix[0][j] = 0;
				}
			}
		}
	}
};