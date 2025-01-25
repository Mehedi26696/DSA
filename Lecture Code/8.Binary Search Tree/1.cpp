// Binary Search Tree means that the left child is smaller than the root, and the right child is larger than the root.

// Example:
//        10
//       /  \
//      5    15
//     / \   / \
//    3   7 12  20



#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
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




void takeInput(Node* &root){
    int data;
    cin>>data;

    while (data != -1)
    {
         insertIntoBST(root,data);
         cin>>data;
    }
    
}


int main(){
    Node * root = NULL;

    cout<<"Enter Data to create BST : "<<endl;

    takeInput(root);
     
    cout<<"Printing the BST tree"<<endl;

    levelOrderTraversal(root);
    
    cout<<"Printing Inorder: "<<endl;
    Inorder(root);
    cout<<endl;
    cout<<"Printing Preorder: "<<endl;
    Preorder(root);
    cout<<endl;
    cout<<"Printing Postorder: "<<endl;
    Postorder(root);

    return 0;

}

 
// Input: 10 5 15 3 7 12 20 -1
// Output:
// Printing the BST tree
// 10
// 5 15
// 3 7 12 20
// Printing Inorder:
// 3 5 7 10 12 15 20
// Printing Preorder:
// 10 3 5 7 12 15 20
// Printing Postorder:
// 3 5 7 12 15 20 10


// Time complexity for insertion in BST is O(h) where h is the height of the tree.
// In the worst case, the height of the tree is n, where n is the number of nodes in the tree. Therefore, the worst-case time complexity of insertion in a BST is O(n).
// The best-case time complexity of insertion in a BST is O(1) when the tree is empty.
// The average-case time complexity of insertion in a BST is O(log n) where n is the number of nodes in the tree.

// Space complexity for insertion in BST is O(h) where h is the height of the tree. In the worst case, the height of the tree is n, where n is the number of nodes in the tree. Therefore, the worst-case space complexity of insertion in a BST is O(n).

