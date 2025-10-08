#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertAttail(Node *&tail, int data)
{
    Node *newnode = new Node(data);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
int main()
{
    Node *node1 = new Node(10);
    // cout << node1->data << " " << endl;
    // cout << node1->prev << " " << endl;
    // cout << node1->next << " " << endl;
    Node *head = node1;
    Node *tail = node1;
    printList(head);
    insertAtHead(head, 12);
    printList(head);
     insertAtHead(head, 18);
    printList(head);
     insertAtHead(head, 16);
    printList(head);

    insertAttail(tail, 25);
    printList(head);

    return 0;
}