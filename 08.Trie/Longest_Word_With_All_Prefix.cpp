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

void insert(string &word, node* root) {

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

bool search(string word, node* root) {

    node* temp = root;

    for (int i = 0; i < word.length(); i++) {

        char ch = word[i];

        if (temp->h[ch - 'a'] != NULL && temp->h[ch - 'a']->isTerminal == true) {
            temp = temp->h[ch - 'a'];
        } else {
            return false;
        }

    }

    return temp->isTerminal;
}

string completeString(int n, vector<string> &a) {

    node* root = new node();

    for (auto &word : a) {
        insert(word, root);
    }

    string ans = "";

    for (auto &word : a) {

        bool f = search(word, root);
        if (f) {
            if (word.length() > ans.length()) {
                ans = word;
            } else if (word.length() == ans.length() && word < ans) {
                ans = word;
            }
        }
    }

    return (ans == "") ? "None" : ans;
}