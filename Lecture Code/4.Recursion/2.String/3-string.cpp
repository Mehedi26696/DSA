
// 1. Generate all strings of length n drawn from 0...4
//for input 3
//output

// 010
// 012
// 014
// 030
// 032
// 034
// 210
// 212
// 214
// 230
// 232
// 234
// 410
// 412
// 414
// 430
// 432
// 434

#include <iostream>
#include <string>
using namespace std;


void generate(int pos,int n,int arr[]){
    if(pos==n){

        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<endl;
        return;
    }
    
    for(int i=0;i<=4;i++){
        
        if(i%2 == pos %2){
            arr[pos] = i;
            generate(pos+1,n,arr);
        }
    }

     
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    generate(0,n,arr);
    
    return 0;
}