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

	int makeConnected(int n, vector<vector<int>>& connections) {

		vector<int> parent(n);
		vector<int> sze(n);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			sze[i] = 1;
		}

		int total_comp = n;
		int cycle = 0;

		for (int i = 0; i < connections.size(); i++) {

			int a = connections[i][0];
			int b = connections[i][1];

			a = find_parent(a, parent);
			b = find_parent(b, parent);

			if (a == b) {
				cycle++;
				continue;
			}

			total_comp -= 1;

			if (sze[a] >= sze[b]) {
				parent[b] = a;
				sze[a] += sze[b];
			} else {
				parent[a] = b;
				sze[b] += sze[a];
			}
		}

		total_comp -= 1;

		if (cycle >= total_comp) {
			return total_comp;
		}

		return -1;
	}
};