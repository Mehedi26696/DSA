

// a) You are given a binary search tree, each node containing an integer, in which all internal nodes have two children and
// all leaves are in the same depth. Write the pseudocode of an efficient algorithm to find the median of the values stored in the binary search tree.
// Note that the median is the middle value in a set of data.

// Pseudocode
// 1. Find the number of nodes in the tree
// 2. Find the inorder traversal of the tree
// 3. Find the middle element of the inorder traversal
// 4. Return the middle element

// Time Complexity
// The time complexity of this algorithm is O(n) where n is the number of nodes in the tree. This is because we are traversing the tree inorder to find the median.

// Space Complexity
// The space complexity of this algorithm is O(n) where n is the number of nodes in the tree. This is because we are storing the inorder traversal of the tree in an array.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void inorderTraversal(Node *root, vector<int> &nodes)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, nodes);
    nodes.push_back(root->data);
    inorderTraversal(root->right, nodes);
}

int findMedian(Node *root)
{
    vector<int> nodes;
    inorderTraversal(root, nodes);
    return nodes[nodes.size() / 2];
}

int main()
{
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    cout << "Median: " << root->data << endl;

    cout << "Median: " << findMedian(root) << endl;
    return 0;
}
