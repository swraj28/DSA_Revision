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

int R;
int C;

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void print_mat(char mat[][50]) {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void Flood_fill(char mat[][50], int i, int j, char ch, char color) {
	// BAse Case-MAtrix Boundary Condition
	if (i<0 or j<0 or i >= R or j >= C) {
		return;
	}
	//Figure Boundary Condition
	if (mat[i][j] != ch) {
		return;
	}

	//Recursive Call
	mat[i][j] = color;

	for (int k = 0; k < 4; k++) {
		Flood_fill(mat, i + dx[k], j + dy[k], ch, color);
	}

	return;
}

int main() {

	cin >> R >> C;

	char mat[15][50];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mat[i][j];
		}
	}

	print_mat(mat);
	Flood_fill(mat, 10, 14, '.', 'r');
	print_mat(mat);

	return 0;
}