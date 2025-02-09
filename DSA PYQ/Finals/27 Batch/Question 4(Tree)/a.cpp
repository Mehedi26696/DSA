
 

 // Consider the given tree,

 //         8
//       /   \
//      ?    10 
//     / \     \
//    1  6     14
//      / \    /
//     4   7  13

// a) Which value in the "?" node would make the above tree a binary tree but not a binary search tree.
// b) Use an appropriate value P in the "?" node to make it a binary search tree. 
// c) Reconstruct two binary search trees after deleting P using both "in-order predecessor and in-order successor" schemes.
 
// Answer:
// a)  11 or 9 can be used to make the above tree a binary tree but not a binary search tree. 

// b) 3 can be used to make it a binary search tree. cause 3 is less than 8 and 6, and greater than 1.

// c) Now tree look like:

//         8
//       /   \
//      3    10
//     / \     \
//    1  6     14
//      / \    /
//     4   7  13

// In-order predecessor scheme:

//         8
//       /   \
//      1    10
//       \     \
//        6     14
//       / \    /
//      4   7  13

// In-order successor scheme:

//         8
//       /   \
//      4    10
//     / \     \
//    1  6     14
//       \    /
//        7  13
