/*Course Schedule II
Solved
Medium
Topics
premium lock icon
Companies
Hint
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path, vector<int>& result) {
    visited[node] = 1;
    path[node] = 1;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, path, result))
                return true;
        }
        else if (path[neighbor]) {
            return true; // cycle detected
        }
    }

    path[node] = 0;
    result.push_back(node);

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
                return {}; // cycle found
            }
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int numCourses = 4;

    // Example: [[1,0],[2,0],[3,1],[3,2]]
    vector<vector<int>> prerequisites = {
        {1,0}, {2,0}, {3,1}, {3,2}
    };

    vector<int> order = findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "Impossible to finish all courses (cycle detected)" << endl;
    } else {
        cout << "Course Order: ";
        for (int x : order) {
            cout << x << " ";
        }
    }

    return 0;
}