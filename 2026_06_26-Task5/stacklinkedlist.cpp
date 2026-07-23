// Task01_Stack_LinkedList.cpp
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string val) : data(val), next(nullptr) {}
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() : top(nullptr) {}

    ~StackLinkedList() {
        while (top != nullptr) {
            pop();
        }
    }

    void push(string val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << val << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow (Empty Stack)" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped: " << temp->data << endl;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element: " << top->data << endl;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (Top to Bottom): ";
        Node* curr = top;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    StackLinkedList stack;
    stack.push("Aimar");
    stack.push("Ahmad");
    stack.push("Anajana");
    stack.display();
    
    stack.peek();
    stack.pop();
    stack.display();
    return 0;
}