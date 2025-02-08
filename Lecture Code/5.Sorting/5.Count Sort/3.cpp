
// Count Sort is an adaptive sorting algorithm. The time complexity of the algorithm is always O(n+k) where n is the number of elements and k is the maximum element.

#include <iostream>
using namespace std;
int getmax(int arr[], int n){
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
void countsort(int arr[], int n){
     
    int k = getmax(arr, n);

    int count[k+1] = {0};
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }
    for(int i=1; i<=k; i++){
        count[i] += count[i-1];
    }
    int output[n];
    for(int i=n-1; i>=0; i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    countsort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}