
// Level Order traversal
 
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

// Function to perform level order traversal of the binary tree
void levelOrderTraversal(node *root)
{
    queue<node *> q; // Queue to store the nodes for level order traversal
    q.push(root);

    // Separator to indicate end of current level
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // Level traversal complete
            cout << endl;
            if (!q.empty())
            {
                // Queue still has some child nodes
                q.push(NULL); // Add separator for the next level
            }
        }
        else
        {
            cout << temp->data << " "; // Print the data of the current node

            // Push the left and right children of the current node to the queue
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root = NULL;
    // Creating tree
    root = buildtree(root);
    // Example input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // Printing tree
    cout << "Printing the level order traversal output: " << endl;
    levelOrderTraversal(root);

    // Output: 1 3 5 7 11 17

    return 0;
}