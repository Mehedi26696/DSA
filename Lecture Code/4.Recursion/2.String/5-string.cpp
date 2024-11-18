

// 1. Generate all possible strings of length n that can be formed using the characters '0', '1', '2', '3', '4' without repeating the same character in a row.

// Output:
// Each line will contain a list of space-separated digits where,
// ● The list contains n digits.
// ● The digits in the list are 0-4 (inclusive)
// ● The odd indexed digit in the list is an even digit
// ● The even indexed digit in the list is an odd digit
// The lists will be printed in descending order. Example: {1 0 3} before {1 0 1}.


// input 3
// output:
// 3 4 3
// 3 4 1
// 3 2 3
// 3 2 1
// 3 0 3
// 3 0 1
// 1 4 3
// 1 4 1
// 1 2 3
// 1 2 1
// 1 0 3
// 1 0 1


#include<bits/stdc++.h>
using namespace std;
void generate(int arr[],int n,int pos){

    if(pos==n){
       for(int i =0;i<n;i++){
         cout<<arr[i]<<" ";
       }
       cout<<endl;
       return;
    }
    
    for(int i = 4; i>=0;i--){
        if(pos%2!=i%2){
            arr[pos] = i;
            generate(arr,n,pos+1);
        }
    }

}
int main()
{
    int n;
    cin>>n;
    int arr[3];
    generate(arr,n,0);
    return 0;
}