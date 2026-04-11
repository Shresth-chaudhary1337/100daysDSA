class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;

            for (vector<int> &f : flights) {
                int u = f[0];
                int v = f[1];
                int cost = f[2];

                if (dist[u] == INT_MAX) continue;

                if (dist[u] + cost < temp[v]) {
                    temp[v] = dist[u] + cost;
                }
            }

            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
        
    }
};