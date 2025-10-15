#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *removeDuplicates(Node *head)
{
    Node *curr = head;

    // Traverse the list
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            // Duplicate found, delete next node
            Node *next_next = curr->next->next;
            delete curr->next;
            curr->next = next_next;
        }
        else
        {
            // Move to the next distinct element
            curr = curr->next;
        }
    }

    return head;
}
//tc -> O(n)
//sc -> O(1)
// Function to print the linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating sample linked list: 10 -> 12 -> 12 -> 15 -> 15
    Node *head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(12);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(15);

    cout << "Original list: ";
    print(head);

    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    print(head);

    return 0;
}
/*// C++ Program to remove duplicates from a
// sorted linked list

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

// Function to remove duplicates
void removeDuplicates(Node *head) {

    // Base case: if the list is empty, return
    if (head == NULL)
        return;

    // Check if the next node exists
    if (head->next != NULL) {

        // If current node has duplicate
        // data with the next node
        if (head->data == head->next->data) {
            head->next = head->next->next;
            removeDuplicates(head);
        }
        else{
            removeDuplicates(head->next);
        }
    }
}
    //tc -> O(n)
    //sc -> O(n) recursive stack space

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
//

int main() {

    // Create a sorted linked list
    // 11->11->11->13->13->20
    Node *head = new Node(11);
    head->next = new Node(11);
    head->next->next = new Node(11);
    head->next->next->next = new Node(13);
    head->next->next->next->next = new Node(13);
    head->next->next->next->next->next = new Node(20);

    cout << "Linked list before duplicate removal:" << endl;
    printList(head);

    removeDuplicates(head);

    cout << "Linked list after duplicate removal:" << endl;
    printList(head);

    return 0;
}*/

/*
// C++ Program to remove duplicates from a
// sorted linked list using Hashset

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node *removeDuplicates(Node *head) {
  
    // Unordered map to track unique node values
    unordered_set<int>st;

    // Initialize pointers for traversing the original list
    // and building the new list without duplicates
    Node *new_head = nullptr;
    Node *tail = nullptr;

    // Traverse the original list
    Node *curr = head;
    while (curr != nullptr) {
      
        // Check if the current node's data is not in the map
        if (st.find(curr->data) == st.end()) {
          
            // Create a new node for the unique data
            Node *new_node = new Node(curr->data);

            // If new_head is null, this is the
            // first unique node
            if (new_head == nullptr) {
                new_head = new_node;
                tail = new_head;
            }
            else {
                // Append the new node to the end
                // of the new list
                tail->next = new_node;
                tail = new_node;
            }

            // Mark this data as encountered
            st.insert(curr->data);
        }
      
        // Move to the next node in the original list
        curr = curr->next;
    }
  
    // Return the head of the new list with
    // duplicates removed
    return new_head;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
  
    // Create a sorted linked list
    // 11->11->11->13->13->20
    Node *head = new Node(11);
    head->next = new Node(11);
    head->next->next = new Node(11);
    head->next->next->next = new Node(13);
    head->next->next->next->next = new Node(13);
    head->next->next->next->next->next = new Node(20);

    cout << "Linked list before duplicate removal:" << endl;
    printList(head);

    head = removeDuplicates(head);

    cout << "Linked list after duplicate removal:" << endl;
    printList(head);

    return 0;
}
*/