#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<int> nextGreaterElements(vector<int> arr) {

    int n = arr.size();
    stack<int> s;
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {

        // This loop will run `n` number of times summed up through all the 
        // outer iterations.
        while (!s.empty() && s.top() < arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        s.push(arr[i]);
    }

    return result;
}

int main() {

    vector<int> result = nextGreaterElements({6, 8, 0, 1, 3});
    for (int i  : result) {
        cout << i << " ";
    }
}