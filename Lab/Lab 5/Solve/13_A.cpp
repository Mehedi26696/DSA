


#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    int arr[26] = {0};
    for(int i = 0;i<s1.size();i++)
    {
        arr[s1[i]-'a']++;
        
    }

    for (int i = 0; i < 26; i++)
    {
        for(int j = 0;j<arr[i];j++)
        {
            s2+=char(i+'a');
        }
    }

    cout<<s2;
    
    return 0;
}