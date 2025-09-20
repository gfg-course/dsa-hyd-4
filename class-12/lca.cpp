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

void getPathUtil(Node* root, int val, vector<int> &currPath, vector<int> &result) {
    if (root == NULL || result.size() > 0) {
        return;
    }

    currPath.push_back(root->data);
    if (root->data == val) {
        result = currPath;
    }

    getPathUtil(root->left, val, currPath, result);
    getPathUtil(root->right, val, currPath, result);
}

vector<int> getPath(Node* root, int val) {

    vector<int> currPath;
    vector<int> result;

    getPathUtil(root, val, currPath, result);
    return result;
}

// TC: O(n)
// AS: O(H)
int lca(Node* root, int n1, int n2) {

    vector<int> pathToN1 = getPath(root, n1);
    vector<int> pathToN2 = getPath(root, n2);

    int i = 0;
    while (i < pathToN1.size() && pathToN1[i] == pathToN2[i]) {
        i++;
    }

    return pathToN1[i - 1];
}

int main() {
}