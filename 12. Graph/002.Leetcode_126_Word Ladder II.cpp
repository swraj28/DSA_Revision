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

// Watch Tech Dose Videos for Analysing the Time Complexity:-

class Solution {
public:

	// Exponential Complexity :-

	// void dfs(string beginWord, string &endWord, unordered_map<string, set<string>> &gr, vector<string> &path, vector<vector<string>> &ans) {

	// 	path.pb(beginWord);

	// 	if (beginWord == endWord) {
	// 		ans.pb(path);
	// 		return;
	// 	}

	// 	for (auto &nbr : gr[beginWord]) {

	// 		dfs(nbr, endWord, gr, path, ans);

	// 		path.pop_back();
	// 	}
	// }

	int isNotVisited(string x, vector<string>& path) {

		int size = path.size();
		for (int i = 0; i < size; i++) {
			if (path[i] == x) {
				return 0;
			}
		}

		return 1;
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

		unordered_set<string> s;

		for (auto & itr : wordList) {
			s.insert(itr);
		}

		unordered_map<string, set<string>> gr;

		//**************************************************************************************//

		unordered_map<string, int> level;
		queue<string> q;
		q.push(beginWord);

		level[beginWord] = 0;

		while (!q.empty()) {

			auto src = q.front();
			q.pop();

			auto node = src;

			for (int i = 0; i < node.length(); i++) {

				char ch = node[i];

				for (int j = 0; j < 26; j++) {
					char ch1 = ('a' + j);

					node[i] = ch1;

					if (s.find(node) != s.end()) {
						if (level.count(node) == 0) {
							level[node] = 1 + level[src];
							gr[src].insert(node);
							q.push(node);
						} else if (level[node] == (1 + level[src])) {
							gr[src].insert(node);
						}
					}
				}

				node[i] = ch;
			}
		}

		//**************************************************************************************//

		// for (auto &src : gr) {
		// 	cout << src.ff << "->";
		// 	for (auto &nbr : src.ss) {
		// 		cout << nbr << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		vector<string> path;
		vector<vector<string>> ans;

		// dfs(beginWord, endWord, gr, path, ans);

		queue<vector<string>> q1;
		path.pb(beginWord);

		q1.push(path);

		while (!q.empty()) {

			path = q1.front();
			q1.pop();

			string last = path[path.size() - 1];

			if (last == endWord) {
				ans.pb(path);
				continue;
			}

			for (auto &nbr : gr[last]) {
				if (isNotVisited(nbr, path)) {
					vector<string> newPath(path);
					newPath.pb(nbr);

					q1.push(newPath);
				}
			}
		}

		return ans;
	}
};