
// Radix Sort with negative numbers

#include <iostream>

using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++; // (arr[i] / exp) % 10 is used to get the digit at the exp place
    }

    // print(count, 10);

    // Change count[i] so that count[i] now contains actual
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1]; // count[i] contains the position of the element in the output array
    }

    // print(count, 10);
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; // -1 is used because array index starts from 0
        count[(arr[i] / exp) % 10]--;                    // Decrease the count
    }
    // print(count, 10);
    // print(output, n);
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    // print(arr, n);
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp); // exp is the place value
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {    
         int x;
         cin>>x;
         arr[i] = x+10000;
    }
    
    radixsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]-10000 << " ";
    }
    return 0;
}