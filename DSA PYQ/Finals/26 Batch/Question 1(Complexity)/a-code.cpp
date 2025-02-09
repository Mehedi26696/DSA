

// b) An n-square matrix array A is said to be symmetric if A [j, k] = A [k, j] for all j and k.Suppose A and B are two n-square symmetric matrices. 
//   Describe an efficient way of storing A and B in memory.

// We can store the upper triangular part of the matrix in a 1D array. The size of the array is n * (n + 1) / 2.
// The index of the element A[i][j] is i * (i + 1) / 2 + j.
// The index of the element B[i][j] is i * (i + 1) / 2 + j + n * (n + 1) / 2.
// The space complexity is O(n^2).
// The time complexity of accessing an element is O(1).


#include <iostream>
using namespace std;

// Function to calculate 1D index for (j, k)
int index(int j, int k) {
    return (j * (j + 1)) / 2 + k;
}

// Function to set a value in the 1D array
void set(int *arr, int n, int j, int k, int value) {
    if (j >= k) {
        arr[index(j, k)] = value;
    }
}

// Function to get a value from the 1D array
int get(int *arr, int n, int j, int k) {
    if (j >= k) {
        return arr[index(j, k)];
    } else {
        return arr[index(k, j)];  // Use symmetry
    }
}

// Function to display the full matrix
void display(int *arr, int n) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            cout << get(arr, n, j, k) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter matrix size (n): ";
    cin >> n;

    // Allocate memory for the 1D array
    int size = (n * (n + 1)) / 2;
    int *arr = new int[size];

    // Input values
    cout << "Enter values for the symmetric matrix:" << endl;
    for (int j = 0; j < n; j++) {
        for (int k = 0; k <= j; k++) { // Only input for lower triangle
            int val;
            cout << "A[" << j << "][" << k << "]: ";
            cin >> val;
            set(arr, n, j, k, val);
        }
    }

    // Display the full symmetric matrix
    cout << "\nSymmetric Matrix:\n";
    display(arr, n);

    // Free allocated memory
    delete[] arr;

    return 0;
}
