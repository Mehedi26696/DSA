// search Node in BST

// Using iterative approach to search a node in a Binary Search Tree (BST)

// Example:
//        10
//       /  \
//      5    15
//     / \   / \
//    3   7 12  20

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// Function to perform level order traversal of the binary tree
void levelOrderTraversal(Node *root)
{
    queue<Node *> q; // Queue to store the nodes for level order traversal
    q.push(root);

    // Separator to indicate end of current level
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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

Node *insertIntoBST(Node *&root, int d)
{
    // base case

    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        // right subtree

        root->right = insertIntoBST(root->right, d);
    }

    else
    {

        // left subtree
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

bool search(Node *&root, int d)
{

    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == d)
        {
            return true;
        }

        else if (d > temp->data)
        {
            temp = temp->right;
        }

        else
        {
            temp = temp->left;
        }
    }

    return false;
 
     
}

int main()
{
    Node *root = NULL;

    cout << "Enter Data to create BST : " << endl;

    takeInput(root);

    cout << "Printing the BST tree" << endl;

    levelOrderTraversal(root);

    int n;
    cout << "Enter the value you want to search :" << endl;
    cin >> n;

    if (search(root, n))
    {
        cout << "Value Present" << endl;
    }

    else
    {
        cout << "Value not present" << endl;
    }
    return 0;
}