#include<bits/stdc++.h>
using namespace std;


// TC: O(n)
// AS: O(n)
int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

// TC: O(n)
// AS: O(1)
void factTailRecursive(int n, int &res) {
    if (n == 0) {
        return;
    }

    res *= n;
    factTailRecursive(n - 1, res);
}

int main() {

}