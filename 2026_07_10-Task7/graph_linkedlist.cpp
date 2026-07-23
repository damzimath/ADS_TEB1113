// Task06_Graph_LinkedList.cpp
#include <iostream>
#include <queue>
using namespace std;

// Node in the adjacency list representing an edge destination
class AdjListNode {
public:
    int dest;
    AdjListNode* next;

    AdjListNode(int d) {
        dest = d;
        next = nullptr;
    }
};

// Linked List header for each vertex
class AdjList {
public:
    AdjListNode* head;

    AdjList() {
        head = nullptr;
    }
};

class Graph {
private:
    int numVertices;
    AdjList* array;

public:
    Graph(int vertices) {
        numVertices = vertices;
        array = new AdjList[numVertices];
    }

    ~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            AdjListNode* current = array[i].head;
            while (current != nullptr) {
                AdjListNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] array;
    }

    // Add an undirected edge between src and dest
    void addEdge(int src, int dest) {
        // Add edge from src to dest
        AdjListNode* newNode = new AdjListNode(dest);
        newNode->next = array[src].head;
        array[src].head = newNode;

        // Add edge from dest to src (undirected)
        newNode = new AdjListNode(src);
        newNode->next = array[dest].head;
        array[dest].head = newNode;
    }

    // Print adjacency list representation of graph
    void printGraph() {
        cout << "\nGraph Adjacency List:" << endl;
        for (int v = 0; v < numVertices; ++v) {
            AdjListNode* crawl = array[v].head;
            cout << "Vertex " << v << ":";
            while (crawl != nullptr) {
                cout << " -> " << crawl->dest;
                crawl = crawl->next;
            }
            cout << endl;
        }
    }

    // Breadth-First Search traversal from a starting vertex
    void BFS(int startVertex) {
        bool* visited = new bool[numVertices]{false};
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "\nBFS Traversal starting from vertex " << startVertex << ": ";

        while (!q.empty()) {
            int current = q.front();
            cout << current << " ";
            q.pop();

            AdjListNode* temp = array[current].head;
            while (temp != nullptr) {
                int adjVertex = temp->dest;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
                temp = temp->next;
            }
        }
        cout << endl;
        delete[] visited;
    }
};

int main() {
    // Create a graph with 5 vertices (0 to 4)
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();
    g.BFS(0);

    return 0;
}