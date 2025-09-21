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

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

Node* buildBstUtil(vector<int> &arr, int low, int high) {
    if (low > high) {
        return NULL;
    }

    int mid = (low + high) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBstUtil(arr, low, mid - 1);
    root->right = buildBstUtil(arr, mid + 1, high);
    return root;
}

// TC: O(n)
// AS: O(log(n))
Node* buildBst(vector<int> arr) {
    return buildBstUtil(arr, 0, arr.size() - 1);
}

int main() {

    Node* root = buildBst({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    preorder(root);
}