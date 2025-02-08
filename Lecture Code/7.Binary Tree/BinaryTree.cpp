

// Binary Tree
// Binary Tree is a tree in which each node has at most two children
// Binary Tree is a tree in which each node has at most two children, which are referred to as the left child and the right child

// Traversal approach:
// 1. Inorder Traversal: Left, Root, Right
// 2. Preorder Traversal: Root, Left, Right
// 3. Postorder Traversal: Left, Right, Root


// Binary Tree Example:
//        1
//       / \
//      2   3
//     / \ / \
//    4  5 6  7



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* findNode(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    Node* leftResult = findNode(root->left, key);
    if (leftResult != NULL) {
        return leftResult;
    }

    return findNode(root->right, key);
}

Node* insert(Node* root, int option, int key, int data) {
    if (root == NULL) {
        return NULL; // Key not found, so insertion cannot happen
    }

    // Find the node with the given key
    Node* targetNode = findNode(root, key);

    if (targetNode == NULL) {
        cout << "Key " << key << " not found. Cannot insert " << data << "." << endl;
        return root;
    }

    // Insert the new node as the left or right child
    if (option == 1) {
        if (targetNode->left == NULL) {
            targetNode->left = new Node(data);
        } else {
            cout << "Left child of node " << key << " already exists." << endl;
        }
    } else if (option == 2) {
        if (targetNode->right == NULL) {
            targetNode->right = new Node(data);
        } else {
            cout << "Right child of node " << key << " already exists." << endl;
        }
    }

    return root;
}

void printInorder(Node* node) {
    if (node == NULL) {
        return;
    }

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(Node* node) {
    if (node == NULL) {
        return;
    }

    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node* node) {
    if (node == NULL) {
        return;
    }

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

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


int main() {
    // Create the root node
    Node* root = new Node(1);

    // Insert nodes using the key
    root = insert(root, 1, 1, 2); // Insert 2 as the left child of node 1
    root = insert(root, 2, 1, 3); // Insert 3 as the right child of node 1
    root = insert(root, 1, 2, 4); // Insert 4 as the left child of node 2
    root = insert(root, 2, 2, 5); // Insert 5 as the right child of node 2
    root = insert(root, 1, 3, 6); // Insert 6 as the left child of node 3
    root = insert(root, 2, 3, 7); // Insert 7 as the right child of node 3

    cout << "Inorder: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder: ";
    printPreorder(root);
    cout << endl;

    cout << "Postorder: ";
    printPostorder(root);
    cout << endl;

    cout << "Printing the level order traversal output: " << endl;
    levelOrderTraversal(root);

    return 0;
}
