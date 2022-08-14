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

	//find the number of total components and subtract the total node from it.

	int find_parent(int v, vector<int> &parent) {
		if (v == parent[v]) {
			return v;
		}

		return parent[v] = find_parent(parent[v], parent);
	}

	int removeStones(vector<vector<int>>& stones) {

		vector<int> parent(20001, 0);
		vector<int> sze(20001, 0);

		for (int i = 0; i <= 20000; i++) {
			parent[i] = i;
			sze[i] = 0;
		}

		for (auto s : stones) {

			int a = find_parent(s[0], parent);
			int b = find_parent(s[1] + 10000, parent);

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
		}

		set<int> st;

		for (auto s : stones) {
			int par = find_parent(s[0], parent);
			st.insert(par);
		}

		return stones.size() - st.size();
	}
};