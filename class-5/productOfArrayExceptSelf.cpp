#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<int> productOfArrayExceptSelf(vector<int> arr) {
    
    int n = arr.size();

    vector<int> suffixProducts(n);
    
    suffixProducts[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffixProducts[i] = suffixProducts[i + 1] * arr[i + 1];
    }

    int prefixProduct = 1;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = prefixProduct * suffixProducts[i];
        prefixProduct *= arr[i];
    }

    return ans;
}

int main() {
    vector<int> result = productOfArrayExceptSelf({1, 2, 3, 4});
    vector<int> result2 = productOfArrayExceptSelf({-1, 1, 0, -3, 3});

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : result2) {
        cout << i << " ";
    }
    cout << endl;
}