#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInBst(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (root->data == value) {
        return root;
    }

    if (value < root->data) {
        root->left = insertInBst(root->left, value);
    } else {
        root->right = insertInBst(root->right, value);
    }

    return root;
}

// TC: O(n)
// AS: O(H)
bool isBstUtil(Node* root, int lower, int upper) {
    if (root == NULL) {
        return true;
    }

    return 
        root->data >= lower && root->data <= upper &&
        isBstUtil(root->left, lower, root->data - 1) && 
        isBstUtil(root->right, root->data + 1, upper);
}

bool isBst(Node* root) {
    return isBstUtil(root, -1e9, 1e9);
}

int main() {
    Node* root = insertInBst(NULL, 10);
    root = insertInBst(root, 5);
    root = insertInBst(root, 15);
    root = insertInBst(root, 2);
    root = insertInBst(root, 7);
    root = insertInBst(root, 13);
    root = insertInBst(root, 20);
    root = insertInBst(root, 6);
    root = insertInBst(root, 12);
    root = insertInBst(root, 18);
    root = insertInBst(root, 25);

    cout << isBst(root) << endl;

    root->left->right->right = new Node(11);

    cout << isBst(root) << endl;
}