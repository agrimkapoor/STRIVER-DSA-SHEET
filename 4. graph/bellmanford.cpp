// bellmand is also for single source shortest path in weighted graph
// it also works in negative edge weights
// it can be used to detect negative edge cycle
// so if negative edge in unweighted graph then there is negative edge cycle
// djisktra was greedy (har step pe min dist)
// bellman is dp 

#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<vector<int>>&edges,int n,int src){
  vector<int>dis(n,INT_MAX);
  dis[src]=0;
  for(int i=0;i< n-1;i++){
     for(auto p : edges){
         int u = p[0];
         int v = p[1];
         int wt = p[2];

         if(dis[u] != INT_MAX and dis[v] > dis[u] + wt ){
            dis[v] = dis[u] + wt;
         }
     }
  }
  return dis;
}


int main(){
  return 0;
}
