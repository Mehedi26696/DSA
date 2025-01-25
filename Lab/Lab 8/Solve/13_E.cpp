//13
//13
//13

#include <iostream>

using namespace std;


void combinations(int place,int n,int com[]){

    // base case 
    if(place==n){

        for(int i=0;i<n-1;i++){
            cout<<com[i]<<" ";
        }
        cout<<com[n-1]<<endl;
        return;
    }
    
    // recursive case  
    for(int i=4;i>=0;i--){
        
        // odd even check 
        if(i%2 != place %2){
            com[place] = i;
            combinations(place+1,n,com);
        }
    }

     
}

int main(){
    int val;
    cin>>val;

    // array create 

    int com[val];

    // function call 

    combinations(0,val,com);
    
    return 0;
}