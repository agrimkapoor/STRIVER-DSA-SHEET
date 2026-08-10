// online stock span problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    int n = prices.size();
    
    vector<int> pg(n); // pg[i] = index of previous greater element
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }
        pg[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    vector<int> span(n);
    for (int i = 0; i < n; i++) {
        span[i] = i - pg[i];
    }

    return 0;
}
