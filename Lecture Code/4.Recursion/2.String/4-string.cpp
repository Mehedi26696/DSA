
 
// genarate subset of a stirng abc
// abc
// a
// ab
// abc
// ac
// b
// bc
// c


#include <iostream>
#include <string>
using namespace std;



void generate(int pos,int n,string str,string ans){
    if(pos==n){

        cout<<ans<<endl;
        return;
    }
    
    generate(pos+1,n,str,ans);
    ans+=str[pos];
    generate(pos+1,n,str,ans);

     
}

int main(){
    string str;
    cin>>str;

    generate(0,str.length(),str,"");
    
    return 0;
}