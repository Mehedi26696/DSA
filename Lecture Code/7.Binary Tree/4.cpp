
// Reverse level order traversal of a binary tree

#include <iostream>
#include <queue>
#include <stack>
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

// Function to perform reverse level order traversal of the binary tree
void reverseLevelOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    stack<node *> s;
    q.push(root);
    q.push(NULL); // Marker for end of level

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL); // Add marker for next level
            }
            s.push(NULL); // Add marker to stack
        }
        else
        {
            s.push(temp);

            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }

    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();

        if (temp == NULL)
        {
            cout << endl; // Separator for levels
        }
        else
        {
            cout << temp->data << " ";
        }
    }
}


int main()
{
    node *root = NULL;
    // Creating tree
    root = buildtree(root);

    cout << "Reverse Level Order Traversal of the binary tree is: " << endl;
    reverseLevelOrderTraversal(root);

    return 0;
}
