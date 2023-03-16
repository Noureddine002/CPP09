#include "RPN.hpp"
#include <stack>

int evaluateRPN(std::string expression) {
    std::stack<int> st;
    int a, b;
    char op;
    std::stringstream ss(expression);
    while (ss >> op) {
        if (isdigit(op)) {
            st.push(op - '0');
        } else if (op == '+') {
            if (st.size() < 2) {
                return 0; // error: not enough operands
            }
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(a + b);
        } else if (op == '-') {
            if (st.size() < 2) {
                return 0; // error: not enough operands
            }
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(a - b);
        } else if (op == '*') {
            if (st.size() < 2) {
                return 0; // error: not enough operands
            }
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(a * b);
        } else if (op == '/') {
            if (st.size() < 2) {
                return 0; // error: not enough operands
            }
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            if (b == 0) {
                return 0; // error: division by zero
            }
            st.push(a / b);
        } else {
            return 0; // error: invalid operator
        }
    }
    if (st.size() != 1) {
        return 0; // error: too many operands
    }
    return st.top();
}