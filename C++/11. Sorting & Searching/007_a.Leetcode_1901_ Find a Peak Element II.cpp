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

/*

The algorithm is as follows:

1.Pick the middle column.
2.Find the global maximum in the column.
3.If the row-neighbours of this element are smaller, then we found a 2D peak.
  Else, we recurse at the right-half of the matrix if the right-neighbour was bigger, and left-half of the matrix if the left-neighbour was bigger.


Here is a little intuition as to why this works:-

When we find a row-neighbour that is bigger than the global maximum of a column,
it means that the row-neighbour is bigger than all the elements of that column.
Thus, the global maximum of the neighbour's column must be bigger than its corresponding row-neighbour in our column.

--> We are trying to move to the largest element of the matrix.
*/

class Solution {
public:
	vector<int> findPeakGrid(vector<vector<int>>& mat) {

		int n = mat.size(), m = mat[0].size();

		int st = 0, end = (m - 1);

		while (st <= end) {

			int mid = (st + (end - st) / 2);

			int idx = -1, mx = INT_MIN;

			for (int i = 0; i < n; i++) {
				if (mat[i][mid] > mx) {
					mx = mat[i][mid];
					idx = i;
				}
			}

			// row--> idx and col--> mid.

			if ((mid == 0 || mat[idx][mid] > mat[idx][mid - 1]) && (mid == m - 1 || mat[idx][mid] > mat[idx][mid + 1]))
				return {idx, mid};
			else if (mid > 0 && mat[idx][mid - 1] > mat[idx][mid]) {
				end = mid - 1;
			} else {
				st = mid + 1;
			}
		}

		return { -1, -1};
	}
};