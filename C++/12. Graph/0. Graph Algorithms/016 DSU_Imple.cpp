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


/*
    A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.
    A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

	Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
	Union: Join two subsets into a single subset. Here first we have to check if the two subsets belong to same set. If no, then we cannot perform union.
*/

//Brute Force Implememtation:-

const int n = 101;
int parent[n];

struct brute {

	void make_set(int v) {
		parent[v] = v;
	}

	int find_par(int v) { // In worst case in one operation it may take o(n) time.
		if (v == parent[v]) {
			return v;
		}

		return find_par(parent[v]);
	}

	void union_sets(int a, int b) {
		a = find_par(a);
		b = find_par(b);
		if (a != b) {
			parent[b] = a;
		}
	}
};

//Optimized Implementation:-

struct optimized {

	int sze[n]; //Size of the Set
	int mn[n];	//Minimum element of the set
	int mx[n];	//Maximum Element Of the set

	void make_set(int v) {
		parent[v] = v;
		sze[v] = 1;
		mn[v] = v;
		mx[v] = v;
	}

	int find_par(int v) {  // log(n) for every query.  (n--> no. of nodes)

		if (v == parent[v]) {
			return v;
		}

		return parent[v] = find_par(parent[v]);
	}

	// Union By Size

	void union_sets(int a, int b) {

		a = find_par(a);
		b = find_par(b);

		if (a == b) { //Both are present in same set.
			return ;
		}

		if (a != b) {
			if (sze[a] >= sze[b]) {
				parent[b] = a;
				sze[a] += sze[b];
				mn[a] = min(mn[a], mn[b]);
				mx[a] = max(mx[a], mx[b]);
			} else {
				parent[a] = b;
				sze[b] += sze[a];
				mn[b] = min(mn[b], mn[a]);
				mx[b] = max(mx[b], mx[a]);
			}
		}
	}

	int size_of_set(int v) {
		return sze[find_par(v)];
	}

	int min_of_the_set(int v) {
		return mn[find_par(v)];
	}

	int max_of_the_set(int v) {
		return mx[find_par(v)];
	}
};

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//Here We are creating disjoint sets where each element represent their own cluster.

	struct optimized b;
	for (int i = 0; i < n; i++) {
		b.make_set(i);
	}

	b.union_sets(0, 1);
	b.union_sets(2, 3);
	b.union_sets(2, 0);
	b.union_sets(2, 4);
	b.union_sets(2, 5);

	cout << b.find_par(1) << endl;

	for (int i = 0; i < 7; i++) {
		cout << parent[i] << " ";
	}
	cout << endl;

	b.union_sets(6, 3);

	cout << b.find_par(1) << endl;

	for (int i = 0; i < 7; i++) {
		cout << parent[i] << " ";
	}
	cout << endl;

	return 0;
}