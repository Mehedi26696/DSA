//13
//13

#include <bits/stdc++.h>
using namespace std;

struct TernaryTree
{
    int data;
    TernaryTree *left;
    TernaryTree *middle;
    TernaryTree *right;

    // constructor

    TernaryTree(int data)
    {
        this->data = data;

        this->left = NULL;

        this->middle = NULL;

        this->right = NULL;
    }
};

// Function to find a TernaryTree with the given key in the tree
TernaryTree *khujtechi(TernaryTree *root, int key)
{
   /* if (!root)
    {
        return NULL; // If the tree is empty
    }

    if (root->data == key)
    {
        return root; // If the root TernaryTree has the key
    }*/

    if(! root || root->data == key) return root; // If the root TernaryTree

    TernaryTree *left = khujtechi(root->left, key); // Search in the left sub-tree

    if (left) return left;

    TernaryTree *middle = khujtechi(root->middle, key); // Search in the middle sub-tree

     if (middle) return middle;

    TernaryTree *right = khujtechi(root->right, key); // Search in the right sub-tree

     if (right) return right;

    return NULL; // If not found in any sub-tree
}

// Function to print the tree in the required order
void print(TernaryTree *root)
{
    if (!root)
        return;

    // Left Sub-tree
    print(root->left);
    // Middle Sub-tree
    print(root->middle);
    // TernaryTree Value
    cout << root->data << endl;
    // Right Sub-tree
    print(root->right);
}

int main()
{
    int r, n;
    cin >> r >> n;
    
    // root create
    TernaryTree *root = new TernaryTree(r);

    for(int i = 0; i < n; i++)
    {
        int op, key, val;
        cin >> op >> key >> val;

        // Find the TernaryTree with the given key
        TernaryTree *parent = khujtechi(root, key);
        /*
               if (parent) {
                   continue; // If the key is not found, ignore the command
               }

               // Create a new TernaryTree for the value
               

               // Assign the child to the correct position
               if (op == 0) {
               TernaryTree *child = new TernaryTree(val);
                   parent->left = child; // Add as left child
               } else if (op == 1) {
                   parent->middle = child; // Add as middle child
               } else if (op == 2) {
                   parent->right = child; // Add as right child
               }
               */

//check key exists or is not

        if (parent)
        {

  // left child

            if (op == 0)

            {

                parent->left = new TernaryTree(val);
            }

        // middle child
            else if (op == 1)
            {
                parent->middle = new TernaryTree(val);
            }

        // right child
            else if (op == 2)
            {
                parent->right = new TernaryTree(val);
            }
        }
    }

    print(root); // Print the tree in the required order

    return 0;
}