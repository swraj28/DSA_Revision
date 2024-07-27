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


int n = 5, m = 4;//n-no of edges and m-no of vertices
int adj[6][6];
int arr[4][2]; //It stores the conection betwwen the vertices

void create_adj_matrix() {

	//initialize all the elements of adj list to zero
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			adj[i][j] = 0;
		}
	}
	//traverse through the edge array
	for (int i = 0; i < m; i++) {
		int x = arr[i][0];
		int y = arr[i][1];

		adj[x][y] = 1;
		adj[y][x] = 1; //bidierctional edges
	}
	//print the adj matrix
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}

	create_adj_matrix();
}


