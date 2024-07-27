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

	int minCostBFS(int src, int dest, int n, vector<int> gr[]) {

		queue<int> q;
		vector<int> visited(n + 1, 0);
		vector<int> dist(n + 1, 0);

		q.push(src);
		visited[src] = 1;
		dist[src] = 0;

		while (!q.empty()) {

			int f = q.front();

			q.pop();

			for (int nbr : gr[f]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = 1;
					dist[nbr] = dist[f] + 1;
				}
			}
		}

		return dist[dest];
	}

	int min_dice_throws(int n, vector<pair<int, int> > snakes, vector<pair<int, int> > ladders) {

		vector<int> board(n + 1, 0);  // 1 based indexing

		//board to graph conversion (Very Very Important)

		for (auto sp : snakes) {
			int s = sp.first;
			int e = sp.second;
			board[s] = e - s;
		}

		for (auto lp : ladders) {
			int s = lp.first;
			int e = lp.second;
			board[s] = e - s;
		}

		//Graph
		vector<int> gr[n + 1];

		for (int u = 1; u < n; u++) {
			for (int dice = 1; dice <= 6; dice++) {
				int v = u + dice;
				if (v <= n) {
					v += board[v];
				}

				if (v <= n) {
					gr[u].pb(v);
				}
			}
		}

		// for (int i = 1; i <= n; i++) {
		// 	cout << i << "->";
		// 	for (auto &ele : gr[i]) {
		// 		cout << ele << " ";
		// 	}
		// 	cout << endl;
		// }

		// cout << endl;

		return minCostBFS(1, n, n, gr);
	}

	int snakesAndLadders(vector<vector<int>>& board) {

		int sze = board.size();

		int n = (sze * sze);

		int val = 1;

		bool f = true;

		vector<pair<int, int> > snakes;
		vector<pair<int, int> > ladders;

		for (int i = sze - 1; i >= 0; i--) {
			if (f) {
				for (int j = 0; j < sze; j++) {
					if (board[i][j] != -1) {
						if (board[i][j] > val) {
							ladders.pb({val, board[i][j]});
						} else {
							snakes.pb({val, board[i][j]});
						}
					}

					val += 1;
				}
				f = false;
			} else {
				for (int j = sze - 1; j >= 0; j--) {
					if (board[i][j] != -1) {
						if (board[i][j] > val) {
							ladders.pb({val, board[i][j]});
						} else {
							snakes.pb({val, board[i][j]});
						}
					}

					val += 1;
				}
				f = true;
			}
		}

		// for (auto &ele : snakes) {
		// 	cout << ele.ff << " " << ele.ss << endl;
		// }

		// cout << endl;

		// for (auto &ele : ladders) {
		// 	cout << ele.ff << " " << ele.ss << endl;
		// }

		// cout << endl;

		int ans = min_dice_throws(n, snakes, ladders);

		return (ans == 0) ? -1 : ans;
	}
};