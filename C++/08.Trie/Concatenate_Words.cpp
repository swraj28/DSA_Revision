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

class node {
public:
	vector <node*> h;
	bool isTerminal;

	node() {
		this->h = vector<node*>(26, NULL);
		this->isTerminal = false;
	}
};

class Solution {
public:

	node* root = new node();

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

		temp->isTerminal = true;
	}

	bool recur(string &word, int n, int si, int concat_cnt) {
		if (si >= n) {
			return concat_cnt >= 2;
		}

		node*temp = root;
		for (int i = si; i < n; i++) {

			if (temp->h[word[i] - 'a'] == NULL) {
				return false;
			}

			temp = temp->h[word[i] - 'a'];

			if (temp->isTerminal == true) {

				bool rec_res = recur(word, n, i + 1, concat_cnt + 1);

				if (rec_res == true) {
					return true;
				}
			}
		}

		return false;
	}

	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

		int n = words.size();

		if (n <= 2) {
			return {};
		}

		for (auto &word : words) {
			insert(word);
		}

		vector<string> ans;

		for (auto &word : words) {
			if (recur(word, (int)word.length(), 0, 0)) {
				ans.pb(word);
			}
		}

		return ans;
	}
};