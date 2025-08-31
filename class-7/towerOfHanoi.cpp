#include<bits/stdc++.h>
using namespace std;

int towerOfHanoiUtil(int n, string from, string helper, string target) {
    if (n == 0) {
        return 0;
    }

    int result = 0;
    result += towerOfHanoiUtil(n - 1, from, target, helper);
    
    cout << "Move disk " << n << " from " << from << " to " << target << endl;
    result++;

    result += towerOfHanoiUtil(n - 1, helper, from, target);
    return result;
}

// TC: O(2^n)
// AS: O(n)
int towerOfHanoi(int n) {
    return towerOfHanoiUtil(n, "A", "B", "C");
}

// TC: O(n)
// AS: O(n)
int towerOfHanoiWithoutPrint(int n) {
    if (n == 0) {
        return 0;
    }
    return 2*towerOfHanoiWithoutPrint(n - 1) + 1;
}

int main() {
    cout << towerOfHanoi(3) << endl;
    cout << towerOfHanoiWithoutPrint(3) << endl;
}