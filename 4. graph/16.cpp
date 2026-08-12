//articulation point in graph : aisi node jisko hatane se no of connec bad jaaye : tarjan algo 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int timer = 0;

    void dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& disc,
             vector<int>& low,
             vector<bool>& vis,
             vector<bool>& isAP) {

        vis[node] = true;

        disc[node] = low[node] = timer++;
        int children = 0;

        for (auto it : adj[node]) {

            // Parent edge ko ignore karo
            if (it == parent)
                continue;

            if (!vis[it]) {
                children++;

                // DFS
                dfs(it, node, adj, disc, low, vis, isAP);

                // Child se low value update
                low[node] = min(low[node], low[it]);

                // Articulation point condition
                if (parent != -1 && low[it] >= disc[node]) {
                    isAP[node] = true;
                }
            }
            else {
                // Back edge
                low[node] = min(low[node], disc[it]);
            }
        }

        // Root ke liye special condition
        if (parent == -1 && children > 1) {
            isAP[node] = true;
        }
    }

public:
    vector<int> articulationPoints(
        int n,
        vector<vector<int>>& connections
    ) {
        vector<vector<int>> adj(n);

        // Build adjacency list
        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<bool> vis(n, false);
        vector<bool> isAP(n, false);

        timer = 0;

        // Graph disconnected bhi ho sakta hai
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, disc, low, vis, isAP);
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (isAP[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};