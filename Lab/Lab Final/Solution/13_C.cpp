//13
//13
//13
//13
//13
//13
//13
 
#include <bits/stdc++.h>
 
using namespace std;

 
int ans(int arr[], int n, int key) {
    int left = 0, right = n - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= key) {
            result = mid;   
            left = mid + 1;   
        } else {
            right = mid - 1;   
        }
    }

    return result + 1;  
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];

 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

 
    int res[m];


    int x;

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;

 
        cout<<ans(arr, n, q)<<endl;
    }
 
    return 0;
}
