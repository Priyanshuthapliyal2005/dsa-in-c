#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char a)
{
    switch (a)
    {
    case '-':
    case '+':
        return 1;
    case '*':
    case '/':
        return 2;
    case '(':
        return 0; // Lower precedence for '('
    default:
        return 3; // Higher precedence for all other characters
    }
}

int main() {
    string s = "a+b/(c-d)*e";
    stack<char> st;
    string prefix;

    // Reverse the infix expression
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        }
        else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            prefix += s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }

            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
            else {
                cout << "Unbalanced parentheses" << endl;
                return 1; // Exit with an error code
            }
        }
        else if (prec(s[i]) > 0) {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                prefix += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }

    // Reverse the prefix expression to get the final result
    reverse(prefix.begin(), prefix.end());

    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
