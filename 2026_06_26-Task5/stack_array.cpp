// Task02_Stack_Array.cpp
#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 100

class StackArray {
private:
    string arr[MAX_SIZE];
    int topIndex;

public:
    StackArray() : topIndex(-1) {}

    void push(string val) {
        if (topIndex >= MAX_SIZE - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++topIndex] = val;
        cout << "Pushed: " << val << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped: " << arr[topIndex--] << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element: " << arr[topIndex] << endl;
        }
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (Top to Bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StackArray stack;
    stack.push("Aimar");
    stack.push("Ahmad");
    stack.push("Anajana");
    stack.display();

    stack.peek();
    stack.pop();
    stack.display();
    return 0;
}