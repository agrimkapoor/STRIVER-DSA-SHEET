// previous greater element in the vector
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,3,2,4};
    int n = v.size();
    vector<int> ans(n,-1);//if prev greater element is not present then -1 index will be the answer
    stack<int> st;

    for(int i=0; i<n; i++){
        while(!st.empty() and v[st.top()]<=v[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(v[i]);
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}
