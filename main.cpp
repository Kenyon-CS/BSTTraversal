#include <iostream>
using namespace std;

// Node class representing a node in the binary search tree
class Node {
public:
    int key;
    Node* left;
    Node* right;

    // Constructor to initialize the node
    Node(int item) : key(item), left(nullptr), right(nullptr) {}
};

// Utility function to insert a new node with a given key into the BST
Node* insertNode(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);

    return root;
}

// In-order traversal: Left, Root, Right
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

// Pre-order traversal: Root, Left, Right
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Post-order traversal: Left, Right, Root
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->key << " ";
    }
}

// Main function to demonstrate BST insertion and traversals
int main() {
    Node* root = nullptr;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "In-order traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
