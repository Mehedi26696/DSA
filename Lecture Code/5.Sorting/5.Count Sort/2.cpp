

//count sort with negative numbers

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
        b[a[i] + 10000]++;
    }
    for (int i = 0; i < 100000; i++)
    {
        if (b[i] != 0)
        {
            for (int j = 0; j < b[i]; j++)
            {
                cout << i - 10000 << " ";
            }
        }
    }
    return 0;
}