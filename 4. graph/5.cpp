//cycle detection in undirected graph

#include <bits/stdc++.h>
using namespace std;

bool dfs(int src,int par,vector<vector<int>>&adj,vector<bool>&vis){
    vis[src]=true;
    for(auto neigh : adj[src]){
        if(!vis[neigh]){
            bool ans = dfs(neigh,src,adj,vis);
            if(ans==true)return true;
        }
        else if(vis[neigh] and neigh!=par){
            return true;
        }
    }
    return false;
}

bool hasCycle(int n, vector<vector<int>> &adj) {
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis))   // -1 = no parent, disconnected components handle karne ke liye loop
                return true;
        }
    }
    return false;
}