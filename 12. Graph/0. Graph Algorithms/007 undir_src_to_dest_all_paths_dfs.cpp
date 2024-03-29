#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Graph {
    map<int, list<int>> adj;
public:

    void add_Edges(int src, int dest) {
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    // https://www.geeksforgeeks.org/find-paths-given-source-destination/

    // The time complexity of this approach will lead to exponetial -->(v^v) --> where v is the number of vertices


    void dfs(vector<int> &visited, vector<int> &path, int src, int dest) {

        visited[src] = 1;
        path.push_back(src);

        if (src == dest) {
            for (auto i : path) {
                cout << i << "->";
            }
            cout << endl;
            return;
        }

        for (auto nbr : adj[src]) {
            if (!visited[nbr]) {
                dfs(visited, path, nbr, dest);

                //Backtracking
                path.pop_back();
                visited[nbr] = 0;
            }
        }
    }

    void path(int src, int dest) {

        vector<int> path;
        vector<int> visited (adj.size(), 0);

        dfs(visited, path, src, dest);
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

    g.path(0, 6);



    return 0;
}