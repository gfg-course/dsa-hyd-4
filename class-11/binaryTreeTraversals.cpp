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

vector<int> levelorder(Node* root) {
    if (root == NULL) {
        return {};
    }

    vector<int> result;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        result.push_back(curr->data);

        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }

    return result;
}

// TC: O(n)
// AS: O(n)
vector<vector<int>> levelByLevelTraversal(Node* root) {
    if (root == NULL) {
        return {};
    }

    vector<vector<int>> result;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        vector<int> currLevel;
        for (int i = 0; i < sz; i++) {
            Node* curr = q.front();
            q.pop();

            currLevel.push_back(curr->data);

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        result.push_back(currLevel);
    }

    return result;
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

    preorder(nodes[1]);
    cout << endl;
    postorder(nodes[1]);
    cout << endl;
    inorder(nodes[1]);
    cout << endl;

    vector<int> res = levelorder(nodes[1]);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    vector<vector<int>> res2= levelByLevelTraversal(nodes[1]);
    for (auto level : res2) {
        for (int i : level) {
            cout << i << " ";
        }
        cout << endl;
    }
}