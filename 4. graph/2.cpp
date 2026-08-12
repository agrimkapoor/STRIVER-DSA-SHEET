// dfs traversal in unweighted graph: ek node se jitna deep jaa sakte hain utna deep jao, phir backtrack karke next node pe jao, aur phir uske jitne deep jaa sakte hain utna deep jao, aur phir backtrack karke next node pe jao, aur aise hi chalte raho jab tak saare nodes visit na ho jayein

#include <bits/stdc++.h>
using namespace std;

void dfs(int src,vector<vector<int>>&adj,vector<bool>&vis){
    vis[src]=true;
    cout<<src<<" ";// process the node

    for(auto neigh : adj[src]){
        if(!vis[neigh]){
            dfs(neigh,adj,vis);
        }
    }
}