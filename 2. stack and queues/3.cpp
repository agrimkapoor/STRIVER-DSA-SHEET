// online stock span problem

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(vector<int>& price) {
        int n = price.size();
        vector<int> span(n);
        stack<int> st;   // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && price[st.top()] <= price[i]) {
                st.pop();
            }

            if (st.empty())
                span[i] = i + 1;
            else
                span[i] = i - st.top();

            st.push(i);
        }

        return span;
    }
}; 