
// ouput trace of the code
#include <iostream>
using namespace std;
void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        cout << n<<" ";
        fun(n - 1);
    }
}
int main()
{
    fun(4);
    return 0;
}