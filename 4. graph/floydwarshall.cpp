//floyd warshal : all pairs shortest path algorithm
//It can also handle negative edges
//It cannot give a meaningful shortest path if there is a negative cycle
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>f(vector<vector<int>>& edges, int n){
   vector<vector<int>>dis(n,vector<int>(n,INT_MAX));

    for(int i=0;i<n;i++){
        dis[i][i]=0;
    }

    for(auto p : edges){
       int u = p[0];
       int v = p[1];
       int wt = p[2];

       dis[u][v] = wt;
    }

    // shortest distance from i to j using nodes 0...k as intermediate nodes  dp[k][i][j]
    for(int k=0;k<n;k++){
       for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            if(dis[i][k] != INT_MAX and dis[k][j] != INT_MAX){
               dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
         }
       }
    }

    for(int i=0;i<n;i++){
      if(dis[i][i] < 0){
         return {};
      }
    }
      
    return dis;
   
}

int main(){
  return 0;
}
