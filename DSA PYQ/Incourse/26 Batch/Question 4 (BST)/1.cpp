
// Question

// i) ·write a code to inseit an element in a Binary-Search Tree (BST);-Using- -J 0 this pseudo code, construct a BST with followin·g data.
// Data: 50, 30, 20, 40, 70, 60, 80

// ii) Write a pseudo code to delete an element in a BST. Using this pseudo code delete element a) 33, b) 80 and c) 77. You have to show the tree after each deletion.


// Answer

 

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

 

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

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
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
 
 

Node * deleteFromBST(Node* root , int key){
    if(root == NULL){
        return root;
    }

    if(key < root->data){
        root->left = deleteFromBST(root->left,key);
    }
    else if(key > root->data){
        root->right = deleteFromBST(root->right,key);
    }
    else{
        // case 1: Node to be deleted is leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // case 2: Node to be deleted has one child
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // case 3: Node to be deleted has two children
        Node* temp = InorderSuccessor(root,root->data);
        root->data = temp->data;
        root->right = deleteFromBST(root->right,temp->data);
    }
}


int main(){

    int n;
    cout<<"Enter the number of elements you want to insert in the BST: "<<endl;
    cin >> n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        insertIntoBST(root, x);
    }
    cout << "Inorder Traversal of the BST: ";
    inorder(root);

    cout << endl;

     int key;
    cout << "Enter key to delete : " << endl;
    cin >> key;

    root = deleteFromBST(root,key);
    
    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;
}