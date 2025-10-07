#include <bits/stdc++.h>

using namespace std;
// creating a node
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};
int main()
{
    // creating a new node
    Node *node1 = new Node(10);
    Node *Head = node1;

    // cout<<Head->data<<endl;
    // cout<<Head->next<<endl;
}