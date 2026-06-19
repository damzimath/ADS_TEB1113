#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *next; // pointer variable, stores address
};

int main()
{
    // Node* head = new Node(); //head is pointer variable, stores a node address
    // Node* second = new Node();
    // Node* third = new Node();

    // head->data = "Aimar";
    // head->next = second;

    // second->data = "Ahmad";
    // second->next = third;

    // third->data = "anjana";
    // third->next = NULL;

    // // Traverse and print
    // Node* temp = head;

    // while (temp != NULL) {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }

    // return 0;

    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();

    node1->data = "Aimar";
    node1->next = node2;

    node2->data = "Ahmad";
    node2->next = node3;

    node3->data = "anjana";
    node3->next = NULL;

    Node *temp = node1;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}