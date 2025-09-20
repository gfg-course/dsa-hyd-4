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

void pushLeft(Node* root, stack<Node*> &s) {

    while (root != NULL) {
        s.push(root);
        root = root->left;
    }
}

// TC: O(n)
// AS: O(H)
void iterativeInorder(Node* root) {
    
    stack<Node*> s;

    pushLeft(root, s);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();

        cout << curr->data << " ";

        pushLeft(curr->right, s);
    }
}

int main() {
    vector<Node*> nodes(11);
    for (int i = 1; i <= 10; i++) {
        nodes[i] = new Node(i);
    }

    nodes[1]->left = nodes[2];
    nodes[2]->left = nodes[4];
    nodes[4]->left = nodes[7];
    nodes[2]->right = nodes[5];
    nodes[5]->left = nodes[8];
    nodes[1]->right = nodes[3];
    nodes[3]->left = nodes[6];
    nodes[6]->left = nodes[9];
    nodes[6]->right = nodes[10];

    inorder(nodes[1]);
    cout << endl;

    iterativeInorder(nodes[1]);
    cout << endl;
}