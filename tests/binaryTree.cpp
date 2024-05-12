#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = new Node(9);
    
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 1);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);
    
    cout << "Árbol binario en orden: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}
