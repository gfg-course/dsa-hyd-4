#include<bits/stdc++.h>
using namespace std;

bool isMatched(char op, char cl) {
    return 
        (op == '(' && cl == ')') ||
        (op == '{' && cl == '}') ||
        (op == '[' && cl == ']');
}

// TC: O(n)
// AS: O(n)
bool checkBalanced(string s) {
    stack<char> helper;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            helper.push(s[i]);
        } else {
            if (helper.empty()) {
                return false;
            }
            char op = helper.top();
            helper.pop();
            if (!isMatched(op, s[i])) {
                return false;
            }
        }
    }

    return helper.empty();
}

int main() {
}