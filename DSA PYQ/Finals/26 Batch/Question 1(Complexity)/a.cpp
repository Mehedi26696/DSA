
 
// a) We all know the basic design of a backpack. What kind of data structure is this backpack? What operations does it support? What are the complexities of those operations?
// b) An n-square matrix array A is said to be symmetric if A [j, k] = A [k, j] for all j and k.Suppose A and B are two n-square symmetric matrices. 
//   Describe an efficient way of storing A and B in memory.
// c) Distinguish among O, and -notation. Order the following terms in ascending order O(n), O(100), O(n logn), O(log n), O(n)
 

// a) The backpack is a stack. It supports the following operations:
// 1. push: O(1)
// 2. pop: O(1)
// 3. top: O(1)
// 4. empty: O(1)


// b) We can store the upper triangular part of the matrix in a 1D array. The size of the array is n * (n + 1) / 2.
//    The index of the element A[i][j] is i * (i + 1) / 2 + j.
//    The index of the element B[i][j] is i * (i + 1) / 2 + j + n * (n + 1) / 2.
//    The space complexity is O(n^2).
//    The time complexity of accessing an element is O(1).

// c) O(100) < O(log n) < O(n) < O(n log n) < O(n^2)





