// to check if graph is bipartite

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int src,vector<vector<int>>&adj,vector<int>&color,int c ){
        color[src]=c;
        for(auto neigh : adj[src]){
            if(color[neigh]==0){
                bool ans = dfs(neigh,adj,color,3-c);
                if(ans==false)return false;
            }
            else if(color[neigh]==c){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,0);
        for(int i=0;i<n;i++){
            if(color[i]==0){
                bool ans = dfs(i,graph,color,1);
                if(ans == false)return false;
            }
        }
        return true;
    }
};