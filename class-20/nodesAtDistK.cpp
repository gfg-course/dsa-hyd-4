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

void nodesAtDistKBelow(Node* root, int k, vector<int> &result) {
    if (k < 0) {
        return;
    }

    if (k == 0) {
        result.push_back(root->data);
        return;
    }
    nodesAtDistKBelow(root->left, k - 1, result);
    nodesAtDistKBelow(root->right, k - 1, result);
}

void getPathUtil(Node* root, int target, vector<Node*> &currPath, vector<Node*> &resPath) {
    if (root == NULL || resPath.size() > 0) {
        return;
    }

    currPath.push_back(root);
    if (root->data == target) {
        resPath = currPath;
        return;
    }

    getPathUtil(root->left, target, currPath, resPath);
    getPathUtil(root->right, target, currPath, resPath);

    currPath.pop_back();
}

vector<Node*> getPath(Node* root, int target) {

    vector<Node*> currPath, resPath;
    getPathUtil(root, target, currPath, resPath);
    return resPath;
}

// TC: O(n)
vector<int> nodesAtDistK(Node* root, int target, int k) {

    vector<Node*> path = getPath(root, target);
    int n = path.size();

    vector<int> result;
    nodesAtDistKBelow(path[n - 1], k, result);
    k--;

    for (int i = n - 2; i >= 0; i--) {
        if (k == 0) {
            result.push_back(path[i]->data);
        }
        else if (path[i + 1] == path[i]->right) {
            nodesAtDistKBelow(path[i]->left, k - 1, result);
        } else {
            nodesAtDistKBelow(path[i]->right, k - 1, result);
        }
        k--;
    }

    return result;
}

int main() {
}