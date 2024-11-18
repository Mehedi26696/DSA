
// combinations of ncr in sorted order

// input: 5 3
// output:
// 4 3 2
// 4 3 1
// 4 3 0
// 4 2 1
// 4 2 0
// 4 1 0
// 3 2 1
// 3 2 0
// 3 1 0
// 2 1 0

#include <iostream>
using namespace std;

void generate_combinations(int arr[], int pos, int n, int k)
{
    if (pos == k)
    {
        for (int i = 0; i < k - 1; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << arr[k - 1] << endl;
        return;
    }
    int start;
    if (pos == 0)
    {
        start = n - 1;
    }
    else
    {
        start = arr[pos - 1] - 1;
    }
    for (int i = start; i >= 0; i--)
    {
        arr[pos] = i;
        generate_combinations(arr, pos + 1, n, k);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[k];
    generate_combinations(arr, 0, n, k);

    return 0;
}