// to detect cycle in directed graph by using kahns algo
// agar number of nodes in topo list is < n then there is a cycle

// this is leetcode 207 : course schedule

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto neigh : adj[i]){
                indegree[neigh]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int cnt=0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();

            cnt++;

            for(auto neigh : adj[x]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        return cnt==n;// if cnt < n then there is a cycle
    }
};