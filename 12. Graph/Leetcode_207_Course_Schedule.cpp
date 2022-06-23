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

	bool dfs(int src, vector<int> gr[], vector<int> &visited, vector<int> &stack) {
		visited[src] = 1;
		stack[src] = 1;

		for (auto nbr : gr[src]) {
			if (!visited[nbr]) {
				bool cycle_mila = dfs(nbr, gr, visited, stack);
				if (cycle_mila) {
					return true;
				}
			} else if (stack[nbr] == 1) {
				return true;
			}
		}

		stack[src] = 0;

		return false;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

		vector<int> stack(numCourses, 0);
		vector<int> visited(numCourses, 0);

		vector<int> gr[numCourses];

		int m = prerequisites.size();

		for (int i = 0; i < m; i++) {
			int x = prerequisites[i][0];
			int y = prerequisites[i][1];

			gr[x].push_back(y);
		}

		for (int i = 0; i < numCourses; i++) {
			if (!visited[i]) {
				if (dfs(i, gr, visited, stack)) {
					return false;
				}
			}
		}

		return true;


	}
};