#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {

    }

    void push(int x) {
        int size = q.size();
        q.push(x);
        while (--size >= 0) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int r = q.front();
        q.pop();
        return r; // Return the popped element
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack s;
    cout << "Pushing 1, 2, and 3 onto the stack:" << endl;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element: " << s.top() << endl; // Output: Top element: 3

    cout << "Popping elements from the stack:" << endl;
    cout << "Popped: " << s.pop() << endl; // Output: Popped: 3
    cout << "Popped: " << s.pop() << endl; // Output: Popped: 2
    cout << "Popped: " << s.pop() << endl; // Output: Popped: 1

    cout << "Is the stack empty? " << (s.empty() ? "Yes" : "No") << endl; // Output: Is the stack empty? Yes
    
    return 0;
}
