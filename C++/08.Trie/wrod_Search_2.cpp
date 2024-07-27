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

class node {  // Structure of a Trie Node.
public:

	vector<node*> h;
	bool isTerminal;

	node() {
		this->isTerminal = false;
		this->h = vector<node*>(26, NULL);
	}
};

class Solution {
public:

	node* root = new node();  // Init. a Trie Node

	void insert(string word) {

		node* temp = root;

		for (int i = 0; i < word.length(); i++) {

			char ch = word[i];

			if (temp->h[ch - 'a'] != NULL) {
				temp = temp->h[ch - 'a'];
			} else {
				node* child = new node();
				temp->h[ch - 'a'] = child;
				temp = temp->h[ch - 'a'];
			}
		}

		temp->isTerminal = true;  // Termination of a Particular word.
	}

	int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

	void recur(vector<vector<char>> &board, int n, int m, int x, int y, node* root, string &word, unordered_set<string> &ans) {

		if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '.') {
			return;
		}

		if (root->h[(board[x][y]) - 'a'] != NULL) {

			char ch = board[x][y];
			board[x][y] = '.';

			word += ch;
			root = root->h[ch - 'a'];

			if (root->isTerminal) {
				ans.insert(word);
			}

			for (int i = 0; i < 4; i++) {
				recur(board, n, m, x + dx[i], y + dy[i], root, word, ans);
			}

			board[x][y] = ch; // backtrack
			word.pop_back();
		}
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

		for (auto & word : words) {
			insert(word);
		}

		int n = board.size(), m = board[0].size();

		node* temp = root;

		unordered_set<string> ans;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				string word = "";
				recur(board, n, m, i, j, temp, word, ans);
			}
		}

		vector<string> v;

		for (auto & it : ans) {
			v.pb(it);
		}

		return v;
	}
};