#include <iostream>
using namespace std;

int top = -1;

void push(char s[], int &n, char v)
{
    if (top < 99)
    {
        top++;
        s[top] = v;
    }
    else
    {
        cout << "stack is full" << endl;
    }
}

void pop(char s[])
{
    if (top == -1)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        top--;
    }
}

bool empty()
{
    return top == -1;
}

char top_element(char s[])
{
    if (top == -1)
    {
        return '\0'; // Return null character if the stack is empty
    }
    return s[top];
}

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
    case ')':
        return 3;
    default:
        return 0;
    }
}

int main()
{
    string s = "a+b/(c-d)*e";
    int n = s.length();
    string ans = "";
    char stack[100];

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += s[i];
        }
        else
        {
            if (s[i] == '(')
            {
                push(stack, n, s[i]);
            }
            else if (s[i] == ')')
            {
                while (!empty() && top_element(stack) != '(')
                {
                    ans += top_element(stack);
                    pop(stack);
                }
                if (!empty() && top_element(stack) == '(')
                {
                    pop(stack); // Pop the '(' from the stack
                }
                else
                {
                    cout << "Unbalanced parentheses" << endl;
                    // return 1; // Exit with an error code
                }
            }
            else
            {
                while (!empty() && prec(s[i]) <= prec(top_element(stack)) && top_element(stack) != '(')
                {
                    ans += top_element(stack);
                    pop(stack);
                }
                push(stack, n, s[i]);
            }
        }
    }

    while (!empty())
    {
        ans += top_element(stack);
        pop(stack);
    }

    cout << "Postfix Expression: " << ans << endl;
    return 0;
}
