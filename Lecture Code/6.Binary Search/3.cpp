
// binary search in recursive way

#include <iostream>

using namespace std;

int binarySearch(int arr[], int s, int e, int key)
{
    if (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binarySearch(arr, s, mid - 1, key);
        }
        else
        {
            return binarySearch(arr, mid + 1, e, key);
        }
    }
    return -1;
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
    cout << binarySearch(arr, 0, n-1, key) << endl;
    return 0;
}