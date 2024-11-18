
// combinations of ncr
// nCr = n! / r! * (n-r)!

// input 5 3
// output:
// 0 1 2
// 0 1 3
// 0 1 4
// 0 2 3
// 0 2 4
// 0 3 4
// 1 2 3
// 1 2 4
// 1 3 4
// 2 3 4

#include<bits/stdc++.h>
using namespace std;
void generate_combinations(int arr[], int index, int n, int k)
{
     if(index == k)
     {
         for(int i=0; i<k; i++)
         {
             cout << arr[i] << " ";
         }
         cout << endl;
         return;
     }

     for(int i=0;i<n;i++)
     {   

        if(index == 0 || arr[index-1] < i)
        {
            arr[index] = i;
            generate_combinations(arr,index+1,n,k);
        }
     }
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[k];
    generate_combinations(arr,0,n,k);
    return 0;
}