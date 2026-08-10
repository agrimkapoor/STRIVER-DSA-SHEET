//leetcode 907 : sum of subarray minimum
class Solution {
public:
    const int MOD = 1e9 + 7;

    
    vector<int> f1(const vector<int>& nums) { // prev smaller (strict)
        int n = nums.size();
        stack<int> st;
        vector<int> ps(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() and nums[i] < nums[st.top()]) { // strict 
                st.pop();
            }
            if (!st.empty()) ps[i] = st.top();
            st.push(i);
        }
        return ps;
    }

    vector<int> f2(const vector<int>& nums) { // next smaller (or equal)
        int n = nums.size();
        stack<int> st;
        vector<int> ns(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and nums[i] <= nums[st.top()]) { // <=
                st.pop();
            }
            if (!st.empty()) ns[i] = st.top();
            st.push(i);
        }
        return ns;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int ans=0;
        vector<int>ps = f1(arr);
        vector<int>ns = f2(arr);
        for(int i=0;i<n;i++){
            // ye nums[i] kitne subarrays ka min hai
            int l = ps[i];
            int r = ns[i];

            int left = i - ps[i];// start karne ke kitne choices
            int right = ns[i] - i; // end karne ke kitne choices

            ans = (ans + 1LL*arr[i]*left*right)%MOD;
        }
        return ans;
    }
};
