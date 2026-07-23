#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    
    Node(string val) : data(val), next(nullptr) {}
};

int main() {
    // 1. Creation of Nodes
    Node* node1 = new Node("Aimar");
    Node* node2 = new Node("Ahmad");
    Node* node3 = new Node("anjana");
    Node* node4 = new Node("Jessy");

    // 2. Structuring the Connections
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    // Circular Link: Point the last node back to the head (node1) instead of NULL
    node4->next = node1;

    // 3. Traversal and Display
    Node* head = node1;
    Node* temp = head;

    cout << "Traversing Circular Linked List:" << endl;
    
    // Loop through the circular list using a do-while loop
    if (head != nullptr) {
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head); // Stop when we circle back to the start node
        
        cout << "(Back to Head: " << temp->data << ")" << endl;
    }

    // 4. Free allocated memory to prevent memory leaks
    // Unlink the circular connection first so we can delete linearly
    node4->next = nullptr; 
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
