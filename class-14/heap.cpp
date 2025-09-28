#include<bits/stdc++.h>
using namespace std;
// Max Heap

void print(vector<int> &heap) {
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;
}

// TC: O(log(n))
// AS: O(1)
void topDownHeapify(int i, vector<int> &heap) {

    int left = 2*i + 1;
    int right = 2*i + 2;

    int maxValueIndex = i;
    if (left < heap.size() && heap[left] > heap[maxValueIndex]) {
        maxValueIndex = left;
    }
    if (right < heap.size() && heap[right] > heap[maxValueIndex]) {
        maxValueIndex = right;
    }

    if (maxValueIndex != i) {
        swap(heap[i], heap[maxValueIndex]);
        topDownHeapify(maxValueIndex, heap);
    }
}

// TC: O(log(n))
// AS: O(1)
void deleteFromHeap(vector<int> &heap) {
    if (heap.size() == 0) {
        return;
    }

    // Step-1
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();

    // Step-2:
    topDownHeapify(0, heap);
}

// TC: O(log(n))
// AS: O(1)
void bottomUpHeapify(int i, vector<int> &heap) {
    int parent = (i - 1) / 2;
    
    if (parent >= 0 && heap[i] > heap[parent]) {
        swap(heap[i], heap[parent]);
        bottomUpHeapify(parent, heap);
    }
}

// TC: O(log(n))
// AS: O(1)
void insertInHeap(vector<int> &heap, int value) {

    // Step-1:
    heap.push_back(value);

    // Step-2:
    bottomUpHeapify(heap.size() - 1, heap);
}

int main() {

    vector<int> heap = {10, 5, 6, 2, 4};
    deleteFromHeap(heap);

    print(heap);

    vector<int> heap2 = {10, 5, 3, 2, 4};
    
    insertInHeap(heap2, 15);
    print(heap2);
    insertInHeap(heap2, 12);
    print(heap2);
}