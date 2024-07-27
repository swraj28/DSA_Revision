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
    int cw, cp;

    node() {
        this->h = vector<node*>(26, NULL);
        this->cw = 0;
        this->cp = 0;
    }
};

class Trie {
    node* root;
public:
    Trie() {
        root = new node();
    }

    void insert(string &word) {

        node* temp = root;

        for (int i = 0; i < word.length(); i++) {

            char ch = word[i];

            if (temp->h[ch - 'a'] != NULL) {
                temp->cp += 1;
                temp = temp->h[ch - 'a'];
            } else {
                node* child = new node();
                temp->h[ch - 'a'] = child;
                temp->cp += 1;
                temp = temp->h[ch - 'a'];
            }
        }

        temp->cw += 1;
        temp->cp += 1;
    }

    int countWordsEqualTo(string &word) {

        node* temp = root;

        for (int i = 0; i < word.length(); i++) {

            char ch = word[i];

            if (temp->h[ch - 'a'] != NULL) {
                temp = temp->h[ch - 'a'];
            } else {
                return 0;
            }
        }

        return temp->cw;
    }

    int countWordsStartingWith(string &word) {

        node* temp = root;

        for (int i = 0; i < word.length(); i++) {

            char ch = word[i];

            if (temp->h[ch - 'a'] != NULL) {
                temp = temp->h[ch - 'a'];
            } else {
                return 0;
            }
        }

        return temp->cp;
    }

    void erase(string &word) {

        node* temp = root;

        for (int i = 0; i < word.length(); i++) {

            char ch = word[i];

            if (temp->h[ch - 'a'] != NULL) {
                temp->cp -= 1;
                temp = temp->h[ch - 'a'];
            } else {
                return;
            }
        }

        temp->cw -= 1;
        temp->cp -= 1;
    }
};