#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int sqrt(int n) {

    int low = 1, high = n;
    int result = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid * mid <= n) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    cout << sqrt(10) << endl;
    cout << sqrt(25) << endl;
    cout << sqrt(30) << endl;
}