// Inorder traversal of a binary tree

// Inorder means left, root, right
// So, we first go to the leftmost node, then print the root, then go to the rightmost node

// Binary tree example:
//
//                1
//              /   \
//            3       5
//          /  \    /   \
//        7    11  17   19

// Inorder traversal: 7 3 11 1 17 5 19

// Inorder traversal of a binary tree using recursion


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

void inorder(node *root){
    // Base case
    if(root == NULL){
        return;
    }

    // Recursive case
    inorder(root->left); // First go to the leftmost node

    cout << root->data << " "; // Print the root

    inorder(root->right); // Go to the rightmost node
}

// using iterative approach

void inorderIteration(node *root)
{  
    stack<node *> s;
    node *curr = root;

    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}



int main()
{
    node *root = NULL;
    root = buildtree(root);

    cout << "Inorder traversal of the binary tree is: ";
    inorder(root);
    cout << endl;
    cout << "Inorder traversal of the binary tree using iterative approach is: ";
    inorderIteration(root);

    return 0;
}

// Example input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 19 -1 -1