#include <iostream>
using namespace std;

const int MAX = 100;
int top = -1;
char stack[MAX];

void push(char v) {
    if (top >= MAX - 1) {
        cout << "Stack overflow" << endl;
    } else {
        top++;
        stack[top] = v;
    }
}

char pop() {
    if (top == -1) {
        cout << "Stack underflow" << endl;
        return '\0'; // Return a placeholder value
    } else {
        char popped = stack[top];
        top--;
        return popped;
    }
}

bool isValid(string s) {
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) {
                return false; // No matching opening parenthesis
            }
            char topChar = pop();
            if ((c == ')' && topChar != '(') || (c == ']' && topChar != '[') || (c == '}' && topChar != '{')) {
                return false; // Mismatched parentheses
            }
        }
    }

    return top == -1; // Stack should be empty for a valid string
}

int main() {
    string s = "(()())";
    if (isValid(s)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}
