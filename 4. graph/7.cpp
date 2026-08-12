//rotten oranges : leetcode 994

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>>q;//{{i,j},time}

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};

        int mx = 0;

        while(!q.empty()){
            auto f = q.front();
            q.pop();
            int r = f.first.first;
            int c = f.first.second;
            int t = f.second;
            

            //process node
            mx = max(mx,t);

            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 and nr<m and nc>=0 and nc<n){
                    if(grid[nr][nc]==1){// fresh orange
                        grid[nr][nc]=2;
                        q.push({{nr,nc},t+1});
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return mx;
    }
};