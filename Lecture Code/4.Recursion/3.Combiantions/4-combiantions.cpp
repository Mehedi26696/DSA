// combinations of abcde of size 3

// output:
// a b c
// a b d
// a b e
// a c d
// a c e
// a d e
// b c d
// b c e
// b d e
// c d e


// total 10 combinations


#include <iostream>
using namespace std;

char var[] = {'a', 'b', 'c', 'd', 'e'};
void generate_combinations(char arr[], int pos, int n, int k)
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
    
    for (int i =0; i < n; i++)
    {
         if(pos == 0 || arr[pos-1] < var[i])
         {
             arr[pos] = var[i];
             generate_combinations(arr, pos + 1, n, k);
         }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    char arr[k];
    generate_combinations(arr, 0, n, k);

    return 0;
}