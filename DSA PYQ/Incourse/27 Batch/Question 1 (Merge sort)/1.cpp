
//Quesion: merge two sorted array

//solution:
#include <iostream>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    int res[n + m];
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            res[k]=arr1[i];
            i++;
        }
        else
        {
            res[k]=arr2[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        res[k]=arr1[i];
        i++;
        k++;
    }
    while (j < m)
    {
        res[k]=arr2[j];
        j++;
        k++;
    }

    for (int i = 0; i < n + m; i++)
    {
        cout << res[i] << " ";
    }
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    merge(arr1, arr2, n, m);
    return 0;
}


// Question:
// Comment on whether the merge sort algorithm is an in-place algorithm or not, and
// indicate which feature or line(s) of your pseudo code dictates your decision. Is there any
// impact of this phenomenon in the efficiency of merge sort algorithm?

// solution:

// Merge sort is not an in-place algorithm. It requires extra space to store the merged array. 
// The extra space required is O(n+m) where n and m are the sizes of the two arrays to be merged. 
//This extra space requirement can be a disadvantage when the size of the arrays is large, as it can 
//lead to increased memory usage and slower performance. However, the time complexity of merge sort remains 
// O(nlogn) regardless of the extra space requirement, making it an efficient sorting algorithm for large datasets.


// Question:
// In which case, based on the size of the input data, may merge sort not be as efficient or
// suitable as compared to sorting algorithms having quadratic complexity algorithms? and
// why? Mention names of two such algorithms.

// solution:

// Merge sort may not be as efficient or suitable as compared to sorting algorithms with quadratic complexity
// (such as bubble sort or insertion sort) when the size of the input data is small. This is because the overhead
// of the recursive calls and the extra space required for merging can make merge sort slower than quadratic
// complexity algorithms for small datasets. Bubble sort and insertion sort are two examples of sorting algorithms
// with quadratic complexity that may outperform merge sort for small input sizes due to their simplicity and lower overhead.



// Question:
// Compare quick sort with merge sort algorithm in terms of the stability issue. Mention
// an application where a stable sorting algorithm is required. You should start your
// discussion by mentioning the property of a stable sort algorithm.

// solution:

// A stable sorting algorithm is one that preserves the relative order of equal elements in the sorted output.
// Merge sort is a stable sorting algorithm, as it maintains the relative order of equal elements during the merge
// step. Quick sort, on the other hand, is not inherently stable, as it may change the relative order of equal elements
// during the partitioning step.


