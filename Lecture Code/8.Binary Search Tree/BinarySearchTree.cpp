

// Binary Search Tree 
// Binary Search Tree means that the left child is smaller than the root, and the right child is larger than the root.

// Example:
//        10
//       /  \
//      5    15
//     / \   / \
//    3   7 12  20

// Binary Search Tree Operations:
// 1. Insertion
// 2. Deletion
// 3. Searching
// 4. Traversal
//     a. Inorder
//     b. Preorder
//     c. Postorder
// 5. Finding Minimum and Maximum Value Node
// 6. Finding Inorder Predecessor and Inorder Successor

// Insertion approach:
// 1. If the root is NULL, create a new node and return it.
// 2. If the data is greater than the root, insert it into the right subtree.
// 3. If the data is smaller than the root, insert it into the left subtree.
// 4. Return the root.


// Deletion approach:
// 1. If the root is NULL, return NULL.
// 2. If the key is smaller than the root, delete the key from the left subtree.
// 3. If the key is greater than the root, delete the key from the right subtree.
// 4. If the key is equal to the root, then
//     a. If the node is a leaf node, delete the node.
//     b. If the node has one child, replace the node with its child.
//     c. If the node has two children, find the inorder successor or predecessor, replace the node with it, and delete the inorder successor or predecessor.

// Searching approach:
// 1. If the root is NULL, return false.
// 2. If the key is equal to the root, return true.
// 3. If the key is greater than the root, search in the right subtree.
// 4. If the key is smaller than the root, search in the left subtree.

// Traversal approach:
// 1. Inorder Traversal: Left, Root, Right
// 2. Preorder Traversal: Root, Left, Right
// 3. Postorder Traversal: Left, Right, Root

// Finding Minimum and Maximum Value Node:
// 1. Minimum Value Node: The leftmost node in the tree.
// 2. Maximum Value Node: The rightmost node in the tree.

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

void Preorder(Node* & root){
    // base case 
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    Inorder(root->left);
    Inorder(root->right);
}

void Postorder(Node* & root){
    // base case 
    if(root == NULL){
        return;
    }
    
    
    Inorder(root->left);
    Inorder(root->right);
    cout<<root->data<<" ";
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

bool search(Node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        return false;
    }
    if (d == root->data)
    {
        return true;
    }
    else if (d > root->data)
    {
        // right subtree
        return search(root->right, d);
    }
    else
    {
        // left subtree
        return search(root->left, d);
    }   
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
    Node* root = NULL;
    root = insertIntoBST(root, 5);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);
    insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    insertIntoBST(root, 7);

    cout<<"Level Order Traversal : "<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder Traversal : ";
    Inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal : ";
    Preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal : ";
    Postorder(root);

    cout<<endl;

    if(search(root, 4)){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

    Node* minNode = minValueNode(root);
    cout<<"Minimum Value Node : "<<minNode->data<<endl;

    Node* maxNode = maxValueNode(root);
    cout<<"Maximum Value Node : "<<maxNode->data<<endl;


    Node* pre = InorderPredecessor(root, 3);
    if(pre != NULL){
        cout<<"Inorder Predecessor of 4 : "<<pre->data<<endl;
    }
    else{
        cout<<"Inorder Predecessor of 4 : NULL"<<endl;
    }

    Node* suc = InorderSuccessor(root, 3);
    if(suc != NULL){
        cout<<"Inorder Successor of 4 : "<<suc->data<<endl;
    }
    else{
        cout<<"Inorder Successor of 4 : NULL"<<endl;
    }

    deleteFromBST(root, 3);
    cout<<"Inorder Traversal : ";
    Inorder(root);
    cout<<endl;

    cout<<"Level Order Traversal : "<<endl;
    levelOrderTraversal(root);
    return 0;
}


