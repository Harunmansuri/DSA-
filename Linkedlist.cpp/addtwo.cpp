#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to reverse a linked list
Node* reverse(Node *head) {
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL) {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Function to add two linked lists (numbers represented as digits)
Node* add(Node *head1, Node *head2) {
    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    int carry = 0;

    while (curr1 != NULL || curr2 != NULL || carry) {
        int sum = 0;
        if (curr1) {
            sum += curr1->data;
            curr1 = curr1->next;
        }
        if (curr2) {
            sum += curr2->data;
            curr2 = curr2->next;
        }

        sum += carry;
        carry = sum / 10;

        Node *newNode = new Node(sum % 10);
        temp->next = newNode;
        temp = temp->next;
    }

    return dummy->next;
}

// Function to print the linked list
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // First linked list represents 10 -> 2 -> 8 (i.e., 1028)
    Node *head1 = new Node(1);
    head1->next = new Node(0);
    head1->next->next = new Node(1);

    // Second linked list represents 9 -> 2 -> 8 (i.e., 928)
    Node *head2 = new Node(2);
   

    // Reverse both lists to start addition from least significant digit
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* ans = add(head1, head2);
    ans = reverse(ans); // reverse the result to get final number

    printList(ans);
}
