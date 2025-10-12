#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

Node *reverseList(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    // reverse the rest of linked list and put
    // the first element at the end
    Node *rest = reverseList(head->next);

    // Make the current head as last node of
    // remaining linked list
    head->next->next = head;

    // Update next of current head to NULL
    head->next = NULL;

    return rest;
}

void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data;
        if (node->next)
            cout << " -> ";
        node = node->next;
    }
}

int main() {

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = reverseList(head);
    printList(head);

    return 0;
}