#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// TC: O(n)
// AS: O(1)
bool detectLoop(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

void removeLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    if (fast == NULL || fast->next == NULL) {
        return;
    }

    // Handling the case of complete loop when the meeting
    // point is the head (x = 0 case).
    if (slow == head) {
        while (slow->next != head) {
            slow = slow->next;
        }
        slow->next = NULL;
        return;
    }

    fast = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

void print(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    cout << detectLoop(n1) << endl;

    n6->next = n3;

    cout << detectLoop(n1) << endl;

    removeLoop(n1);
    cout << detectLoop(n1) << endl;

    print(n1);

    n6->next = n1;
    cout << detectLoop(n1) << endl;
    removeLoop(n1);
    cout << detectLoop(n1) << endl;

    print(n1);

    n1->next = n1;
    cout << detectLoop(n1) << endl;
    removeLoop(n1);
    cout << detectLoop(n1) << endl;

    print(n1);
}