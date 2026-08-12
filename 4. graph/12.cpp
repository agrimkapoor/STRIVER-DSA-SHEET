// djikstra algo
// ab vis nhi kyuki now first way to reach a node may not be the 

#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<pair<int,int>>>&adj,int src){
    int n = adj.size();
    vector<int>dis(n,INT_MAX);
    set<pair<int,int>>s;
    dis[src]=0;
    s.insert({0,src});//dis[src] , src
    

    while(!s.empty()){
        auto f = s.begin();
        int parD = f->first;
        int par = f->second;
        s.erase(f);

        for(auto neigh : adj[par]){
            int child = neigh.first;
            int eD = neigh.second;

            if(dis[child] > dis[par] + eD){
                auto f = s.find({dis[child],child});
                if(f!=s.end())s.erase(f);
                dis[child] = dis[par] + eD;
                s.insert({dis[child],child});
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }
}