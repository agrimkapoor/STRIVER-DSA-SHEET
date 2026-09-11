// LEETCODE 994 :  https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    //MULTISOURCE BFS :  isme level wise traversal karna hai 
    //ham ek graph banate where each cell of the grid would be a node and edge will be to its 4 directional neigh nodes
    // ispe bfs lagate
    // par ham graph nhi bana rhe and generating neighbors on the fly (no need to make graph in grid waale ques)
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
