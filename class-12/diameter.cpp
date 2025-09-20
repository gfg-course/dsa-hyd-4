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

// TC: O(n)
// AS: O(H)
int height(Node* root, unordered_map<Node*, int> &heights) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left, heights);
    int rightHeight = height(root->right, heights);

    heights[root] = 1 + max(leftHeight, rightHeight);
    return heights[root];
}

void diameterUtil(Node* root, int &result, unordered_map<Node*, int> &heights) {
    if (root == NULL) {
        return;
    }

    // Process the current node.
    int lh = heights[root->left];
    int rh = heights[root->right];
    result = max(result, lh + rh);

    diameterUtil(root->left, result, heights);
    diameterUtil(root->right, result, heights);
}

// TC: O(n)
// AS: O(n)
int diameterUsingHeights(Node* root) {

    // Precompute the heights of all the nodes.
    unordered_map<Node*, int> heights;
    height(root, heights);

    int result = 0;
    diameterUtil(root, result, heights);
    return result;
}

// ------------------------------------------------

int computeHeightAndMaintainDiameter(Node* root, int &diam) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = computeHeightAndMaintainDiameter(root->left, diam);
    int rightHeight = computeHeightAndMaintainDiameter(root->right, diam);

    diam = max(diam, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}


// TC: O(n)
// AS: O(H)
int diameterOptimal(Node* root) {
    int diam = 0;
    computeHeightAndMaintainDiameter(root, diam);
    return diam;
}


int main() {
}