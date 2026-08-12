// to find no of connected components in a graph

#include <bits/stdc++.h>
using namespace std;

void dfs(int src,vector<vector<int>>&adj,vector<bool>&vis){
    vis[src]=true;
    for(auto neigh : adj[src]){
        if(!vis[neigh]){
            dfs(neigh,adj,vis);
        }
    }
}

int countConnectedComponents(int n,vector<vector<int>>&adj){
    vector<bool>vis(n,false);
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,vis);
            cnt++;
        }
    }
    return cnt;
}