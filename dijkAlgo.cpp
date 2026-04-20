/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int source) {
    // Distance array
    vector<int> dist(n + 1, INT_MAX);
    dist[source] = 0;

    // Min heap (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip outdated entries
        if (d > dist[node]) continue;

        for (auto it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed graph
    }

    int source;
    cin >> source;

    vector<int> result = dijkstra(n, adj, source);

    // Output distances (1 to n)
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}