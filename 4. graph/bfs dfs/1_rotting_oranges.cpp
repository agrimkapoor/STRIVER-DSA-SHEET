// LEETCODE 994 :  https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    //MULTISOURCE BFS :  isme level wise traversal karna hai 
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }

        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};

        int mx = 0;
        while(!q.empty()){
            auto f = q.front();
            int r = f.first.first;
            int c = f.first.second;
            int t = f.second;
            q.pop();

            mx = max(mx,t);

            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 and nr<m and nc>=0 and nc<n){
                    if(grid[nr][nc] == 1){
                        grid[nr][nc]=2;//marking as vis
                        q.push({{nr,nc},t+1});
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return mx;
    }
};
