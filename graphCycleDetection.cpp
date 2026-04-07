#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &visited) {
    visited[node] = 1;

    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];

        // not visited → go deeper
        if (visited[neighbor] == 0) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        }
        // visited and not parent → cycle
        else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    // input edges
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    // build adjacency list
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(V, 0);

    // check all components
    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            if (dfs(i, -1, adj, visited)) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}