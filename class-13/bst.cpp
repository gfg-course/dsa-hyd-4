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

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// TC: O(H)
// AS: O(1) since the code is tail-recursive.
bool searchRec(Node* root, int value) {
    if (root == NULL) {
        return false;
    }

    if (root->data == value) {
        return true;
    }

    if (value < root->data) {
        return searchRec(root->left, value);
    } else {
        return searchRec(root->right, value);
    }
}

// TC: O(H)
// AS: O(1)
bool searchIterative(Node* root, int value) {

    while (root != NULL) {
        if (root->data == value) {
            return true;
        }

        if (value < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return false;
}

// TC: O(H)
// AS: O(H)
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

int getMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// TC: O(H)
// AS: O(H)
Node* deleteFromBst(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteFromBst(root->left, value);
    } else if (value > root->data) {
        root->right = deleteFromBst(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        }
        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }

        int inorderSucc = getMin(root->right);
        root->data = inorderSucc;
        root->right = deleteFromBst(root->right, inorderSucc);

        // int childCount = 0;
        // if (root->left != NULL) {
        //     childCount++;
        // } 
        // if (root->right != NULL) {
        //     childCount++;
        // }

        // if (childCount == 0) {
        //     return NULL;
        // }
        // if (childCount == 1) {
        //     if (root->left != NULL) {
        //         return root->left;
        //     } else {
        //         return root->right;
        //     }
        // }

        // int inorderSucc = getMin(root->right);
        // root->data = inorderSucc;
        // root->right = deleteFromBst(root->right, inorderSucc);
    }

    return root;
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

    root = insertInBst(root, 14);
    root = insertInBst(root, 12);

    cout << searchRec(root, 14) << endl;
    cout << searchRec(root, 7) << endl;
    cout << searchRec(root, 9) << endl;

    cout << searchIterative(root, 14) << endl;
    cout << searchIterative(root, 7) << endl;
    cout << searchIterative(root, 9) << endl;

    inorder(root);
    cout << endl;

    root = deleteFromBst(root, 14);
    root = deleteFromBst(root, 13);
    root = deleteFromBst(root, 15);

    inorder(root);
}