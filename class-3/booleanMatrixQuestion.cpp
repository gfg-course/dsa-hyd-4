#include<bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// AS: O(1)
void updateRowsAndColsToZeros(vector<vector<int>> &arr) {

    int n = arr.size();
    int m = arr[0].size();

    bool zerothRowContainsZero = false;
    bool zerothColContainsZero = false;

    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 0) {
            zerothRowContainsZero = true;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            zerothColContainsZero = true;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                // Update the row and col bucket to 0
                arr[i][0] = 0; // row bucket
                arr[0][j] = 0; // col bucket
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            // If row or col bucket is 0 -> update arr[i] to 0
            if (arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    if (zerothRowContainsZero) {
        for (int j = 0; j < m; j++) {
            arr[0][j] = 0;    
        }
    }
    if (zerothColContainsZero) {
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }
}

int main() {

    vector<vector<int>> arr = 
        {
            {1, 0, 1, 1, 1},
            {1, 0, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 0, 0},
            {1, 1, 1, 1, 1}
        };

    updateRowsAndColsToZeros(arr);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


}