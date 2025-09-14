#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n*log(n))
vector<string> generateNBinaryNumbers(int n) {
    queue<string> q;
    vector<string> result;

    q.push("1");
    int pushes = 1;

    while (pushes < n) {

        string curr = q.front();
        q.pop();
        
        result.push_back(curr);

        q.push(curr + "0");
        q.push(curr + "1");
        pushes += 2;
    }

    while (result.size() != n) {
        string curr = q.front();
        q.pop();
        
        result.push_back(curr);
    }

    return result;
}

// TC: O(n)
// AS: O(1)
vector<string> generateNBinaryNumbersUsingArrayAsQueue(int n) {
    vector<string> result;

    result.push_back("1");
    int front = 0;

    while (result.size() < n) {

        string curr = result[front];
        front++;

        result.push_back(curr + "0");
        result.push_back(curr + "1");
    }

    if (result.size() == n + 1) {
        result.pop_back();
    }

    return result;
}

int main() {

    vector<string> result = generateNBinaryNumbersUsingArrayAsQueue(10);

    for (string i : result) {
        cout << i << endl;
    }
}