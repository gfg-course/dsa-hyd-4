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

class LinkedList {
    public:
    Node* head;

    // TC: O(1)
    // AS: O(1)
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // TC: O(n)
    // AS: O(1)
    void insertAtEnd(int data) {
        if (head == NULL) {
            insertAtBeginning(data);
            return;
        }

        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new Node(data);
    }

    // TC: O(pos)
    // AS: O(1)
    void insertAtPos(int pos, int data) {
        if (pos == 0 || head == NULL) {
            insertAtBeginning(data);
            return;
        }

        Node* curr = head;
        int hops = 0;
        while (hops < pos - 1 && curr->next != NULL) {
            curr = curr->next;
            hops++;
        }

        Node* newNode = new Node(data);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    // TC: O(1)
    // AS: O(1)
    void deleteFromBeginning() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete(temp);
    }

    // TC: O(n)
    // AS: O(1)
    void deleteFromEnd() {
        if (head == NULL || head->next == NULL) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = NULL;

        delete(toDelete);
    }

    // TC: O(pos)
    // AS: O(1)
    void deleteFromPos(int pos) {
        if (pos <= 0 || head == NULL || head->next == NULL) {
            deleteFromBeginning();
            return;
        }

        int hops = 0;
        Node* curr = head;

        while (hops < pos - 1 && curr->next->next != NULL) {
            curr = curr->next;
            hops++;
        }

        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete(temp);
    }

    // TC: O(n)
    // AS: O(1)
    void reverse() {

        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
    }

    // TC: O(n)
    // AS: O(1)
    int getMiddle() {
        if (head == NULL) {
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }


    // TC: O(n)
    // AS: O(1)
    void print() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

Node* isPalindromeUtil(Node* curr, Node* head, bool &result) {
    if (curr == NULL) {
        return head;
    }

    Node* toCompare = isPalindromeUtil(curr->next, head, result);
    if (curr->data != toCompare->data) {
        result = false;
    }

    return toCompare->next;
}

// TC: O(n)
// AS: O(n)
bool isPalindrome(Node* head) {
    bool result = true;
    isPalindromeUtil(head, head, result);
    return result;
}

int main() {
    LinkedList* ll = new LinkedList();
    ll->insertAtBeginning(3);
    ll->insertAtBeginning(2);
    ll->insertAtBeginning(1);

    ll->print();

    ll->insertAtBeginning(0);

    ll->print();

    ll->insertAtEnd(4);
    ll->insertAtEnd(5);
    ll->print();

    ll->insertAtPos(3, 7); // 0 1 2 7 3 4 5
    ll->insertAtPos(0, -1); // -1 0 1 2 7 3 4 5
    ll->insertAtPos(1000, 6); // -1 0 1 2 7 3 4 5 6
    ll->print();

    ll->deleteFromBeginning();
    ll->print();

    ll->reverse();
    ll->print();

}