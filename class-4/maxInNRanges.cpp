#include<bits/stdc++.h>
using namespace std;

// TC: O(n + maxx)
// AS: O(maxx)
int maxInNRanges(vector<int> L, vector<int> R) {

    int n = L.size();
    int maxx = R[0];
    for (int i = 1; i < n; i++) {
        maxx = max(maxx, R[i]);
    }

    vector<int> freq(maxx + 2, 0);

    for (int i = 0; i < n; i++) {
        freq[L[i]]++;
        freq[R[i] + 1]--;
    }

    int result = 0;
    for (int i = 1; i < freq.size(); i++) {
        freq[i] += freq[i - 1];

        if (freq[i] > freq[result]) {
            result = i;
        }
    }
    return result;
}

int main() {

    cout << maxInNRanges({1, 5, 6}, {3, 10, 9}) << endl;
}