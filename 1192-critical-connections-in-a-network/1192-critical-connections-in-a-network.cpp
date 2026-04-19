class Solution {
public:
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<bool> visited;
    vector<vector<int>> bridges;
    int timer = 0;

    void dfs(int node, int parent) {
        visited[node] = true;
        tin[node] = low[node] = timer++;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;

            if (!visited[neighbor]) {
                dfs(neighbor, node);

                low[node] = min(low[node], low[neighbor]);

                // bridge condition
                if (low[neighbor] > tin[node]) {
                    bridges.push_back({node, neighbor});
                }
            } else {
                // back edge
                low[node] = min(low[node], tin[neighbor]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        tin.resize(n);
        low.resize(n);
        visited.resize(n, false);

        // build graph
        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // run DFS (graph is connected but still safe to loop)
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }

        return bridges;
    }
};