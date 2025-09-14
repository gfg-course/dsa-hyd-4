#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
queue<int> reverse(queue<int> q) {

    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    return q;
}

int main() {
}