#include<bits/stdc++.h>
using namespace std;

// TC: O(k^2 * log(k))
// AS: O(k)
vector<int> mergeKSortedArrays(vector<vector<int>> arr) {

    int k = arr.size();

    // {value, {i, j}} min heap
    priority_queue<pair<int, pair<int, int>>, 
                vector<pair<int, pair<int, int>>>, 
                greater<pair<int, pair<int, int>>>> pq;
    

    for (int i = 0; i < k; i++) {
        pq.push({arr[i][0], {i, 0}});
    }

    vector<int> result;

    while (!pq.empty()) {
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();

        int value = curr.first;
        int i = curr.second.first;
        int j = curr.second.second;

        result.push_back(value);
        if (j + 1 < k) {
            pq.push({arr[i][j + 1], {i, j + 1}});
        }
    }

    return result;
}

int main() {

    vector<int> result = mergeKSortedArrays({{1, 3, 5, 11},
                                             {2, 4, 7, 12},
                                             {1, 1, 3, 3},
                                             {13, 14, 15, 16}});
    
    for (int i : result) {
        cout << i << " ";
    }
}