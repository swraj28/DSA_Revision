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


class Graph {

    list<int> *l;
    int V;

public:

    Graph(int V) {
        this->V = V;
        l = new list<int>[V + 1];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
    }

    int minCostBFS(int src, int dest) {
        queue<int> q;
        vector<bool> visited(V, false);
        vector<int> dist(V, 0);

        q.push(src);
        visited[src] = true;
        dist[src] = 0;

        while (!q.empty()) {

            int f = q.front();

            q.pop();

            for (int nbr : l[f]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    dist[nbr] = dist[f] + 1;
                }
            }
        }
        return dist[dest];
    }

};

int min_dice_throws(int n, vector<pair<int, int> > snakes, vector<pair<int, int> > ladders) {

    vector<int> board(n + 1, 0);  // 1 based indexing

    //board to graph conversion (Very Very Important)

    for (auto sp : snakes) {
        int s = sp.first;
        int e = sp.second;
        board[s] = e - s;
    }

    for (auto lp : ladders) {
        int s = lp.first;
        int e = lp.second;
        board[s] = e - s;
    }

    //Graph
    Graph g(n + 1);

    for (int u = 1; u < n; u++) {
        for (int dice = 1; dice <= 6; dice++) {
            int v = u + dice;
            v += board[v];
            if (v <= n) {
                g.addEdge(u, v);
            }
        }

    }

    return g.minCostBFS(1, n);
}

