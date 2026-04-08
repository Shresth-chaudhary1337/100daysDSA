/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];

        // not visited
        if (visited[neighbor] == 0) {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
        // if in current path → cycle
        else if (recStack[neighbor] == 1) {
            return true;
        }
    }

    recStack[node] = 0; // remove from current path
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    // input directed edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed
    }

    vector<int> visited(V, 0);
    vector<int> recStack(V, 0);

    // check all components
    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            if (dfs(i, adj, visited, recStack)) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}