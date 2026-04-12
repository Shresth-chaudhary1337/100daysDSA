/*Min Cost to Connect All Points
Medium
Topics
premium lock icon
Companies
Hint
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCost(vector<vector<int>>& points) {
    int n = points.size();

    vector<int> dist(n, INT_MAX);
    vector<bool> vis(n, false);

    dist[0] = 0;
    int total = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        vis[u] = true;
        total += dist[u];

        for (int v = 0; v < n; v++) {
            if (!vis[v]) {
                int d = abs(points[u][0] - points[v][0]) +
                        abs(points[u][1] - points[v][1]);

                if (d < dist[v]) {
                    dist[v] = d;
                }
            }
        }
    }

    return total;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    cout << minCost(points);
}