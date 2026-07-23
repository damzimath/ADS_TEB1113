// Task03_Queue_LinkedList.cpp
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string val) : data(val), next(nullptr) {}
};

class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    QueueLinkedList() : front(nullptr), rear(nullptr) {}

    ~QueueLinkedList() {
        while (front != nullptr) {
            dequeue();
        }
    }

    void enqueue(string val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow (Empty Queue)" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue (Front to Rear): ";
        Node* curr = front;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    QueueLinkedList queue;
    queue.enqueue("Aimar");
    queue.enqueue("Ahmad");
    queue.enqueue("Anajana");
    queue.display();

    queue.dequeue();
    queue.display();
    return 0;
}