/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or N*/
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &visited) {
    visited[node] = 1;

    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];

        // if not visited → go deeper
        if (visited[neighbor] == 0) {
            if (dfs(neighbor, node, adj, visited) == true)
                return true;
        }
        // if visited and not parent → cycle
        else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n, 0);

    // check all components
    for (int i = 0; i < n; i++) {
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