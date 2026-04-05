/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    // input adjacency list
    for (int i = 0; i < n; i++) {
        int m; // number of neighbors of node i
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    int s;
    cin >> s;

    vector<bool> visited(n, false);

    dfs(s, adj, visited);

    return 0;
}