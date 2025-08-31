#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
void printNto1(int N) {
    if (N < 1) {
        return;
    }

    cout << N << endl;
    printNto1(N - 1);
}

void print1ToNUtil(int curr, int N) {
    if (curr > N) {
        return;
    }

    cout << curr << endl;
    print1ToNUtil(curr + 1, N);
}

void print1ToN(int N) {
    
    print1ToNUtil(1, N);
}

void print1ToN2(int N) {

    if (N < 1) {
        return;
    }

    print1ToN2(N - 1);
    cout << N << endl;
}

int main() {

    print1ToN2(5);
}