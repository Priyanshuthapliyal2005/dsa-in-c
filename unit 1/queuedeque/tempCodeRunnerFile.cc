#include <iostream>
#include <stack>

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
        int top = st2.top();
        st2.pop();
        return top;
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
};

void display(MyQueue* obj) {
    while (!obj->empty()) {
        int dequeuedElement = obj->pop();
        cout << "Dequeued: " << dequeuedElement << endl;
    }
}

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    
    cout << "Queue elements: ";
    display(obj);
    
    obj->push(4);
    cout << "Queue elements after push(4): ";
    display(obj);
    
    int param_2 = obj->pop();
    cout << "Popped element: " << param_2 << endl;
    
    int param_3 = obj->peek();
    cout << "Front element (peek): " << param_3 << endl;
    
    bool param_4 = obj->empty();
    cout << "Is the queue empty? " << (param_4 ? "Yes" : "No") << endl;

    return 0;
}
