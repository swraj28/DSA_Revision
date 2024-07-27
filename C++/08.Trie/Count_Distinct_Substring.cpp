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

void insert(string &word, node* root, int &cnt) {

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

    if (temp->isTerminal == false) {
        cnt++;
    }

    temp->isTerminal = true;
}

int countDistinctSubstrings(string &s) {

    int n = s.length();

    int cnt = 0;

    node* root = new node();

    for (int i = 0; i < n; i++) {
        string word = "";
        for (int j = i; j < n; j++) {
            word += s[j];

            insert(word, root, cnt);
        }
    }

    return cnt + 1;
}