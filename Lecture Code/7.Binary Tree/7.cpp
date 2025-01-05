
// Postorder traversal of a binary tree
// Postorder traversal of a binary tree is defined as follows:
// 1. Traverse the left subtree in postorder.
// 2. Traverse the right subtree in postorder.
// 3. Visit the root node.

// Example of Binary Tree:
//                1
//              /   \
//            3       5
//          /  \    /   \
//        7    11  17   19

// Postorder traversal: 7 11 3 17 19 5 1

// Postorder traversal of a binary tree using recursion

#include<bits/stdc++.h>
using namespace std;

// Node class to represent each node in the binary tree

class node
{
public:
    int data;    // Data stored in the node
    node *left;  // Pointer to the left child
    node *right; // Pointer to the right child

    // Constructor to initialize the node with data
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build the binary tree

node *buildtree(node *root)
{
    cout << "Enter the data " << endl;
    int data;
    cin >> data;
    root = new node(data); // Create a new node with the input data

    // Base case for recursion
    if (data == -1)
    {
        return NULL; // If data is -1, this node is NULL
    }

    // Recursively build the left and right subtrees
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);

    return root; // Return the root of the subtree
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Traverse the left subtree in postorder
    postorder(root->left);

    // Traverse the right subtree in postorder
    postorder(root->right);

    // Visit the root node
    cout << root->data << " ";
}

// using iteration
void postorderIteration(node *root)
{
    stack<node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left)
        {
            s1.push(temp->left);
        }
        if (temp->right)
        {
            s1.push(temp->right);
        }
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main()
{
    node *root = NULL;
    root = buildtree(root);

    cout << "Postorder traversal of the binary tree is: ";
    postorder(root);
    cout << endl;

    cout << "Postorder traversal of the binary tree using iteration is: ";
    postorderIteration(root);

    return 0;
}

 // Example input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 19 -1 -1