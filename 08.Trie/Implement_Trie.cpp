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

// Leetcode-208

class node {
public:
	vector <node*> h;
	bool isTerminal;

	node() {
		this->h = vector<node*>(26, NULL);
		this->isTerminal = false;
	}
};

class Trie {
	node* root;
public:
	Trie() {
		root = new node();
	}

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

	bool search(string word) {

		node* temp = root;

		for (int i = 0; i < word.length(); i++) {

			char ch = word[i];

			if (temp->h[ch - 'a'] != NULL) {
				temp = temp->h[ch - 'a'];
			} else {
				return false;
			}

		}

		return temp->isTerminal;
	}

	bool startsWith(string prefix) {

		node* temp = root;

		for (int i = 0; i < prefix.length(); i++) {

			char ch = prefix[i];

			if (temp->h[ch - 'a'] != NULL) {
				temp = temp->h[ch - 'a'];
			} else {
				return false;
			}
		}

		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */