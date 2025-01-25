// search Node in BST

// Using recursive approach to search a node in a Binary Search Tree (BST)

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
    // base case
    if (root == NULL)
    {
        return false;
    }
    if (d == root->data)
    {
        return true;
    }
    else if (d > root->data)
    {
        // right subtree
        return search(root->right, d);
    }
    else
    {
        // left subtree
        return search(root->left, d);
    }

     
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


// Time complexity of search in BST is O(h) where h is the height of the tree. In the worst case, the height of the tree is n-1 where n is the number of nodes in the tree. Therefore, the worst-case time complexity of search in BST is O(n). In the best case, the height of the tree is log(n) where n is the number of nodes in the tree. Therefore, the best-case time complexity of search in BST is O(log(n)).

// The average-case time complexity of search in a BST is O(log n) where n is the number of nodes in the tree.

// Space complexity of search in BST is O(h) where h is the height of the tree. In the worst case, the height of the tree is n-1 where n is the number of nodes in the tree. Therefore, the worst-case space complexity of search in BST is O(n). In the best case, the height of the tree is log(n) where n is the number of nodes in the tree. Therefore, the best-case space complexity of search in BST is O(log(n)).