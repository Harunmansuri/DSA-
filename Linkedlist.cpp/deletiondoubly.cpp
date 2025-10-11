#include <bits/stdc++.h>
using namespace std;

// ------------------- Node Class -------------------
class Node {
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor (used to show when memory is freed)
    ~Node() {
        int val = this->data;
        if (next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory freed for node with data " << val << endl;
    }
};

// ------------------- Utility Functions -------------------

// Print the entire linked list
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Calculate length of the list
int getLength(Node *head) {
    Node *temp = head;
    int len = 0;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// ------------------- Insertion Functions -------------------

// Insert a new node at the HEAD
void insertAtHead(Node *&head, Node *&tail, int data) {
    // Create new node
    Node *newNode = new Node(data);

    // Case 1: Empty list (both head and tail are NULL)
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Case 2: At least one node already exists
    newNode->next = head; // new node’s next becomes current head
    head->prev = newNode; // current head’s prev points to new node
    head = newNode;       // update head to the new node
}

// Insert a new node at the TAIL
void insertAtTail(Node *&head, Node *&tail, int data) {
    Node *newNode = new Node(data);

    // Case 1: Empty list
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Case 2: Normal case
    tail->next = newNode; // old tail’s next points to new node
    newNode->prev = tail; // new node’s prev points to old tail
    tail = newNode;       // update tail
}

// Insert a node at a given POSITION (1-based index)
void insertAtPosition(Node *&head, Node *&tail, int position, int data) {
    // Case 1: Insert at head
    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    int len = getLength(head);

    // Case 2: Insert at or after tail
    if (position > len) {
        insertAtTail(head, tail, data);
        return;
    }

    // Case 3: Insert somewhere in the middle
    Node *newNode = new Node(data);
    Node *temp = head;
    int cnt = 1;

    // Traverse to (position - 1) node
    while (cnt < position - 1 && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    // Connect new node with neighbors
    newNode->next = temp->next;
    newNode->prev = temp;

    // If inserting not at the end, update next node’s prev
    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode; // inserting at end, update tail

    temp->next = newNode;
}

// ------------------- Deletion Function -------------------
void deleteNode(Node *&head, Node *&tail, int position) {
    // Case 1: Empty list
    if (head == NULL) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    int len = getLength(head);

    // Case 2: Invalid position
    if (position <= 0 || position > len) {
        cout << "Invalid position.\n";
        return;
    }

    // Case 3: Deleting the first node (head)
    if (position == 1) {
        Node *temp = head;

        // If only one node in the list
        if (head->next == NULL) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;   // move head forward
            head->prev = NULL;   // remove backward link
            temp->next = NULL;   // isolate temp node
        }

        delete temp; // free memory
        return;
    }

    // Case 4: Deleting the last node (tail)
    if (position == len) {
        Node *temp = tail;

        tail = tail->prev;   // move tail backward
        tail->next = NULL;   // break next link
        temp->prev = NULL;   // isolate temp
        delete temp;
        return;
    }

    // Case 5: Deleting a middle node
    Node *curr = head;
    int cnt = 1;

    while (cnt < position) {
        curr = curr->next;
        cnt++;
    }

    // Re-link neighbors
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    // Isolate the node
    curr->next = NULL;
    curr->prev = NULL;

    // Delete the node
    delete curr;
}

// ------------------- Main Function -------------------
int main() {
    Node *head = NULL;
    Node *tail = NULL;

    // Insert operations
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 15);
    insertAtTail(head, tail, 5);

    cout << "List after insertions: ";
    printList(head);
    cout << "Head: " << head->data << " Tail: " << tail->data << endl;

    // Insert at a specific position
    insertAtPosition(head, tail, 3, 20);
    cout << "After inserting 20 at position 3: ";
    printList(head);

    cout << "Length: " << getLength(head) << endl;

    // Deleting nodes one by one
    deleteNode(head, tail, 1); // delete head
    cout << "After deleting position 1: ";
    printList(head);
    if (head)
        cout << "Head: " << head->data << " ";
    if (tail)
        cout << "Tail: " << tail->data << endl;

    deleteNode(head, tail, 3); // delete middle node
    cout << "After deleting position 3: ";
    printList(head);

    deleteNode(head, tail, getLength(head)); // delete last node
    cout << "After deleting last node: ";
    printList(head);

    if (head)
        cout << "Head: " << head->data << " Tail: " << tail->data << endl;
    else
        cout << "List is now empty.\n";

    return 0;
}
