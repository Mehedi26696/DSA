

// permutation of a,b,c in a string of length n

// if n = 3
// output: abc, acb, bac, bca, cab, cba

// total number of permutations = 3! = 6

#include <iostream>
#include <algorithm>

using namespace std;

char arr[] = {'a', 'b', 'c'};

void permute(int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i <= r; i++)
        {
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    for (int i = l; i <= r; i++)
    {
        swap(arr[l], arr[i]);
        permute(l + 1, r);
        swap(arr[l], arr[i]); // backtrack
    }
}

int main()
{
    permute(0, 2);
    return 0;
}