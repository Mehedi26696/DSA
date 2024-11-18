
// combinations of abcde of size 3

// output:
// a b c
// a b d
// a b e
// a c d
// a c e
// a d e
// b c d
// b c e
// b d e
// c d e


// total 10 combinations

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void generate(char arr[],stack<char>st, int n, int i)
{
    if (st.size() == n)
    {
        for (int j = 0; j < n; j++)
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
        return;
    }

    if (i == 5) 
    {
        return;
    }
    

    st.push(arr[i]);
    generate(arr,st, n, i + 1);
    st.pop();
    generate(arr,st, n, i + 1);
}


int main()
{
    char arr[] = {'a', 'b', 'c', 'd'};

    stack<char> st;

    int n;
    cin >> n;
    generate(arr,st, n, 0);
}