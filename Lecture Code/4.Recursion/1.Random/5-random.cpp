
#include <iostream>

using namespace std;

void fun(int n) {
    if(n >= 10) {
        return;
    }

    fun(n+1);

    fun(n+2);

    cout << n << " ";

}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    fun(n);
    return 0;
}