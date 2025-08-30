#include<bits/stdc++.h>
using namespace std;


// TC: O(n)
// AS: O(n)
int getNumOfSubarraysWithEqual0sAnd1s(vector<int> arr) {
    int n = arr.size();

    unordered_map<int, int> sumFreq;
    int sum = 0;
    int result = 0;

    sumFreq[0] = 1;
    for (int i = 0; i < n; i++) {
        sum += arr[i] == 0 ? -1 : +1;
        result += sumFreq[sum];
        sumFreq[sum]++;
    }

    return result;
}
 
int main() {
    cout << getNumOfSubarraysWithEqual0sAnd1s({1, 0, 0, 1, 0, 1, 1}) << endl;
    cout << getNumOfSubarraysWithEqual0sAnd1s({1, 1, 1, 1, 0}) << endl;
}