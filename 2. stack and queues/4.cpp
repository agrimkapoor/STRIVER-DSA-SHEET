// infix to postfix 

/*
input : A+B*(C-D)
output: ABCD-*+
*/

#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c=='+' or c=='-' or c=='*' or c=='/' or c=='^');// ^ is exponent operator here
}

bool isOperand(char c){
    return (c>= 'a' && c<= 'z') || (c>= 'A' && c<= 'Z');
}

int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*' or c=='/') return 2;
    else if(c=='+' or c=='-') return 1;
    else return -1;
}

string infix2postfix(string infix){
    stack<char>st;
    string postfix = "";

    for(int i=0;i<infix.length();i++){
        char c = infix[i];

        if(isOperand(c)){
            postfix += c;
        }
        else if (c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty() and st.top()!='('){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(isOperator(c)){
            while(!st.empty() and 
                (precedence(st.top()) > precedence(c) || 
                (precedence(st.top()) == precedence(c) && c != '^'))){// ham usse nikal rhe jo pehle solve hoga
                // A+ B*C  toh st mei * tha aur + aaya toh * ko nikalo as woh pehle solve hoga
                // A^B^C toh st mei ^ tha aur ^ aaya tooh ab mat nikalo as woh right associative hai
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main(){
    string infix = "A+B*(C-D)";
    cout<<infix2postfix(infix)<<endl;
    return 0;
}