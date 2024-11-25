// Write down an algorithm (pseudocode) for printing all the words: (i) consisting of letters {A, B, C}, (ii) of
// length K where K>5, (iii) having more than four "A".

#include<bits/stdc++.h>
using namespace std;
string s = "ABC";
char arr[100];
void recursive(int x,int k){
    if(x==k){
        
        int cnt = 0;
        for(int i=0;i<k;i++){
            if(arr[i]=='A'){
                cnt++;
            }
        }
        if(cnt>4){
            for(int i=0;i<k;i++){
                cout<<arr[i];
            }
            cout<<endl;
        }
        
        return;
    }

    for(int i=0;i<s.size();i++){
        arr[x] = s[i];
        recursive(x+1,k);
    }
}
int main()
{
    int k;
    cin>>k;
     
    recursive(0,k);

    return 0;
}