#include<iostream>
#include<stack>
using namespace std;
int evaluate_exp(int b1,int b2,char op){
    switch(op){
        case '+':return b1+b2;
        case '-':return b1-b2;
        case '*':return b1*b2;
        case '/':return b1/b2;
    }
    return 0;
}
int main()
{
    string s="-*42/42";
    stack<int>st;
    int n=s.length();
   for (int i = n - 1; i >= 0; i--) {
    cout << "Processing character: " << s[i] << endl;
    if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
        st.push(s[i] - '0');
    } else {
        int b2 = st.top();
        st.pop();
        int b1 = st.top();
        st.pop();
        int r = evaluate_exp(b1, b2, s[i]);
        st.push(r);
        cout << "Stack after operation: ";
        stack<int> temp = st;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
}

    cout<<"prefix evaluation is:"<<st.top()<<endl;
    return 0;
}