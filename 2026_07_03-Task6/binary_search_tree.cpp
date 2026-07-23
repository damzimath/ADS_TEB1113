// Task05_BST_Tree.cpp
#include <iostream>
#include <string>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Helper for recursive insertion
    TreeNode* insertRecursive(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = insertRecursive(node->right, val);
        }

        return node;
    }

    // Helper for recursive search
    bool searchRecursive(TreeNode* node, int val) {
        if (node == nullptr) return false;
        if (node->data == val) return true;

        if (val < node->data) {
            return searchRecursive(node->left, val);
        }
        return searchRecursive(node->right, val);
    }

    // Traversals
    void inOrderRecursive(TreeNode* node) {
        if (node != nullptr) {
            inOrderRecursive(node->left);
            cout << node->data << " ";
            inOrderRecursive(node->right);
        }
    }

    void preOrderRecursive(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderRecursive(node->left);
            preOrderRecursive(node->right);
        }
    }

    void postOrderRecursive(TreeNode* node) {
        if (node != nullptr) {
            postOrderRecursive(node->left);
            postOrderRecursive(node->right);
            cout << node->data << " ";
        }
    }

    // Helper for memory cleanup in destructor
    void clear(TreeNode* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        clear(root);
    }

    void insert(int val) {
        root = insertRecursive(root, val);
        cout << "Inserted: " << val << endl;
    }

    void search(int val) {
        if (searchRecursive(root, val)) {
            cout << "Value " << val << " found in the BST." << endl;
        } else {
            cout << "Value " << val << " NOT found in the BST." << endl;
        }
    }

    void printInOrder() {
        cout << "In-Order Traversal (Sorted): ";
        inOrderRecursive(root);
        cout << endl;
    }

    void printPreOrder() {
        cout << "Pre-Order Traversal: ";
        preOrderRecursive(root);
        cout << endl;
    }

    void printPostOrder() {
        cout << "Post-Order Traversal: ";
        postOrderRecursive(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert nodes
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "\n--- BST Traversals ---" << endl;
    bst.printInOrder();
    bst.printPreOrder();
    bst.printPostOrder();

    cout << "\n--- Search Operations ---" << endl;
    bst.search(40);
    bst.search(90);

    return 0;
}