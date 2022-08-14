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

// dfs (Exponential Complexity)

class Solution {
public:

	void recur(string beginWord, string endWord, unordered_map<string, set<string>> &gr, vector<string> &path, vector<vector<string>> &ans) {

		path.pb(beginWord);

		if (beginWord == endWord) {
			ans.pb(path);
			return;
		}

		for (auto &nbr : gr[beginWord]) {

			recur(nbr, endWord, gr, path, ans);

			string x = path.back();
			path.pop_back();
		}
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

		recur(beginWord, endWord, gr, path, ans);

		return ans;
	}
};

// BFS:-

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

		unordered_set<string> wordSet(all(wordList));
		wordSet.erase(beginWord);

		vector<vector<string>> ans;

		queue<vector<string>> q;
		q.push({beginWord});

		unordered_set<string> visited;

		while (!q.empty()) {

			unordered_set<string> curLayer;

			int sze = q.size();

			while (sze--) {

				vector<string> curList = q.front();
				q.pop();

				string lastWord = curList[curList.size() - 1];

				if (lastWord == endWord) {
					ans.pb(curList);
				}

				for (int i = 0; i < lastWord.length(); i++) {
					char ch1 = lastWord[i];
					for (char ch = 'a'; ch <= 'z'; ch++) {

						lastWord[i] = ch;

						if (wordSet.count(lastWord) && visited.count(lastWord) == 0) {
							vector<string> newList = curList;
							newList.pb(lastWord);
							q.push(newList);
							curLayer.insert(lastWord);
						}
					}

					lastWord[i] = ch1;
				}
			}

			visited.insert(all(curLayer));
		}

		return ans;
	}
};