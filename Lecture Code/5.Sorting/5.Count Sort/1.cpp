//count sort
// Time Complexity: O(n)
// Space Complexity: O(n)
// Count sort is a sorting algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array. The algorithm then uses this information to create a sorted array.
// Count sort is a stable sorting algorithm, meaning that the relative order of equal elements is preserved in the sorted array.

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[100000] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }
    for (int i = 0; i < 100000; i++)
    {
        if (b[i] != 0)
        {
            for (int j = 0; j < b[i]; j++)
            {
                cout << i << " ";
            }
        }
    }
    return 0;
}