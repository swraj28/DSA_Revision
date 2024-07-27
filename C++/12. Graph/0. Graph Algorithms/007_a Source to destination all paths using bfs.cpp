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
    map<int, vector<int>> adj;
public:

    void add_Edges(int src, int dest) {
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    void printpath(vector<int>& path) {

        int size = path.size();

        for (int i = 0; i < size; i++) {
            cout << path[i] << "->";
        }

        cout << endl;
    }

    int isNotVisited(int x, vector<int>& path) {

        int size = path.size();
        for (int i = 0; i < size; i++) {
            if (path[i] == x) {
                return 0;
            }
        }

        return 1;
    }

    void bfs(int src, int dest) {

        queue<vector<int>> q;

        vector<int> path;
        path.pb(src);

        q.push(path);

        while (!q.empty()) {

            path = q.front();
            q.pop();

            int last = path[path.size() - 1];

            if (last == dest) {
                printpath(path);
                continue;
            }

            for (auto &nbr : adj[last]) {
                if (isNotVisited(nbr, path)) {
                    vector<int> newPath(path);
                    newPath.pb(nbr);

                    q.push(newPath);
                }
            }
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Graph g;

    g.add_Edges(0, 1);
    g.add_Edges(1, 2);
    g.add_Edges(2, 3);
    g.add_Edges(0, 3);
    g.add_Edges(3, 4);
    g.add_Edges(4, 5);
    g.add_Edges(4, 6);
    g.add_Edges(5, 6);

    g.bfs(0, 6);

    return 0;
}