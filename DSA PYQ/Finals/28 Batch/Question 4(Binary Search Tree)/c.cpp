
// c) Let, a binary search tree B has the property that all the nodes to the left of a node have lower values than it and those to the right have higher values.
//  You have to build a new tree from B where all the nodes to the left of a node have higher values and those to the right have lower values. 
// Write a pseudocode to an efficient algorithm to do so.

// Pseudocode
// 1. Create a new binary search tree
// 2. Traverse the original binary search tree in reverse inorder
// 3. Insert the nodes into the new binary search tree

// Time Complexity
// The time complexity of this algorithm is O(n) where n is the number of nodes in the tree. This is because we are visiting each node once.

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

Node* newinsert(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data >= root->data)
    {
        root->left = newinsert(root->left, data);
    }
    else
    {
        root->right = newinsert(root->right, data);
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


void mirrorBST(Node* root) {
    if (root == nullptr) return;
 
    swap(root->left, root->right);
    mirrorBST(root->left);
    mirrorBST(root->right);
}


void newTree(Node *root, Node *&newRoot)
{
    if (root == NULL)
    {
        return;
    }
    newTree(root->right, newRoot);
    newRoot = newinsert(newRoot, root->data);
    newTree(root->left, newRoot);
}


Node* buildInvertedTree(Node* root) {
    
    if (root == NULL) return NULL;

    Node* newRoot = createNode(root->data);

    newRoot->left = buildInvertedTree(root->right);

    newRoot->right = buildInvertedTree(root->left);

    return newRoot;

    
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    cout << "Original Tree: ";
    inorder(root);
    cout << endl;

    Node *newRoot = NULL;
    
    newTree(root, newRoot);

    cout << "New Tree: ";
    inorder(newRoot);
    cout << endl;

    cout<<"Another way to do it"<<endl;
    cout << "Original Tree: ";
    inorder(root);
    cout << endl;

    Node* invertedRoot = buildInvertedTree(root);
    cout << "New Tree: ";
    inorder(invertedRoot);
    cout << endl;

    cout<<"Anohther way to do it"<<endl;

    cout << "Original Tree: ";
    inorder(root);
    cout << endl;

    mirrorBST(root);

    cout << "New Tree: ";
    inorder(root);
    cout << endl;

   

    return 0;
}

