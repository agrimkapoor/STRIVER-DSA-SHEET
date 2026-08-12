//topo sort by bfs : kahns algo
// directed acyclic graph

#include <bits/stdc++.h>
using namespace std;

vector<int> topo(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto neigh : adj[i]){
            indegree[neigh]++;//bas neigh ki indegree ++ ho rhi
        }
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        auto x = q.front();
        q.pop();

        ans.push_back(x);

        for(auto neigh : adj[x]){
            indegree[neigh]--;
            if(indegree[neigh]==0){//agar undirec graph toh infinite loop : src se neigh neigh se src
                q.push(neigh);
            }
        }
    }
    return ans;
}