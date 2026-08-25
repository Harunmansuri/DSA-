#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    int x;
    cout<<"enter the root eleemnt";
    cin>>x;
    int first;
    int second;
    queue<Node*>q;
    Node*root= new Node(x);
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout<<"enter the left child  of "<<temp->data<< " : "<<endl;
        cin>>first;
        if(first !=-1){
            temp->left = new Node(first);
            q.push(temp->left);
        }
        cout<<"enter the right child of"<<temp->data<< " : "<<endl;
        cin>>second;
        if(second !=-1){
            temp->right = new Node (second);
            q.push(temp->right);
        }
    }
}