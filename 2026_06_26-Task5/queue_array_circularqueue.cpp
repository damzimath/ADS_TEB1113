// Task04_Queue_Array.cpp
#include <iostream>
#include <string>
using namespace std;

#define CAPACITY 5

class QueueArray {
private:
    string arr[CAPACITY];
    int front;
    int rear;
    int count;

public:
    QueueArray() : front(0), rear(-1), count(0) {}

    void enqueue(string val) {
        if (count == CAPACITY) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % CAPACITY;
        arr[rear] = val;
        count++;
        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % CAPACITY;
        count--;
    }

    bool isEmpty() {
        return count == 0;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue (Front to Rear): ";
        for (int i = 0; i < count; i++) {
            int idx = (front + i) % CAPACITY;
            cout << arr[idx] << " ";
        }
        cout << endl;
    }
};

int main() {
    QueueArray queue;
    queue.enqueue("Aimar");
    queue.enqueue("Ahmad");
    queue.enqueue("Anajana");
    queue.display();

    queue.dequeue();
    queue.display();
    return 0;
}