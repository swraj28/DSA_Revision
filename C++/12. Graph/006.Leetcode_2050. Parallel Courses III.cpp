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
	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

		vector<int> gr[n];

		for (auto &r : relations) {
			gr[r[0] - 1].pb(r[1] - 1);
		}

		vector<int> visited(n , 0);
		vector<int> indegree(n , 0);

		for (int i = 0; i < n; i++) {

			for (auto &nbr : gr[i]) {
				indegree[nbr]++;
			}
		}

		queue<int> q;

		vector<int> dp(n, 0);

		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				dp[i] = time[i];
			}
		}

		while (q.size()) {

			int s = q.size();

			while (s--) {

				int node = q.front();
				q.pop();

				for (auto &nbr : gr[node]) {
					dp[nbr] = max(dp[node] + time[nbr], dp[nbr]);

					indegree[nbr]--;

					if (indegree[nbr] == 0) {
						q.push(nbr);
					}
				}
			}
		}

		return *max_element(all(dp));
	}
};