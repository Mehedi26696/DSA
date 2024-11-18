

#include <iostream>

using namespace std;

void fun(int n) {
    if(n <= 0) {
        return;
    }

    fun(n-1);
    cout << n << " ";
    fun(n-2);

}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    fun(n);
    return 0;
}