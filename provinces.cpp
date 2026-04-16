/*Number of Provinces
Solved
Medium
Topics
premium lock icon
Companies
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int city, vector<vector<int>>& isConnected, vector<int>& visited) {
    visited[city] = 1;

    for (int j = 0; j < isConnected.size(); j++) {
        if (isConnected[city][j] == 1 && !visited[j]) {
            dfs(j, isConnected, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));

    // input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    vector<int> visited(n, 0);
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, isConnected, visited);
            provinces++;
        }
    }

    cout << provinces;

    return 0;
}