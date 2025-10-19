#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Definition of a Node in the linked list
// --------------------------------------------
class Node
{
public:
    int data;   // Value of the node
    Node *next; // Pointer to the next node

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// --------------------------------------------
// Function to merge two sorted linked lists
// (without using extra space)
// --------------------------------------------
Node *merge(Node *&head1, Node *&head2)
{
    vector<int> ans;
    while (head1 != NULL)
    {
        ans.push_back(head1->data);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        ans.push_back(head2->data);
        head2 = head2->next;
    }

    sort(ans.begin(), ans.end());
    Node *dummy = new Node(-1);
    Node *curr = dummy;

    for (int i = 0; i < ans.size(); i++)
    {
        curr->next = new Node(ans[i]);
        curr = curr->next;
    }

    return dummy->next;
}

/*Node *merge(Node *&first, Node *&second)
{

    // If one of the lists is empty, return the other one
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    // Pointers for traversing both lists
    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    // Traverse both lists while both have nodes
    while (next1 != NULL && curr2 != NULL)
    {

        // Case 1: curr2 fits between curr1 and next1
        // i.e. curr1->data <= curr2->data <= next1->data
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {

            // Insert curr2 node between curr1 and next1
            curr1->next = curr2;

            // Save next pointer of curr2 (because we'll change curr2->next)
            next2 = curr2->next;

            // Link curr2 to next1 (complete the insertion)
            curr2->next = next1;

            // Move curr1 and curr2 forward
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // Case 2: curr2 doesn't fit here, move curr1 ahead
            curr1 = next1;
            next1 = next1->next;

            // If we reached end of first list,
            // simply attach remaining part of second list
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }

    // Return merged sorted list starting from 'first'
    return first;
}*/

// --------------------------------------------
// Function to print the linked list
// --------------------------------------------
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

// --------------------------------------------
// Main Function
// --------------------------------------------
int main()
{
    // Create first sorted linked list: 1 -> 3 -> 5 -> 7
    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);

    // Create second sorted linked list: 2 -> 4 -> 6 -> 8
    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(9);
    head2->next->next->next = new Node(8);

    // Decide which list to use as base (the one with smaller first element)
    Node *mergedHead = NULL;
    if (head1->data > head2->data)
    {
        mergedHead = merge(head2, head1);
    }
    else
    {
        mergedHead = merge(head1, head2);
    }

    // Print final merged sorted linked list
    cout << "Merged Sorted Linked List: ";
    printList(mergedHead);

    return 0;
}