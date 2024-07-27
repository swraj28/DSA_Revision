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

// T.c:- O(2^n)--> The worst case complexity will occur when all the characters are letters therefore we have 2 possiblities each

// Best case:- When all the character are digit

// Space :- O(n)--> Recursive Call Stack

class Solution {
public:
    vector<string> v;

    void recur(string s, string ans) {

        if (s.length() == 0) {
            v.push_back(ans);
            return;
        }

        char ch = s[0];
        string ros = s.substr(1);

        if (isdigit(ch)) {
            recur(ros, ans + ch);
        } else if (islower(ch)) {
            recur(ros, ans + ch);
            ch = toupper(ch);
            recur(ros, ans + ch);
        } else {
            recur(ros, ans + ch);
            ch = tolower(ch);
            recur(ros, ans + ch);
        }
    }

    vector<string> letterCasePermutation(string s) {

        recur(s, "");

        return v;
    }
};