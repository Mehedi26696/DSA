//13
//13
//13
//13
//13
 


#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    
    int n, m;
    cin >> n;

    unordered_map<int, int> frequency;  

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        frequency[num]++;
    }

    cin >> m;
    
    int queries[m];

   
  
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    
    for (int i = 0; i < m; i++) {
        cout << frequency[queries[i]] << endl;  
    }

    return 0;
}
