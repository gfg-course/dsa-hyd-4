#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(vector<int> arr) {

    int n = arr.size();
    stack<int> s;
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {

        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = n;
        } else {
            result[i] = s.top();
        }

        s.push(i);
    }

    return result;
}

vector<int> prevSmallerElements(vector<int> arr) {

    int n = arr.size();
    stack<int> s;
    vector<int> result(n);

    for (int i = 0; i < n; i++) {

        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        s.push(i);
    }

    return result;
}

// TC: O(n)
// AS: O(n)
int maxArea(vector<int> heights) {

    vector<int> prevSmaller = prevSmallerElements(heights);
    vector<int> nextSmaller = nextSmallerElements(heights);

    int result = 0;
    for (int i = 0; i < heights.size(); i++) {
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        result = max(result, width * heights[i]);
    }

    return result;
}

int main() {

    cout << maxArea({6, 2, 5, 4, 5, 1, 6});
}