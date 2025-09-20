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

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* constructUtil(vector<int> &inorder, int low, int high, vector<int> &postorder, int &postIdx) {
    if (low > high) {
        return NULL;
    }

    Node* root = new Node(postorder[postIdx]);
    postIdx--;

    // TODO: Optimize this search to O(1) by precomputing the following map:
    // {inorder[i] -> i}
    int inIdx = low;
    for (int i = low + 1; i <= high; i++) {
        if (inorder[i] == root->data) {
            inIdx = i;
            break;
        }
    }

    root->right = constructUtil(inorder, inIdx + 1, high, postorder, postIdx);
    root->left = constructUtil(inorder, low, inIdx - 1, postorder, postIdx);

    return root;
}

// TC: O(n^2)
// AS: O(H)
Node* constructUsingInorderAndPostorder(vector<int> inorder, vector<int> postorder) {

    int n = postorder.size();
    int postIdx = n - 1;

    return constructUtil(inorder, 0, n - 1, postorder, postIdx);
}

int main() {

    Node* root = constructUsingInorderAndPostorder({4, 8, 2, 5, 1, 6, 3, 7}, {8, 4, 5, 2, 6, 7, 3, 1});

    inorder(root);
    cout << endl;
    postorder(root);
}