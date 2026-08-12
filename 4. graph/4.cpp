// cycle detection in directed graph

#include <bits/stdc++.h>
using namespace std;

bool dfs(int src ,vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&instack){
    vis[src] = true;
    instack[src] = true;

    for(auto neigh : adj[src]){
        if(!vis[neigh]){
            bool ans = dfs(neigh,adj,vis,instack);
            if(ans==true)return true;//agar kisi bhi node se cycle mil gayi toh true return kar do
        }
        else if(instack[neigh] == true){
            return true; //neighbor already current path mein hai 
        }
    }
    instack[src]=false;
    return false;
}