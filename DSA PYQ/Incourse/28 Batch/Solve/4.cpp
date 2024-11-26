// You are given a sorted array of numbers and a number k as input. Write down an efficient algorithm
// for finding the largest number in the array that is smaller than k. Mention the runtime and
// space complexity of your algorithm.

// Binary Search
// Time Complexity: O(logn)
// Space Complexity: O(1)
// use function to find the largest number smaller than k

#include <bits/stdc++.h>
using namespace std;

int find_largest_smaller(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < k)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << find_largest_smaller(arr, n, k);

    return 0;
}