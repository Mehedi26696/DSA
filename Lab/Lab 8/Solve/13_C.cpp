//13
//13

#include <bits/stdc++.h>
using namespace std;

struct Tree {

    // structure 
    int data;
    Tree *left;
    Tree *right;

    Tree(int data) {
        this->data = data;
        
        // left and right pointer

        this->left = NULL;

        this->right = NULL;
    }
};

// Function to find a tree with the given key in the tree

Tree* khujtechi(Tree *root, int key) {
    if (!root || root->data == key) return root;
    
   
   // search in left 
    
    Tree *left = khujtechi(root->left, key); // Search in the left sub-tree

    if(left) return left;

     // search in right

    Tree *right = khujtechi(root->right, key); // Search in the right sub-tree

    if(right) return right;

    return NULL; // If not found in any sub-tree
}

// Function to check if two trees are equal

bool soman(Tree *FirstTree, Tree *SecondTree) {

    // both tree empty

    if (!FirstTree && !SecondTree) return true;

    // one tree empty

    if (!FirstTree || !SecondTree)  return false;

    // data not equal
    
    if(FirstTree->data != SecondTree->data)  return false;

    bool  l = soman(FirstTree->left, SecondTree->left);

    bool  r = soman(FirstTree->right, SecondTree->right);


   // return l && r;

    bool result = l && r;

    return result;



}

int main(){
    
    int first, firstLength;
    // first tree input
    cin >> first >> firstLength;
    Tree *FirstTree = new Tree(first);

    //

    for (int i = 0; i < firstLength; i++) {

        // option , key , value input
        int op, key, val;
        cin >> op >> key >> val;

        // parent finding
        Tree *tree = khujtechi(FirstTree, key);

        if (tree) {

            // left child
            if (op == 0) {
                 tree->left = new Tree(val);
            } 
            // right child
            else {
                tree->right = new Tree(val);
            }
        }
    }


    int second, secondLength;

    // second tree input
    cin >> second >> secondLength;
    Tree *SecondTree = new Tree(second);
    for (int i = 0; i < secondLength; i++) {

        // option, key, value input
        int op, key, val;
        cin >> op >> key >> val;

        // parent finding
        Tree *tree = khujtechi(SecondTree, key);

        if (tree) {
            // left child
            if (op == 0) {
                tree->left = new Tree(val);
            } 
            // right child
            else {
                tree->right = new Tree(val);
            }
        }
    }

    // result
 
    cout << soman(FirstTree, SecondTree) << endl;

    return 0;
}