#include<bits/stdc++.h>
using namespace std;

int getNumStudents(vector<int> &books, int mid) {

    int numStudents = 1, numPages = 0;
    for (int i = 0; i < books.size(); i++) {
        if (numPages + books[i] > mid) {
            numStudents++;
            numPages = books[i];
        } else {
            numPages += books[i];
        }
    }

    return numStudents;
}

// TC: O(n * log(sum))
// AS: O(1)
int allocationMinPages(vector<int> books, int m) {
    int n = books.size();
    if (m > n) {
        return -1;
    }

    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        low = max(low, books[i]);
        high += books[i];
    }

    int result = high;
    while (low <= high) {
        int mid = (low + high)/2;

        int numStudents = getNumStudents(books, mid);
        if (numStudents <= m) {
            high = mid - 1;
            result = mid;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {

    cout << allocationMinPages({12, 34, 67, 90}, 2) << endl;
    cout << allocationMinPages({10, 20, 10, 30}, 2) << endl;
}