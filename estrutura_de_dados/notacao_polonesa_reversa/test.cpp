#include <iostream>
#include <stack>
#include <string>
#include <sstream>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // Assuming '(' has lowest precedence
}

std::string infixToPostfix(const std::string& infix) {
    std::stringstream postfix;
    std::stack<char> operators;

    for (char c : infix) {
        if (c == ' ') {
            continue;
        } else if (isdigit(c)) {
            postfix << c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix << ' ' << operators.top();
                operators.pop();
            }
            operators.pop(); // Discard '('
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
                postfix << ' ' << operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix << ' ' << operators.top();
        operators.pop();
    }

    return postfix.str();
}

int main() {
    char exp3[] = "2 + (2 * 2 + (2 * 2))";
    std::string infix(exp3);
    std::string postfix = infixToPostfix(infix);
    std::cout << "Infix: " << infix << std::endl;
    std::cout << "Postfix: " << postfix << std::endl;

    return 0;
}
