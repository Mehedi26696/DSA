

// a) Write down a recursive algorithm to construct a binary tree from a given preorder and inorder traversing sequence of the tree. Apply this algorithm to construct binary tree from the
// given following sequences.
// Preorder sequence: ACEHBDGF

// Inorder sequence: HCBEDAGF

#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to build the binary tree recursively
Node* buildTreeHelper(const string& preorder, const string& inorder, 
                      int inStart, int inEnd, int& preIndex, unordered_map<char, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    // Select the current root from preorder traversal
    char rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    // Find the index of this root in the inorder sequence
    int inIndex = inMap[rootVal];

    // Recursively construct left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex, inMap);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex, inMap);

    return root;
}

// Wrapper function to build the tree
Node* buildTree(const string& preorder, const string& inorder) {
    unordered_map<char, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1, preIndex, inMap);
}

// Function for inorder traversal to verify correctness
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function for preorder traversal to verify correctness
void preorderTraversal(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    string preorder = "ACEHBDGF";
    string inorder = "ECAHBGDF";  // Corrected inorder sequence

    Node* root = buildTree(preorder, inorder);

    // Verify the reconstructed tree
    cout << "Inorder traversal of constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal of constructed tree: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}




