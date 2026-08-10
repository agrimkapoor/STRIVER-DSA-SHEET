// maximal rectangle : leetcode 85

class Solution {
public:
    void f1(vector<int>&heights,vector<int>&ns){
        int n = heights.size();
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(!s.empty())ns[i]=s.top();
            s.push(i);
        }
    }
    void f2(vector<int>&heights,vector<int>&ps){
        int n = heights.size();
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() and heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(!s.empty())ps[i]=s.top();
            s.push(i);
        }
    }
    int f(vector<int>& heights) {
        int n = heights.size();
        vector<int>ns(n,n);
        vector<int>ps(n,-1);
        f1(heights,ns);
        f2(heights,ps);
        int ans=0;
        for(int i=0;i<n;i++){
            int width = ns[i] - ps[i]-1;
            ans = max(ans,heights[i]*width);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int j = 0; j < n; j++) {
            dp[0][j] = (matrix[0][j] == '1') ? 1 : 0;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1')
                    dp[i][j] = dp[i-1][j] + 1;
                else
                    dp[i][j] = 0;
            }
        }
        int mx=0;
        for(int i=0;i<m;i++){
            mx=max(mx,f(dp[i]));
        }
        return mx;
    }
};
