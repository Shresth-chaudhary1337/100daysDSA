/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st) {
    visited[node] = 1;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }

    st.push(node); // push after visiting all neighbors
}

vector<int> topoSort(int V, vector<vector<int>> &adj) {
    vector<int> visited(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> result;

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

int main() {
    int V = 6;

    vector<vector<int>> adj(V);

    // Example DAG
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topo = topoSort(V, adj);

    cout << "Topological Sort: ";
    for (int node : topo) {
        cout << node << " ";
    }

    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> cd5e663 (Add courseSchedule.cpp)
