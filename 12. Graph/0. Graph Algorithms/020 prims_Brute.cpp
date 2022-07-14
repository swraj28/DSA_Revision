#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N^2). Going through N Node for N-1 times

	Space Complexity: O(N). 3 arrays of size N
*/

int main() {
	int N = 5, m = 6;
	vector<pair<int, int> > adj[N];


	adj[0].push_back({1, 2});
	adj[0].push_back({3, 6});
	adj[1].push_back({0, 2});
	adj[1].push_back({2, 3});
	adj[1].push_back({3, 8});
	adj[1].push_back({4, 5});
	adj[2].push_back({1, 3});
	adj[2].push_back({4, 7});
	adj[3].push_back({0, 6});
	adj[3].push_back({1, 8});
	adj[4].push_back({1, 5});
	adj[4].push_back({2, 7});

	int parent[N]; // To trace back the tree .
	int Weight[N];
	bool mstSet[N];

	for (int i = 0; i < N; i++) {
		Weight[i] = INT_MAX, mstSet[i] = false;
	}

	Weight[0] = 0;
	parent[0] = -1;
	int ansWeight = 0;

	for (int count = 0; count < N - 1; count++) {

		int mini = INT_MAX, u;

		for (int v = 0; v < N; v++) {

			if (mstSet[v] == false && Weight[v] < mini) {
				mini = Weight[v], u = v;
			}
		}

		mstSet[u] = true;

		for (auto it : adj[u]) {

			int v = it.first;
			int weight = it.second;

			if (mstSet[v] == false && weight < Weight[v]) {
				parent[v] = u, Weight[v] = weight;
			}
		}

	}


	for (int i = 1; i < N; i++) {
		cout << parent[i] << " - " << i << " \n";
	}

	return 0;
}