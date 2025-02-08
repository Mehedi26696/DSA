
// b) Write a pseudocode to traverse a binary search tree such that the generated output is in  descending order.

// Pseudocode
// 1. Create a stack to store the nodes of the tree
// 2. Push the root node onto the stack
// 3. While the stack is not empty, do the following:

//     a. Pop the top node from the stack
//     b. Print the data of the node
//     c. If the right child of the node is not NULL, push the right child onto the stack
//     d. If the left child of the node is not NULL, push the left child onto the stack

// 4. Repeat step 3 until the stack is empty

// Another approach is to use the reverse inorder traversal of the tree to get the nodes in descending order.

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

void reverseInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    reverseInorder(root->right);
    cout << root->data << " ";
    reverseInorder(root->left);
}
void descendingOrder(Node *root)
{
    stack<Node *> s;
    Node *current = root;

    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->right;
        }

        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->left;
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Descending order traversal: ";
    descendingOrder(root);
    cout << endl;

    cout << "Reverse Inorder traversal: ";
    reverseInorder(root);
    cout << endl;

    return 0;
}