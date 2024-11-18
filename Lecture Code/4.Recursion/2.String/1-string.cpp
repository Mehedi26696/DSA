
// combinations of a,b,c in a string of length n


// if n = 3
// output: aaa, aab, aac, aba, abb, abc, aca, acb, acc, baa, bab, bac, bba, bbb, bbc, bca, bcb, bcc, caa, cab, cac, cba, cbb, cbc, cca, ccb, ccc

//total number of combinations = 3^3 = 27




#include <iostream>

using namespace std;

char arr[3];

void fun(int i) {
    if(i == 3) {
        
        for(int j = 0; j < 3; j++) {
            cout << arr[j];
        }
        cout << endl;
        return;
    }
    
    arr[i] = 'a';
    fun(i+1);
    arr[i] = 'b';
    fun(i+1);
    arr[i] = 'c';
    fun(i+1);
}

int main() {
    
    fun(0);
    return 0;
}