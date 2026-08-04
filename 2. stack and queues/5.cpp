// infix to prefix

/*

To convert Infix → Prefix, the standard approach is:

1. Reverse the infix expression.
2. Swap '(' with ')'.
3. Convert the modified expression to postfix.
4. Reverse the postfix expression to get the prefix expression.

A+B*(C-D)
1. Reverse: )D-C(*B+A
2. Swap parentheses: (D-C)*B+A
3. Convert to postfix: DC-B*A+
4. Reverse postfix: +A*B-C*D

*/