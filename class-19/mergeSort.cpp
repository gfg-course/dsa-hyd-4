#include<bits/stdc++.h>
using namespace std;

void mergeSortUtil(int low, int high, vector<int> &arr) {
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;
    mergeSortUtil(low, mid, arr); // Sorts [low ... mid] in place
    mergeSortUtil(mid + 1, high, arr); // Sorts [mid + 1 ... high] in place

    vector<int> temp;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }
}

void mergeSort(vector<int> &arr) {

    mergeSortUtil(0, arr.size() - 1, arr);
}

int main() {
    vector<int> arr = {3, 5, 7, 2, 1, 6, 3, 8};
    mergeSort(arr);

    for (int i : arr) {
        cout << i << " ";
    }
}