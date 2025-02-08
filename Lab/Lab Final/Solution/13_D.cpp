//13
//13
//13
//13
//13
//13
 

#include<iostream>

using namespace std;

void gen(int pos,int n,int arr[]) {

    if(pos == n) {
        for(int i=0; i<n-1; i++) {
            cout << arr[i] << " ";
        }
        cout << arr[n-1] << endl;
        return;
    }

    for(int i=0; i<=4; i++) {
         
        if(i%2== pos%2) {
            arr[pos] = i;
            gen(pos+1,n,arr);
    }
     
}
}

int main(){
    int n;

    cin >> n;

    int a[n];

    gen(0,n,a);
}