#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1; // For '(' and ')'
}

string infixToPostfix(string expression) {
    stack<char> st;
    string postfix = "";

    for (char& c : expression) {
        // If character is an operand, append it to postfix string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            postfix += c;
        // If character is '(', push it to the stack
        else if (c == '(')
            st.push(c);
        // If character is ')', pop and append operators from stack until '(' is encountered
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Pop '(' from stack
        }
        // If character is an operator
        else {
            // Pop operators with higher or equal precedence from the stack and append to postfix
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(c); // Push the current operator to the stack
        }
    }

    // Append remaining operators from the stack to postfix
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix_expression;
    cout << "Enter infix expression: ";
    getline(cin, infix_expression);

    string postfix_expression = infixToPostfix(infix_expression);
    cout << "Postfix expression: " << postfix_expression << endl;

    return 0;
}
