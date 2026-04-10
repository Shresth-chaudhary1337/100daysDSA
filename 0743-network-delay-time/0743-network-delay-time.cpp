class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        
        // build graph
        for (auto &t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }
        
        // min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int d = it.first;
            int node = it.second;
            
            for (auto &edge : adj[node]) {
                int adjNode = edge.first;
                int wt = edge.second;
                
                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        
        return ans;
    }
};