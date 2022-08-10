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