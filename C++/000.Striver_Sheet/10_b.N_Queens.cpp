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
Time Complexity: Exponential in nature, since we are trying out all ways. To be precise it goes as O(N! * N) nearly.
Space Complexity: O(N^2)
*/

class Solution {
public:

	vector<vector<string>> ans;

	bool is_valid(vector<string> &v, int n, int row, int col) {

		for (int i = row - 1; i >= 0; i--) {
			if (v[i][col] == 'Q') {
				return false;
			}
		}

		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
			if (v[i][j] == 'Q') {
				return false;
			}
		}

		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
			if (v[i][j] == 'Q') {
				return false;
			}
		}

		return true;
	}

	void recur(vector<string> &v, int n, int row) {
		if (row >= n) {
			ans.pb(v);

			return;
		}

		for (int col = 0; col < n; col++) {
			if (is_valid(v, n, row, col)) {
				v[row][col] = 'Q';
				recur(v, n, row + 1);
				v[row][col] = '.'; // Backtrack
			}
		}
	}

	vector<vector<string>> solveNQueens(int n) {

		vector<string>v(n, std::string(n, '.'));

		recur(v, n, 0);

		return ans;
	}
};

// Optimization of the is_valid function

/*
	The number of columns is n, the number of 45° diagonals is 2 * n - 1, the number of 135° diagonals is also 2 * n - 1.
	When reach [row, col], the column No. is col, the 45° diagonal No. is row + col and the 135° diagonal No. is n - 1 + col - row.
	We can use three arrays to indicate if the column or the diagonal had a queen before, if not, we can put a queen in this position and continue.
*/

/*
  *    | | |                / / /             \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / /                 \ \ \
  *   3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)
*/

class Solution {
public:
	std::vector<std::vector<std::string> > solveNQueens(int n) {

		std::vector<std::vector<std::string> > res;

		std::vector<std::string> nQueens(n, std::string(n, '.'));

		std::vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);

		solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);

		return res;
	}
private:
	void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag_col, std::vector<int> &flag_45, std::vector<int> &flag_135, int row, int &n) {
		if (row == n) {
			res.push_back(nQueens);
			return;
		}

		for (int col = 0; col != n; ++col) {
			if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {

				flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;

				nQueens[row][col] = 'Q';

				solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);

				nQueens[row][col] = '.'; // Backtracking.

				flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1; // Backtracking.
			}
		}
	}
};