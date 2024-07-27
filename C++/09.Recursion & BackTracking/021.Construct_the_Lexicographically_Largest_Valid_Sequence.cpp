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

// Time: O(N!)
// Space: O(N)

class Solution {
public:

	bool recur(vector<int> &ans, vector<int> &visited, int si, int n) {

		if (si >= ans.size()) {
			return true;
		}

		if (ans[si]) {
			return recur(ans, visited, si + 1, n);
		}

		for (int i = n; i >= 1; i--) {

			if (visited[i] == 1) {
				continue;
			}

			if (i != 1 && (si + i >= ans.size() || ans[si + i])) {
				continue;
			}

			visited[i] = 1;
			ans[si] = i;

			if (i != 1) {
				ans[si + i] = i;
			}

			bool rec_res = recur(ans, visited, si + 1, n);

			if (rec_res == true) {
				return true;
			}

			// Backtracking

			visited[i] = 0;
			ans[si] = 0;
			if (i != 1) {
				ans[si + i] = 0;
			}
		}

		return false;
	}

	vector<int> constructDistancedSequence(int n) {

		vector<int> ans((2 * n) - 1, 0);
		vector<int> visited(n + 1, 0);

		recur(ans, visited, 0, n);

		return ans;
	}
};