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

// O(row + col)

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		int n = matrix.size(), m = matrix[0].size();

		int st = 0, end = (m - 1);

		while (st < n && end >= 0) {

			if (matrix[st][end] == target) {
				return true;
			}

			if (matrix[st][end] > target) {
				end--;
			} else {
				st++;
			}
		}

		return false;
	}
};