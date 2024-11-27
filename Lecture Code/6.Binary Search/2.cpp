
// Find an element in a sorted array that smaller than k

#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n-1;
    while (s <= e)
    {
        int mid = e + (s - e) / 2;
        if (arr[mid] == key)
        {
            return mid-1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return e;
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
    int key;
    cin >> key;
    cout << arr[binarySearch(arr,n,key)] << endl;
    return 0;
}