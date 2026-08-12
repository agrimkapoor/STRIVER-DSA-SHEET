//bridges in graph : it is a edge whose removal increases the connec comp in graph ( TARJANS ALGORITHM )

// during dfs we have to maintain two arrays : disc[]  low[]
// disc[u] : discovery time of vertex u
// low[u] :  earliest discovered vertex reachable from u ka time 
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int timer = 0;

    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, vector<bool>& vis, vector<vector<int>>& bridges) {
        vis[node] = true;
        disc[node] = low[node] = timer++;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, adj, disc, low, vis, bridges);
                low[node] = min(low[node], low[it]);   // child subtree ka low

                if (low[it] > disc[node]) {
                    bridges.push_back({node, it});
                }
            } 
            else {
                // back edge — disc[it] use karo, low[it] nahi
                low[node] = min(low[node], disc[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>> bridges;
        vector<bool> vis(n, false);
        vector<int> disc(n, -1), low(n, -1);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, -1, adj, disc, low, vis, bridges);
        }
        return bridges;
    }
};