// Floyd-Warshall Algorithm
// All-Pairs Shortest Path
// Negative edges allowed
// Time: O(V^3)
// Space: O(V^2)

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist) {

    int n = dist.size();

    // k = intermediate vertex
    for(int k = 0; k < n; k++) {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                // Avoid INF + value
                if(dist[i][k] == INF || dist[k][j] == INF)
                    continue;

                // Relaxation
                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]
                );
            }
        }
    }

    // Negative cycle detection
    for(int i = 0; i < n; i++) {
        if(dist[i][i] < 0) {
            cout << "Negative cycle exists\n";
            return;
        }
    }

    // Print shortest distances
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }

        cout << "\n";
    }
}

int main() {

    int n = 3;

    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Distance to itself = 0
    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // u -> v = weight
    dist[0][1] = 5;
    dist[1][2] = 3;
    dist[0][2] = 10;

    floydWarshall(dist);

    return 0;
}