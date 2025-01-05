
// preorder traversal
// preorder traversal is a type of depth-first traversal where the nodes are recursively visited in this order: root, left, right.

// Binary tree example:

//                1
//              /   \
//            3       5
//          /  \    /   \
//        7    11  17   19

// Preorder traversal: 1 3 7 11 5 17 19


// Preorder traversal of a binary tree using recursion

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

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " "; // Print the data of the root
    preorder(root->left);      // Recursively traverse the left subtree
    preorder(root->right);     // Recursively traverse the right subtree
}

// using iterative method

void preorderIteration(node *root)
{
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if (temp->right)
        {
            s.push(temp->right);
        }
        if (temp->left)
        {
            s.push(temp->left);
        }
    }
}



int main()
{
    node *root = NULL;
    root = buildtree(root);

    cout << "Preorder traversal of the binary tree: ";
    preorder(root);
    cout << endl;
    cout << "Preorder traversal of the binary tree using iteration: ";
    preorderIteration(root);

    return 0;
}

// Input example: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 19 -1 -1