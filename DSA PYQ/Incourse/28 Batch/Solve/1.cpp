
// You are given a list of numbers as input where all the items except three are placed in sorted order.
// Write down an efficient algorithm (pseudocode) for sorting the entire list. Mention the runtime and space
// complexity of your algorithm.

// Insertion Sort

#include <bits/stdc++.h>
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

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
           
        arr[j+1] = temp;
    }

     
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}