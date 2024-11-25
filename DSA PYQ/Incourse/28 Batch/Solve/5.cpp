
// ouput trace of the code
#include <iostream>
using namespace std;
void pr(int n)
{
    if (n < 1)
        return;
    pr(n / 2);
    cout << n<<" ";
}
int main()
{
    pr(17);
    return 0;
}