#include <iostream>
using namespace std;
void gen(int arr[], int n, int pos)
{
    if (pos == n)
    {
        for (int i = 0; i < n-1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << arr[n-1]<<endl;  
        return;
    }

    for (int i = 4; i >= 0; i--)
    {

        if (pos % 2 == i % 2)
        {
            arr[pos] = i;
            gen(arr, n, pos + 1);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];

    gen(arr, n, 0);
    return 0;
}