
// a) Write an algorithm to calculate the postfix expression from an infix expression. Simulate your algorithm based on the following input infix expression.
// 3^7-5/7+3*4/5+6*2
 
// b) Write an algorithm to calculate the value of a postfix expression. Based on the converted postfix expression in 7.a), simulate the output using your designed algorithm. [Use integer operations only]
 

// Answer:
// a) Algorithm to convert infix expression to postfix expression:
// 1. Create an empty stack to store operators.
// 2. Create an empty string to store the postfix expression. 
// 3. For each character in the infix expression:
//    a. If the character is an operand, add it to the postfix expression string.
//    b. If the character is an operator:
//       i. While the stack is not empty and the precedence of the top operator in the stack is greater than or equal to the precedence of the current operator, pop the top operator from the stack and add it to the postfix expression string.
//       ii. Push the current operator onto the stack.
//    c. If the character is an opening parenthesis, push it onto the stack.
//    d. If the character is a closing parenthesis:
//       i. Pop operators from the stack and add them to the postfix expression string until an opening parenthesis is encountered.
//       ii. Discard the opening parenthesis.
// 4. Pop any remaining operators from the stack and add them to the postfix expression string.
// 5. Return the postfix expression string.


// b) Algorithm to evaluate a postfix expression:
// 1. Create an empty stack to store operands.
// 2. For each character in the postfix expression:
//    a. If the character is an operand, push it onto the stack.
//    b. If the character is an operator:
//       i. Pop the top two operands from the stack.
//       ii. Perform the operation on the two operands based on the operator.
//       iii. Push the result back onto the stack.
// 3. The final result will be the top element of the stack.
// 4. Return the result.



#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    for (char c : infix) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> st;
    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                case '^': st.push(pow(a, b)); break;
            }
        }
    }
    return st.top();
}


int main() {

    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    // string infix = "3^7-5/7+3*4/5+6*2";
    string postfix = infixToPostfix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    cout << "Evaluation of postfix expression: " << evaluatePostfix(postfix) << endl;
    return 0;
}