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
	char ch;
	unordered_map<char, node*> h;
	bool isTerminal;

	node(char ch) {
		this->ch = ch;
		this->isTerminal = false;
	}
};

class WordDictionary {
public:
	WordDictionary() {

	}

	node* root = new node('\0');

	void addWord(string word) {

		node* temp = root;

		for (int i = 0; i < word.length(); i++) {

			char ch = word[i];

			if (temp->h.count(ch)) {
				temp = temp->h[ch];
			} else {
				node* child = new node(ch);
				temp->h[ch] = child;
				temp = temp->h[ch];
			}
		}

		temp->isTerminal = true;
	}

	bool dfs(string word, node* temp, int pos) {

		if (pos == word.size()) {

			return temp->isTerminal;
		}

		char ch = word[pos];

		if (ch != '.') {
			if (temp->h.count(ch)) {
				bool rec_res = dfs(word, temp->h[ch], pos + 1);

				if (rec_res == true) {
					return true;
				}
			}

			return false;
		}

		for (int i = 0; i < 26; i++) {
			char ch1 = 'a' + i;

			if (temp->h.count(ch1)) {

				bool rec_res = dfs(word, temp->h[ch1], pos + 1);

				if (rec_res == true) {
					return true;
				}
			}
		}

		return false;
	}

	bool search(string word) {

		node* temp = root;

		return dfs(word, temp, 0);
	}
};