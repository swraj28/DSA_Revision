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
	int find_parent(int v, vector<int> &parent) {
		if (v == parent[v]) {
			return v;
		}

		return parent[v] = find_parent(parent[v], parent);
	}

	vector<int> findRedundantConnection(vector<vector<int>>& edges) {

		int n = edges.size();
		vector<int> parent(n + 1);
		vector<int> sze(n + 1);

		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			sze[i] = 1;
		}

		vector<int> res;

		for (int i = 0; i < n; i++) {

			int a = edges[i][0];
			int b = edges[i][1];

			a = find_parent(a, parent);
			b = find_parent(b, parent);

			if (a == b) {
				res.pb(edges[i][0]);
				res.pb(edges[i][1]);
				break;
			}

			if (sze[a] >= sze[b]) {
				parent[b] = a;
				sze[a] += sze[b];
			} else {
				parent[a] = b;
				sze[b] += sze[a];
			}
		}

		return res;
	}
};