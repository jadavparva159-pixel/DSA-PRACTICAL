
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char ch : infix) {
        if (isspace(static_cast<unsigned char>(ch))) {
            continue;
        }

        // Operand goes directly to output.
        if (isalnum(static_cast<unsigned char>(ch))) {
            postfix += ch;
        }

        // Opening bracket goes onto the stack.
        else if (ch == '(') {
            st.push(ch);
        }

        // Pop operators until the matching opening bracket.
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            if (st.empty()) {
                return "Invalid Expression";
            }

            st.pop(); // Remove '('
        }

        // Handle operators according to precedence.
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^') {

            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                   (precedence(st.top()) == precedence(ch)
                    && ch != '^'))) {

                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }

        else {
            return "Invalid Expression";
        }
    }

    while (!st.empty()) {
        if (st.top() == '(') {
            return "Invalid Expression";
        }

        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    cout << "Postfix expression: "
         << infixToPostfix(infix) << endl;

    return 0;
}

