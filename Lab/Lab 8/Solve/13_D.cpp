//13
//13

#include <iostream>
using namespace std;

void combinations(int n,int k, int place, int com[])
{
    // base case check
    if (place == k)
    {   
        // print the combination
        for (int i = 0; i < k - 1; i++)
        {
            cout << com[i] << ' ';
        }
        cout <<com[k - 1] << endl;
        return;
    }
     
    // For each combination

    // iterate from 1 to n (inclusive)

    // check start position

   // int shuru = place == 0 ? n-1: com[place - 1]-1;
    for(int i = place == 0 ? n-1 : com[place-1]-1; i >= 0; i--)
    {
        // insert a new combination
        com[place] = i;
        // recusrion call 


        combinations(n,k,place+1,com);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    // array create 
    int com[k];

    // function call 
    combinations(n,k,0,com);

    return 0;
}