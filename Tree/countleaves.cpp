#include<bits/stdc++.h>
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

Node *buildTree()
{
    int x;

    cout << "Enter node value (-1 for NULL): ";
    cin >> x;

    if (x == -1)
    {
        return NULL;
    }

    Node *temp = new Node(x);

    cout << "Enter left child of " << x << " : ";
    temp->left = buildTree();

    cout << "Enter right child of " << x << " : ";
    temp->right = buildTree();

    return temp;
}

void countLeaves(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    // leaf node
    if (!root->left && !root->right)
    {
        count++;
        return;
    }

    countLeaves(root->left, count);

    countLeaves(root->right, count);
}
int countLeaves(Node*root){
      if(root == NULL){
        return 0;
      }
      if(!root->left && !root->right){
        return 1;
      }

      return (countLeaves(root->left)+countLeaves(root->right));
}

int main()
{
    Node *root = buildTree();

    int count = 0;

    countLeaves(root, count);

    cout << "Leaf Nodes : " << count;
}