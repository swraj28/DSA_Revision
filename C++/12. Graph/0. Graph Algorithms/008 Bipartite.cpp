#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <list>
#include <iomanip>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <bitset>
#include <cstring>
#include <numeric>
#include <array>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <ctime>
#include <unordered_set>
#include <random>
#include <functional>
#include <cassert>
#include <chrono>

using namespace std;

#define ll long long
#define ull unsigned long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define PI 3.1415926535897932384626
#define mod 1000000007
#define mod1 998244353
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define YES cout << "YES\n";
#define Yes cout << "Yes\n";
#define NO cout << "NO\n";
#define No cout << "No\n";
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(), (v).end()

bool dfs_helper(vector<int> graph[], int node, vector<int>& visited, int parent, int color) {
    visited[node] = color; // 1 or 2, both mean visited

    for (auto nbr : graph[node]) {
        if (visited[nbr] == 0) {
            bool rec_result = dfs_helper(graph, nbr, visited, node, 3 - color);
            if (!rec_result) return false;
        } else if (nbr != parent && color == visited[nbr]) {
            return false;
        }
    }

    return true;
}

bool dfs(vector<int> graph[], int n) {
    vector<int> visited(n, 0);

    int color = 1;
    bool ans = dfs_helper(graph, 0, visited, -1, color);

    for (int i = 0; i < n; i++) {
        cout << i << " - Color " << visited[i] << endl;
    }

    return ans;
}

bool bipartiteBfs(int src, vector<int> adj[], vector<int>& color) {
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            } else if (color[it] == color[node]) {
                return false;
            }
        }
    }

    return true;
}

bool checkBipartite(vector<int> adj[], int n) {
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> graph[n];
    while (m--) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if (dfs(graph, n)) {
        cout << "Bipartite Graph" << endl;
    } else {
        cout << "Not a Bipartite Graph" << endl;
    }

    return 0;
}
