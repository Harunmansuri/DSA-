#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

void deleteAtPosition(Node *&head, int position) {
    // Edge Case 1: Empty list
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    // Edge Case 2: Invalid position
    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }

    // Edge Case 3: Delete head (position 0)
    if (position == 0) {
        Node *temp = head;
        head = head->next; // move head to next node
        temp->next = NULL;
        delete temp;       // free old head
        return;
    }

    // Traverse to the node before the desired position
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < position) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    // Edge Case 4: Position out of range
    if (curr == NULL) {
        cout << "Position out of range." << endl;
        return;
    }

    // Unlink the node and delete
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create linked list: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Original list: ";
    printList(head);

    // Delete node at position 0 (head)
    deleteAtPosition(head, 0);
    printList(head);

    // Delete node at position 2 (middle)
    deleteAtPosition(head, 2);
    printList(head);

    // Delete node at last position (tail)
    deleteAtPosition(head, 2); 
    printList(head);

    // Try deleting at invalid position
    deleteAtPosition(head, 10);
    printList(head);

    return 0;
}
