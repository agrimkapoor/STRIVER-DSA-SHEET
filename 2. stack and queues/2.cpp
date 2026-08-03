// asteroid collision

#include <bits/stdc++.h>
using namespace std;

//[5,10,-5]
// -5 will collide with 10 pehle (jo last mei aaya)

vector<int> f(const vector<int> &nums){
    int n = nums.size();
    stack<int> st;

    for (int i = 0; i < n; i++){
        int aster = nums[i];
        int value = abs(nums[i]);
        int direc = (aster > 0) ? 1 : -1;

        bool flag = false;
        while (!st.empty()){
            int ele = st.top();
            int val = abs(st.top());
            int dir = (ele > 0) ? 1 : -1;

            if (dir == direc)
                break;
            else if (direc == 1 and dir == -1)
                break;
            else{
                if (value < val){
                    flag = true;
                    break;
                }
                else if (value > val){
                    st.pop();
                }
                else{
                    st.pop();
                    flag = true;
                    break;
                }
            }
        }
        if (flag == false)
            st.push(nums[i]);
    }
    vector<int> ans;
    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> nums = {5, 10, -5};
    vector<int> ans = f(nums);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
