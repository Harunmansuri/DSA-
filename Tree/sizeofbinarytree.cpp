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

/*int size(Node *root, int &count)
{
    /*if (root == NULL)
    {
        return 0;
    }

    count++;

    size(root->left, count);
    size(root->right, count);

    return count;


}

*/
int size(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (1 + size(root->left) + size(root->right));
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

    int count = 0;

    //  int ans = size(root, count);
    int ans = size(root);

    cout << ans;
}