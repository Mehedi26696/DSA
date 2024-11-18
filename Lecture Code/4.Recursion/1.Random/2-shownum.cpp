
// Print n,n-1,.........3,2,1 without using recursion

#include <iostream>
using namespace std;

void print(int n) {
    
    if(n == 0) {
        return;
    }

    cout << n << " ";
    print(n-1);
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    print(n);
    return 0;
}