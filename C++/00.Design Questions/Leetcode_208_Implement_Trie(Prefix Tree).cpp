#include    <iostream>
#include    <string>
#include    <algorithm>
#include    <map>
#include    <unordered_map>
#include    <vector>
#include    <set>
#include    <list>
#include    <iomanip>
#include    <queue>
#include    <stack>
#include    <math.h>
#include    <climits>
#include    <bitset>
#include    <cstring>
#include    <numeric>
#include    <array>
#include    <deque>
#include    <cstdlib>
#include    <cstdio>
#include    <stdlib.h>
#include    <cerrno>
#include    <ctime>
#include    <unordered_set>
#include    <cstring>
#include    <cmath>
#include    <random>
#include    <functional>
#include    <cassert>
#include    <bitset>
#include    <chrono>
 
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define PI 3.1415926535897932384626
#define mod 1000000007
#define mod1 998244353
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()


/*-------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
/*--------------------------------------------------------------------------------------------*/

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

class Trie {
	node* root;
public:
	Trie() {
		root = new node('\0');  // Initializing a Trie with a Null Character ... 
	}

	void insert(string word) {

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

	bool search(string word) {

		node* temp = root;

		for (int i = 0; i < word.length(); i++) {

			char ch = word[i];

			if (temp->h.count(ch)) {
				temp = temp->h[ch];
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

			if (temp->h.count(ch)) {
				temp = temp->h[ch];
			} else {
				return false;
			}
		}

		return true;
	}
};