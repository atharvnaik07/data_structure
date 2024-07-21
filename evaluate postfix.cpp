#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

double applyOperation(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: throw runtime_error("Invalid operator");
    }
}

double evaluatePostfix(const string& expression) {
    stack<double> operands;
    
    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0'); // Convert char to integer and push to stack
        } else if (isOperator(c)) {
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();
            double result = applyOperation(operand1, operand2, c);
            operands.push(result);
        }
    }
    
    return operands.top();
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    getline(cin, postfixExpression);
    
    try {
        double result = evaluatePostfix(postfixExpression);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    
    return 0;
}
