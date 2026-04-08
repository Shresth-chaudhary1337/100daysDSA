/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (int i = 0; i < adj[node].size(); i++) {
        int nbr = adj[node][i];

        if (!vis[nbr]) {
            if (dfs(nbr, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[nbr]) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v); // directed graph
    }

    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, pathVis))
                return true;
        }
    }

    return false;
}

int main() {
    int V = 4;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,1}};

    if (isCycle(V, edges))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}