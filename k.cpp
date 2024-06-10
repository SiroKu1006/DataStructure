#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(Node* root, int data) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == data) {
        cout << root->data << "\n";
        return true;
    }
    cout << root->data << "->";
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int main() {
    Node* root = nullptr;
    int arr[] = {35, 1, 7, 20, 3, 8, 41, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    int target = 8;
    if (search(root, target)) {
        cout << "Found " << target << "\n";
    } else {
        cout << "Not found " ;
    }e
    return 0;
}