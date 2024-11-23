// Bubble sort
// Optimize way

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = 1; j < n; j++)
    {
        bool swapped = false;
        for (int k = 0; k < n - j; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                swapped = true;
                swap(arr[k], arr[k + 1]);
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}