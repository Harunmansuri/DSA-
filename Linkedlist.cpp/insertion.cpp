#include <bits/stdc++.h>
using namespace std;
// creating a node
class Node
{
    // public access modifier
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// insert at head

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
// print linked list
void printHead(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}
void insertAtTail(Node *&head, int d)
{
    // Create new node
    Node *tailnode = new Node(d);

    // If list is empty, new node becomes the head
    if (head == NULL)
    {
        head = tailnode;
        return;
    }

    // Otherwise, traverse to the last node
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Link last node to the new node

    temp->next = tailnode;
    temp = tailnode;
}

void insertAtPosition(Node *&head, int d, int position)
{

    // Create new node
    Node *newNode = new Node(d);

    // If inserting at the head (position 0)
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse to the node just before the desired position
    Node *temp = head;
    while (temp != NULL && position > 1)
    {
        temp = temp->next;
        position--;
    }

    // If the position is beyond the current length, insert at the end
    if (temp == NULL)
    {
        insertAtTail(head, d);
        return;
    }

    // Insert the new node at the desired position
    newNode->next = temp->next;
    temp->next = newNode;
}

// length of linked list
int length(Node *&head)
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

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    int d;
    cin >> d;
    // insertAtHead(head,d);
    // insertAtTail(head,d);
    printHead(head);

    // cout<<length(head)<<endl;
}