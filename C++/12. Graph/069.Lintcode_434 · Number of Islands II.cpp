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

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:

	int find_parent(int v, vector<int> &parent) {
		if (v == parent[v]) {
			return v;
		}

		return parent[v] = find_parent(parent[v], parent);
	}

	vector<int> dx = { -1, 1, 0, 0}, dy = {0, 0, -1, 1};

	vector<int> numIslands2(int row, int col, vector<Point> &operators) {

		int n = (1e5 + 1);

		vector<int> parent(n);
		vector<int> sze(n);

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			sze[i] = 1;
		}

		int total = 0;

		vector<int> ans;

		for (auto &e : operators) {

			int i = e.x, j = e.y;

			int a = (i * col) + j;

			if (parent[a] == -1) {
				parent[a] = a;
				total += 1;
			}

			bool f = false;

			for (int k = 0; k < 4; k++) {

				int new_i = i + dx[k], new_j = j + dy[k];

				if (new_i < 0 || new_i >= row || new_j < 0 || new_j >= col) {
					continue;
				}

				int b = (new_i * col) + new_j;

				if (parent[b] == -1) {
					continue;
				}

				a = find_parent(a, parent);
				b = find_parent(b, parent);

				if (a == b) {
					continue;
				}

				if (sze[a] >= sze[b]) {
					parent[b] = a;
					sze[a] += sze[b];
				} else {
					parent[a] = b;
					sze[b] += sze[a];
				}

				total -= 1;

			}

			ans.pb(total);
		}

		return ans;
	}
};