// Sliding window maximum : leetcode 239

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;

        vector<int>ans;

        for(int i=0;i<k;i++){
            while(!dq.empty() and nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

       for(int i=k;i<n;i++){

            //left se shrink 
            if(dq.front()<= i-k){
                dq.pop_front();
            }

            //right se expand
            while(!dq.empty() and nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
       }
       return ans;
    }
};
