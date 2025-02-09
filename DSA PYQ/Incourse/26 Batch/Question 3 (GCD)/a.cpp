
// Question

// Write a procedure to calculate the Greatest Common Divisor (GCD) for a given two numbers. You have to write two versions –
// i) a recursive function, and
// ii) a function with stack (explicitly).

// Answer

#include <iostream>

using namespace std;

int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}

int gcd_stack(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    cout << "Enter two numbers:\n";
    cin >> a >> b;
    cout << "GCD using recursive function: " << gcd_recursive(a, b) << endl;
    cout << "GCD using stack function: " << gcd_stack(a, b) << endl;
    return 0;
}