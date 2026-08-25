#include <bits/stdc++.h>
using namespace std;

/*
=====================================================
                NODE CLASS
=====================================================

Har node ke andar 3 cheeze hoti hai:

1. data  -> node ki value
2. left  -> left child ka address
3. right -> right child ka address

Example:

        1
       / \
      2   3

Node 1:
data = 1
left = address of node 2
right = address of node 3

*/

class Node
{
public:
    int data;      // node ki value store karega
    Node *left;    // left child ka pointer
    Node *right;   // right child ka pointer

    // Constructor
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};


/*
=====================================================
                PREORDER TRAVERSAL
=====================================================

Traversal order:

ROOT -> LEFT -> RIGHT

Example:

        1
       / \
      2   3

Output:
1 2 3

Flow:
1. root print karo
2. left subtree me jao
3. right subtree me jao

*/

void preOrder(Node *root)
{
    // Base case
    // agar node NULL hai to wapas aa jao
    if (root == NULL)
    {
        return;
    }

    // Step 1 : root print
    cout << root->data << " ";

    // Step 2 : left subtree
    preOrder(root->left);

    // Step 3 : right subtree
    preOrder(root->right);
}



/*
=====================================================
                INORDER TRAVERSAL
=====================================================

Traversal order:

LEFT -> ROOT -> RIGHT

Example:

        1
       / \
      2   3

Output:
2 1 3

BST me inorder traversal
sorted order deta hai.

*/

void InOrder(Node *root)
{
    // Base case
    if (root == NULL)
    {
        return;
    }

    // Step 1 : left subtree
    InOrder(root->left);

    // Step 2 : root print
    cout << root->data << " ";

    // Step 3 : right subtree
    InOrder(root->right);
}



/*
=====================================================
                POSTORDER TRAVERSAL
=====================================================

Traversal order:

LEFT -> RIGHT -> ROOT

Example:

        1
       / \
      2   3

Output:
2 3 1

Mostly deletion me use hota hai
kyunki children pahle process hote hai.

*/

void PostOrder(Node *root)
{
    // Base case
    if (root == NULL)
    {
        return;
    }

    // Step 1 : left subtree
    PostOrder(root->left);

    // Step 2 : right subtree
    PostOrder(root->right);

    // Step 3 : root print
    cout << root->data << " ";
}



/*
=====================================================
            BINARY TREE CREATION
=====================================================

Input Example:

1
2
-1
-1
3
-1
-1

Tree:

        1
       / \
      2   3

Logic:

-1 means NULL node

Recursive flow:

1. value input lo
2. agar -1 hai -> NULL return
3. node banao
4. left child recursively banao
5. right child recursively banao

*/

Node *Binarytree()
{
    int x;

    cin >> x;

    // IMPORTANT

    // Agar -1 hai matlab node exist nahi karti
    // to NULL return karenge

    // TUMHARE CODE ME GALTI THI:
    // if(x != -1)
    // usse har valid node par NULL return ho raha tha

    // Correct:
    if (x == -1)
    {
        return NULL;
    }

    // new node create
    Node *temp = new Node(x);

    /*
    Recursive calls

    pahle left subtree banega
    fir right subtree
    */

    temp->left = Binarytree();

    temp->right = Binarytree();

    return temp;
}



/*
=====================================================
            LEVEL ORDER TRAVERSAL
=====================================================

Also called BFS

Level by level traversal

Example:

        1
       / \
      2   3
     / \
    4   5

Output:
1 2 3 4 5

QUEUE USE HOTI HAI

Flow:

1. root queue me dalo
2. queue se node nikalo
3. print karo
4. uske children queue me dalo

*/

vector<int> levelorder(Node *root)
{
    vector<int> ans;

    // edge case
    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;

    // first root insert
    q.push(root);

    while (!q.empty())
    {
        // queue ka front node nikalo
        Node *temp = q.front();

        q.pop();

        // node value answer me store
        ans.push_back(temp->data);

        // left child exist karta hai to push karo
        if (temp->left)
        {
            q.push(temp->left);
        }

        // right child exist karta hai to push karo
        if (temp->right)
        {
            q.push(temp->right);
        }
    }

    return ans;
}



/*
=====================================================
                    MAIN FUNCTION
=====================================================
*/

int main()
{
    /*
    INPUT:

    1 2 -1 -1 3 -1 -1

    Tree:

            1
           / \
          2   3
    */

    Node *root;

    cout << "Enter tree nodes (-1 for NULL): ";

    // tree creation
    root = Binarytree();


    /*
    =====================================================
                    PREORDER
    =====================================================
    */

    cout << "\nPreOrder : ";
    preOrder(root);


    /*
    =====================================================
                    INORDER
    =====================================================
    */

    cout << "\nInOrder : ";
    InOrder(root);


    /*
    =====================================================
                    POSTORDER
    =====================================================
    */

    cout << "\nPostOrder : ";
    PostOrder(root);


    /*
    =====================================================
                    LEVEL ORDER
    =====================================================
    */

    vector<int> ans = levelorder(root);

    cout << "\nLevel Order : ";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}