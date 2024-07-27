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


#define INF 10000000

// Time Complexity:-O(n^3)--> n is the number of nodes.

// Space Complexity:- O(n^2)--> n is the number of nodes.

vector<vector<int> > floyd_warshall(vector<vector<int> > graph) {

	vector<vector<int> > dist(graph);

	int V = graph.size();

	//Phases, in kth phase we included vertices (0,1,2,...k-1) as intermediate vertices

	for (int k = 0; k < V; k++) {

		//Iterate over entire 2D Matrix
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {

				//if vertex k is included as intermidiate vertex, and can we minimise the dist ?
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	return dist;
}

// Negative Edge Weight Cycle detection using Floyd Warshall Algorithm.-- (To do)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// 4 Vertices (4 X 4 Matrix)
	vector<vector<int> > graph = {
		{0, INF, -2, INF},
		{4, 0, 3, INF},
		{INF, INF, 0, 2},
		{INF, -1, INF, 0}
	};


	auto result = floyd_warshall(graph);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}