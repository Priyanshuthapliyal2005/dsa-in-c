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
    case ')':
        return 3;
    default:
        return 0;
    }
}
int main() {
    string s = "a+b/(c-d)*e";
    stack<char> st;

    // Reverse the string
    reverse(s.begin(), s.end());

    int n=s.length();
    string ans="";
    for(int i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z')
        {
            ans+=s[i];
        }
        else{
            if(st.empty()) st.push(s[i]);
            else{
                if(prec(s[i])>prec(st.top()))st.push(s[i]);
                else{
                    while(!st.empty()&&prec(s[i])<=prec(st.top())){
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << "Prefix Expression: " << ans << endl;

    return 0;
}
