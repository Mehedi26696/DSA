// Delete a node in BST

// Example:
//       10
//      /  \
//     5    15
//    / \    /  \
//   3  7  12   20

// Delete 5
//       10
//      /  \
//     3    15
//        \    /  \
//         7  12   20

 

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


void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
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

int main()
{
    Node *root = NULL;

    cout << "Enter Data to create BST : " << endl;

    takeInput(root);

    cout << "Inorder Traversal : ";
    Inorder(root);
    cout << endl;

    int key;
    cout << "Enter key to delete : ";
    cin >> key;

    root = deleteFromBST(root,key);
    
    cout << "Inorder Traversal : ";
    Inorder(root);
    cout << endl;
    return 0;
}



