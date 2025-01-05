// Given an array representation of a complete binary tree, where the root node is stored at index 0, and for any node at index i, its left child is located at index 2i + 1 and its right 
//child at index 2i + 2, develop an efficient algorithm to perform an inorder traversal of the binary tree without explicitly reconstructing the tree structure.
// The algorithm should return a list of elements in the inorder sequence, where "inorder" is defined as visiting the left subtree, then the root, and finally the right subtree.


#include<bits/stdc++.h>
using namespace std;
void traverse(int arr[], int index, int n) {
    if (index >= n) {
        return;
    }
    int leftIndex = 2 * index + 1;
    if (leftIndex < n) {
        traverse(arr, leftIndex, n);
    }
    cout << arr[index] << " ";
    int rightIndex = 2 * index + 2;
    if (rightIndex < n) {
        traverse(arr, rightIndex, n);
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    traverse(arr, 0, n);
    cout << endl;
    return 0;
}