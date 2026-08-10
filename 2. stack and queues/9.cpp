// largest rectangle in histogram : leetcode 84
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
    int largestRectangleArea(vector<int>& heights) {
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
};
