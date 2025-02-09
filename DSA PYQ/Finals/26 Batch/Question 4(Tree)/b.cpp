


// b) Write down the algorithms to find the following from a given binary search tree.
// i) The largest element of the tree
// ii) The smallest element of the tree
// iii) The inorder successor of a given key of the tree
// iv) Sorted list of the keys of the given tree.

// i) The largest element of the tree
// The largest element of the tree is the rightmost element of the tree. So, we can find the largest element by traversing 
// the right subtree of the tree until we reach the rightmost element.

// Algorithm to find the largest element of the tree:
// 1. Start from the root of the tree.
// 2. Traverse the right subtree of the tree until we reach the rightmost element.
// 3. The rightmost element is the largest element of the tree.

// ii) The smallest element of the tree
// The smallest element of the tree is the leftmost element of the tree. So, we can find the smallest element by traversing
// the left subtree of the tree until we reach the leftmost element.

// Algorithm to find the smallest element of the tree:
// 1. Start from the root of the tree.
// 2. Traverse the left subtree of the tree until we reach the leftmost element.
// 3. The leftmost element is the smallest element of the tree.


// iii) The inorder successor of a given key of the binary search tree

// Algorithm to find the inorder successor of a given key in a binary search tree:
// 1. If the right subtree of the node is not NULL, then the inorder successor is the leftmost node in the right subtree.
// 2. If the right subtree of the node is NULL, then the inorder successor is the lowest ancestor of the node whose left child is also an ancestor of the node.

// iv) Sorted list of the keys of the given tree
// To get the sorted list of the keys of the given binary search tree, we can perform an inorder traversal of the tree.
// Inorder traversal of a binary search tree visits the nodes in sorted order.

// Algorithm to get the sorted list of the keys of the given binary search tree:
// 1. Perform an inorder traversal of the binary search tree.
// 2. Store the keys of the nodes in a list in the order they are visited.
// 3. The list of keys will be sorted in ascending order.


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void Inorder(Node* & root){
    // base case 
    if(root == NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
Node* insertIntoBST(Node* & root ,int d){
    //base case

    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data ){
        // right subtree

        root->right = insertIntoBST(root->right , d);
    }

    else{

        // left subtree
        root->left = insertIntoBST(root->left,d);
    }

    return root;
}

Node * minValueNode(Node* node) 
{ 
    Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) {
        current = current->left; 
    }
         
    return current; 
}

Node * maxValueNode(Node* node) 
{ 
    Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->right != NULL) {
        current = current->right; 
    }
         
    return current; 
}


Node * InorderPredecessor(Node* root, int key){
    Node* pre = NULL;
    Node* current = root;
    while(current != NULL){
        if(current->data == key){
            if(current->left != NULL){
                pre = current->left;
                while(pre->right != NULL){
                    pre = pre->right;
                }
            }
            return pre;
        }
        else if(current->data < key){
            pre = current;
            current = current->right;
        }
        else{
            current = current->left;
        }
    }
    return pre;
}


Node * InorderSuccessor(Node* root, int key){
    Node* suc = NULL;
    Node* current = root;
    while(current != NULL){
        if(current->data == key){
            if(current->right != NULL){
                suc = current->right;
                while(suc->left != NULL){
                    suc = suc->left;
                }
            }
            return suc;
        }
        else if(current->data < key){
            current = current->right;
        }
        else{
            suc = current;
            current = current->left;
        }
    }
    return suc;
}

void sortedList(Node* root, vector<int> &sorted){
    if(root == NULL){
        return;
    }
    sortedList(root->left,sorted);
    sorted.push_back(root->data);
    sortedList(root->right,sorted);
}

int main() {
    Node* root = NULL;
    root = insertIntoBST(root, 5);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);
    insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    insertIntoBST(root, 7);

    

    cout<<"Inorder Traversal : ";
    Inorder(root);
    cout<<endl;
    Node* minNode = minValueNode(root);
    cout<<"Minimum Value Node : "<<minNode->data<<endl;

    Node* maxNode = maxValueNode(root);
    cout<<"Maximum Value Node : "<<maxNode->data<<endl;


    Node* pre = InorderPredecessor(root, 3);
    if(pre != NULL){
        cout<<"Inorder Predecessor of 3 : "<<pre->data<<endl;
    }
    else{
        cout<<"Inorder Predecessor of 3 : NULL"<<endl;
    }

    Node* suc = InorderSuccessor(root, 3);
    if(suc != NULL){
        cout<<"Inorder Successor of 3 : "<<suc->data<<endl;
    }
    else{
        cout<<"Inorder Successor of 3 : NULL"<<endl;
    }

    cout<<"Sorted List of the keys : ";
    vector<int> sorted;
    sortedList(root,sorted);

    for(int i = 0; i < sorted.size(); i++){
        cout<<sorted[i]<<" ";
    }
    return 0;
}





