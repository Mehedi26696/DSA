
//Reverse Level Order traversal

// Create a Binary Tree

/*        1
        /   \
       3     5
      / \    / \
     7  11  17  NULL
*/

#include <bits/stdc++.h>
using namespace std;

// Node class to represent each node in the binary tree

class node
{
public:
    int data;       // Data stored in the node
    node *left;     // Pointer to the left child
    node *right;    // Pointer to the right child

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

// Function to perform reverse traversal of the binary tree

void reverseTraversal(node *root)
{
    queue<node *> q; // Queue to store the nodes for level order traversal
    stack<node *> s; // Stack to store the nodes for reverse level order traversal
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp->right)
        {
            q.push(temp->right);
        }

        if (temp->left)
        {
            q.push(temp->left);
        }
    }

    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
}

int main()
{
    node *root = NULL;
    // Creating tree
    root = buildtree(root);

    // Performing reverse traversal
    cout << "Reverse Traversal: ";
    reverseTraversal(root);

    // Output: Reverse Traversal: 7 11 17 3 5 1

    return 0;
}