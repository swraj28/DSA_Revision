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

class Solution {
public:

	bool check(vector<vector<char>> &board, char val, int x, int y) {

		for (int i = 0; i < 9; i++) { // Iterating over all the columns of that particualr row of (9*9) grid.
			if (board[x][i] == val) {
				return false;
			}
		}

		for (int i = 0; i < 9; i++) { // Iterating over all the rows of that particualr row of (9*9) grid.
			if (board[i][y] == val) {
				return false;
			}
		}

		int row = x - (x % 3), col = y - (y % 3); // Starting point of the subgrid

		for (int i = 0; i < 3; i++) {   // Iterating over the subgrid associated with that particular (x,y) of size (3*3).
			for (int j = 0; j < 3; j++) {
				if (board[row + i][col + j] == val) {
					return false;
				}
			}
		}

		return true;
	}

	bool recur(vector<vector<char>> &board, int x, int y) {
		if (x == 9) {
			return true;
		}

		if (y == 9) {
			return recur(board, x + 1, 0);
		}

		if (board[x][y] != '.') {
			return recur(board, x, y + 1);
		}

		for (int i = 1; i <= 9; i++) {

			if (check(board, (i + '0'), x, y)) {

				board[x][y] = (i + '0');

				bool rec_res = recur(board, x, y + 1);

				if (rec_res == true) {
					return true;
				}

				board[x][y] = '.';
			}
		}

		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {

		recur(board, 0, 0);
	}
};