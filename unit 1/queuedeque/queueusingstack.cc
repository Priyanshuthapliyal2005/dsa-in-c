#include<bits/stdc++.h>
//queue ->fifo
using namespace std;

class MyQueue {
public:
    stack<int> st1; // For enqueue
    stack<int> st2; // For dequeue

    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int front = st2.top();
        st2.pop();
        return front;
    }
    
    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }

    void display() {
        stack<int> temp = st2;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        temp = st1;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    MyQueue q;
    cout << "Enqueuing 1, 2, and 3 into the queue:" << endl;
    q.push(1);
    q.display();

    q.push(2);
    q.display();

    q.push(3);
    q.display();


    cout << "Queue elements: ";
    q.display();

    cout << "Front element: " << q.peek() << endl;

    cout << "Dequeuing elements from the queue:" << endl;
    cout << "Dequeued: " << q.pop() << endl;
    cout << "Dequeued: " << q.pop() << endl;
    cout << "Dequeued: " << q.pop() << endl;

    cout << "Is the queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
