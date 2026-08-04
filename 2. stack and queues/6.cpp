//postfix to infix

/*
Algorithm
1.Traverse the postfix expression from left to right.
2.If the character is an operand, push it onto the stack.
3.If the character is an operator:
 Pop the top two elements.
 Let the first popped be op2 and the second be op1.

 Form the expression:

 (op1 operator op2)
 Push the new expression back onto the stack.
4.At the end, the stack's top is the required infix expression.
*/


#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c=='+' or c=='-' or c=='*' or c=='/' or c=='^');
}

bool isOperand(char c){
    return (c>= 'a' && c<= 'z') || (c>= 'A' && c<= 'Z') || (c>='0' && c<='9');
}

string postfix2infix(string postfix){
    stack<string> st;

    for(int i=0; i<postfix.length(); i++){
        char c = postfix[i];

        if(isOperand(c)){
            // push single operand as a string
            string s = "";
            s += c;
            st.push(s);
        }
        else if(isOperator(c)){
            string op2 = st.top(); st.pop();  // second operand (popped first)
            string op1 = st.top(); st.pop();  // first operand
            
            string combined = "(" + op1 + c + op2 + ")";
            st.push(combined);
        }
    }

    return st.top(); // final infix expression
}

int main(){
    string postfix = "ABC-*+"; // A+(B-C) -> wait, let's check with a real example
    cout << postfix2infix(postfix) << endl;
    return 0;
}