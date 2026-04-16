#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1 << 15][15];

// TSP function
int tsp(int mask, int pos, vector<vector<int>> &cost) {
    // If all cities are visited, return to starting city
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    // If already calculated
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    // Try all unvisited cities
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] +
                         tsp(mask | (1 << city), city, cost);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << tsp(1, 0, cost);

    return 0;
}