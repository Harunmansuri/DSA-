#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int total1(Node *root, int &Sum)
{
    if (root == NULL)
    {
        return 0;
    }

    Sum += root->data;

    total1(root->left, Sum);
    total1(root->right, Sum);

    return Sum;
}

int total(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (root->data + total(root->left) + total(root->right));
    /*
    Time Complexity
O(N)

Har node ek baar visit ho raha hai.

Space Complexity
O(H)

H = height of tree
(recursion stack)*/
}
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

int main()
{
    Node *root = buildTree();

    int Sum = 0;

    int ans1 = total1(root, Sum);
    int ans = total(root);

    cout << ans1 << endl;
    cout << ans << endl;
}