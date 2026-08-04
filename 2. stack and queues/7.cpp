//prefix to infix 

#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c=='+' or c=='-' or c=='*' or c=='/' or c=='^');
}

bool isOperand(char c){
    return (c>= 'a' && c<= 'z') || (c>= 'A' && c<= 'Z') || (c>='0' && c<='9');
}

string prefix2infix(string prefix){
    stack<string> st;

    // scan RIGHT to LEFT
    for(int i = prefix.length()-1; i >= 0; i--){
        char c = prefix[i];

        if(isOperand(c)){
            string s = "";
            s += c;
            st.push(s);
        }
        else if(isOperator(c)){
            string op1 = st.top(); st.pop();  // left operand (popped first now)
            string op2 = st.top(); st.pop();  // right operand

            string combined = "(" + op1 + c + op2 + ")";
            st.push(combined);
        }
    }

    return st.top();
}

int main(){
    string prefix = "+A*B-CD"; // prefix of A+(B*(C-D))
    cout << prefix2infix(prefix) << endl;
    return 0;
}