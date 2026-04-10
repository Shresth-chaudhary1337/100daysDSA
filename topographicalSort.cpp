/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);

    // calculate indegree
    for (int i = 0; i < V; i++) {
        for (int x : adj[i]) {
            indegree[x]++;
        }
    }

    queue<int> q;

    // push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (int x : adj[node]) {
            indegree[x]--;

            if (indegree[x] == 0) {
                q.push(x);
            }
        }
    }

    return ans;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);

    vector<int> res = topoSort(V, adj);

    for (int x : res) {
        cout << x << " ";
    }
}