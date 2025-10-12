#include <iostream>
#include <stack>
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
    
    stack<Node *> s;
    Node *temp = head;

    // push all nodes except the last node into stack
    while (temp->next != NULL) {
        s.push(temp);
        temp = temp->next;
    }

    // make the last node as new head of the linked list
    head = temp;

    // pop all the nodes and append to the linked list
    while (!s.empty()) {
        
        // append the top value of stack in list
        temp->next = s.top();

        s.pop();

        temp = temp->next;
    }

    // update the next pointer of last node of stack to null
    temp->next = NULL;

    return head;
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