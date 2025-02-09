
// a) Write down an iterative algorithm for linear search. Convert the iterative algorithm into a recursive one by answering the following question.
// i) Determine the size factor.
// ii) Determine base case(s).
// iii) Determine general case(s) and merge.
// iv) Verify the algorithm (three question method).

#include <iostream>
using namespace std;

int search(int a[], int n, int x, int i) {
    if (i < n) {
        if (a[i] == x) {
            return i;
        } else {
            return search(a, n, x, i + 1);
        }
    } else {
        return -1;
    }
}

int linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, x;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter the element to search: ";
    cin >> x;

    // Iterative
    cout << "Iterative: " << endl;
    int resultIterative = linearSearch(a, n, x);
    if (resultIterative == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << resultIterative << endl;
    }

    // Recursive
    cout << "Recursive: " << endl;
    int i = 0;
    int result = search(a, n, x, i);
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
    return 0;
}