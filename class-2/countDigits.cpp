#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int countDigits(int n) {
    if (n == 0) {
        return 1;
    }

    int count = 0;
    while (n != 0) {
        n = n/10;
        count++;
    }

    return count;
}

// TC: O(n*log(n))
// AS: O(1)
int countDigitsIn1ToN(int n) {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        result += countDigits(i);
    }
    return result;
}

int main() {

    cout << countDigits(123) << endl;
    cout << countDigits(12300) << endl;
    cout << countDigits(0) << endl;
    cout << countDigits(5) << endl;
}