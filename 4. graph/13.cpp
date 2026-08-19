//bellman ford algo : it works for directed graph as for undirected graph with -ve edge will become a -ve edge cycle
#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(
    int V,
    vector<vector<int>>& edges,
    int src
) {
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    // Relax all edges V-1 times
    for(int i = 1; i <= V - 1; i++) {


        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != INT_MAX &&
               dist[u] + wt < dist[v]) {

                dist[v] = dist[u] + wt;
            }
        }

    }

    // Check for negative cycle
    for(auto edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(dist[u] != INT_MAX &&
           dist[u] + wt < dist[v]) {

            // Negative weight cycle exists
            return {};
        }
    }

    return dist;
}
