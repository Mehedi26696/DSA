
// a) Given two binary search trees, each node containing an integer, having no element in common, 
// write a pseudocode of an efficient algorithm that merges the trees into a combined binary search tree containing elements from both trees.


// Pseudocode
// 1. Create a new empty binary search tree.
// 2. Traverse the first tree in inorder and insert each element into the new tree.
// 3. Traverse the second tree in inorder and insert each element into the new tree.
// 4. Return the new tree.

// Time Complexity
// The time complexity of this algorithm is O(n + m), where n and m are the number of nodes in the first and second trees, respectively.

// Space Complexity
// The space complexity of this algorithm is O(n + m), where n and m are the number of nodes in the first and second trees, respectively.


#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to merge two binary search trees
void inorderInsert(Node* root, Node*& mergedRoot) {
    if (root != NULL) {
        inorderInsert(root->left, mergedRoot);
        mergedRoot = insertNode(mergedRoot, root->data);
        inorderInsert(root->right, mergedRoot);
    }
}

Node* mergeTrees(Node* root1, Node* root2) {
    Node* mergedRoot = NULL;
    inorderInsert(root1, mergedRoot);
    inorderInsert(root2, mergedRoot);
    return mergedRoot;
}

// Function to do inorder traversal of a binary search tree

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Creating the first binary search tree
    Node* root1 = NULL;
    root1 = insertNode(root1, 5);
    insertNode(root1, 3);
    insertNode(root1, 7);
    insertNode(root1, 2);
    insertNode(root1, 4);
    insertNode(root1, 6);
    insertNode(root1, 8);
    cout << "Inorder traversal of the first binary search tree: ";
    inorderTraversal(root1);
    cout << endl;

    // Creating the second binary search tree
    Node* root2 = NULL;
    root2 = insertNode(root2, 10);
    insertNode(root2, 9);
    insertNode(root2, 1);
    insertNode(root2, 11);
    insertNode(root2, 13);
    cout << "Inorder traversal of the second binary search tree: ";
    inorderTraversal(root2);
    cout << endl;

    // Merging the two binary search trees
    Node* mergedRoot = mergeTrees(root1, root2);

    // Printing the merged binary search tree
    cout << "Inorder traversal of the merged binary search tree: ";
    inorderTraversal(mergedRoot);

    return 0;
}