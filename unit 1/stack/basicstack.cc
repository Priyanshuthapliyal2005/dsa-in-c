#include <iostream>
using namespace std;

int top = -1;

void push(int st[], int v, int &size) {
    if (top == size - 1) {
        cout << "Stack overflow" << endl;
    } else {
        top++;
        st[top] = v;
    }
}

void pop(int st[]) {
    if (top == -1) {
        cout << "Stack underflow" << endl;
    } else {
        top--;
    }
}
void displaypeek(int st[], int &size){
    if (top == size - 1) {
        cout << "Stack overflow" << endl;
    } else if (top == -1) {
        cout << "Stack underflow" << endl;
    }
    cout<<st[top];
}
void display(int st[]) {
    if (top == -1) {
        cout << "Stack underflow" << endl;
    } else {
        cout << "Elements in stack:"<<endl;
        for (int i = top; i >= 0; i--) {
            cout << " " << st[i]<<endl;
        }
        cout << endl;
    }
}
void sizi(int st[]){
    int j=0;
    for (int i = top; i >= 0; i--) {
            j++;
        }
        cout<<"size of stack: "<<j<<endl;
}
void clear(int st[]){
    for (int i = top; i >= 0; i--) {
            top--;
        }
}
int main() {
    int size;
    cout << "Enter the number of elements you want to store in the stack: ";
    cin >> size;

    int *stack = new int[size]; // Dynamically allocate memory for the stack

    while (true) {
        cout << "1. Push\n2. Pop\n3. Display\n4.Peek\n5.size\n6.clear\n7. Quit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter the value to push: ";
                cin >> value;
                push(stack, value, size);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                displaypeek(stack,size);
                break;
            case 5:
                sizi(stack);
                break;
            case 6:
                clear(stack);
                break;
            case 7:
                delete[] stack; // Free the dynamically allocated memory
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
