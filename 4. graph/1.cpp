// bfs traversal in unweighted graph : jab koi node ko kardiya visit toh woh hi min distance pe hoga from source node isliye ham tab hi visited mark kar denge

#include<bits/stdc++.h>
using namespace std;

void bfs(int src,vector<vector<int>>&adj,vector<bool>&vis){
    queue<int>q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int node = q.front();
            q.pop();
            
            cout<<node<<"";// process the node

            for(auto neigh : adj[node]){
                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        cout<<endl;// for printing level wise
    }
}

// visited marking ko push time pe karo and not at pop time warna same node multiple times queue mein aa sakta hai (duplicate processing), though answer still correct rahega bas extra overhead hoga.
// 0 is connected to 1 and 2 , 1 is connected to 2 so when we start from 0, we will push 1 and 2 into queue, then when we pop 1, we will again push 2 into queue as it is not marked visited yet, so now 2 is in queue twice. So, to avoid this, we mark visited at the time of pushing into queue.

