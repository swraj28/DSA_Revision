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


// https://leetcode.ca/all/1059.html  -->Look at this link for proper explanation of the question

// Problem Link :- https://www.codingninjas.com/codestudio/problems/all-paths-from-source-lead-to-destination_1376425

/*
  Approach:-
  All the paths starting from node ‘SRC’ eventually end at node ‘DEST’ if -:
	1.Node ‘DEST’ is reachable from ‘SRC’.
	2.There is no outgoing edge from node ‘DEST’.
	3.No cycle is reachable from ‘SRC’.
*/

void dfs(int src, int &dest, vector<int>& visited, vector<int> &stack, vector<int> gr[], bool &ans) {

	if (ans == false) {
		return;
	}

	visited[src] = 1;
	stack[src] = 1;

	for (auto &nbr : gr[src]) {
		if (stack[nbr]) {
			ans = false;
			return;
		}

		if (!visited[nbr]) {
			dfs(nbr, dest, visited, stack, gr, ans);
		}
	}

	stack[src] = 0;

	if (src != dest && gr[src].size() == 0) {
		ans = false;
	}
}

bool leadsToDestination(int n, int m, int src, int dest, vector<vector<int>> &edges) {

	vector<int> gr[n];

	for (auto &e : edges) {

		gr[e[0]].pb(e[1]);
	}

	if (gr[dest].size()) {
		return false;
	}

	bool ans = true;

	vector<int> visited(n, 0);

	vector<int> stack(n, 0);

	dfs(src, dest, visited, stack, gr, ans);

	return ans;
}