/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        
        int d = it.first;
        int node = it.second;
        
        for (auto edge : adj[node]) {
            int adjNode = edge.first;
            int wt = edge.second;
            
            if (d + wt < dist[adjNode]) {
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    
    return dist;
}

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    // u -> v (weight)
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    vector<int> ans = dijkstra(V, adj, 0);

    for (int d : ans) {
        cout << d << " ";
    }
}