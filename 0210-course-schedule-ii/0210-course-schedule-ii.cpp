class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path, vector<int>& result) {
        visited[node] = 1;
        path[node] = 1;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, path, result))
                    return true;
            }
            else if (path[neighbor]) {
                return true; // cycle found
            }
        }

        path[node] = 0;
        result.push_back(node); // post-order

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // build graph: b -> a
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> path(numCourses, 0);
        vector<int> result;

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, path, result)) {
                    return {}; // cycle → impossible
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};