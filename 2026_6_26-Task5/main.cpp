#include <iostream>
#include <string>

using namespace std;

// 1. The Node represents each individual element in the stack
class Node {
public:
    string name;
    Node* next;

    // Constructor to easily create new nodes
    Node(string n) {
        name = n;
        next = NULL;
    }
};

// 2. The Stack class manages the nodes using LIFO principles
class Stack {
private:
    Node* top; // Pointer to keep track of the top element

public:
    Stack() {
        top = NULL;
    }

    // PUSH: Add a new element to the top of the stack
    void push(string new_name) {
        Node* newNode = new Node(new_name);
        newNode->next = top; // The new node points to the current top
        top = newNode;       // The top is updated to the new node
        cout << "Pushed: " << new_name << endl;
    }

    // POP: Remove the element from the top of the stack
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;        // Store the current top temporarily
        top = top->next;         // Move the top pointer down to the next node
        cout << "Popped: " << temp->name << endl;
        delete temp;             // Free up the memory to prevent leaks
    }

    // PEEK: Look at the top element without removing it
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << top->name << endl;
        }
    }

    // Helper method to display the whole stack
    void display() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "\nCurrent Stack (Top to Bottom):" << endl;
        Node* current = top;
        while (current != NULL) {
            cout << current->name << endl;
            current = current->next;
        }
        cout << "---------------------------" << endl;
    }
};

int main() {
    Stack myStack;

    // Pushing elements onto the stack
    myStack.push("Aimar");
    myStack.push("Ahmad");
    myStack.push("Anajana");
    myStack.push("Jessy");

    // Displaying the stack (Notice it prints in reverse order: LIFO)
    myStack.display();

    // Peeking at the top element
    myStack.peek();

    // Popping the top element ("Jessy" will be removed)
    myStack.pop();

    // Displaying the stack after popping
    myStack.display();

    return 0;
}