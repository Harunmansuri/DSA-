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

void deletion(Node *&head, int d) {
    // Edge case 1: Empty list
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    // Edge case 2: If head node itself holds the value to be deleted
    if (head->data == d) {
        Node *temp = head;
        head = head->next; // move head to next node
        temp->next = NULL; // unlink node from list
        delete temp;       // free memory
        return;
    }

    // Edge case 3: Deleting in between or last node
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL && curr->data != d) {
        prev = curr;
        curr = curr->next;
    }

    // If data not found
    if (curr == NULL) {
        cout << "Node with value " << d << " not found." << endl;
        return;
    }

    // Unlink the node
    prev->next = curr->next;
    curr->next = NULL;

    // Delete the node
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
    // Sample linked list: 10 -> 20 -> 30 -> 40 -> NULL
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original list: ";
    printList(head);

    // Deleting different positions
    deletion(head, 10); // delete head
    printList(head);

    deletion(head, 30); // delete middle node
    printList(head);

    deletion(head, 40); // delete last node
    printList(head);

    deletion(head, 100); // delete non-existent node
    printList(head);

    return 0;
}
