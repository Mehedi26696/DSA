
// d) You will be given N numbers, and each number can be either positive or negative. You need to calculate the number of non-repetitive positive even numbers observed in your input. 
// You also need to analyze the memory complexity in terms of Big O for your proposed solution.

// Answer: To solve this problem, we can use a hash set to keep track of the positive even numbers we have encountered so far.
// We iterate through the input numbers and check if the number is positive and even. If it is, we add it to the hash set.
// Since a hash set does not allow duplicates, we can ensure that we only count non-repetitive positive even numbers.
// The memory complexity of this solution is O(N) since we are storing at most N positive even numbers in the hash set.

#include <iostream>
#include <unordered_map>

using namespace std;
int main() {
    int N;
    cout << "Enter the number of elements: "<< endl;
    cin >> N;

    unordered_map<int, int> mp;

    int arr[N];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }


    int count = 0;
    for(auto i : mp) {
        if(i.first > 0 && i.first % 2 == 0) {
            count++;
        }
    }
    cout << "Number of non-repetitive positive even numbers: " << count << endl;
    return 0;
}

// Time complexity: O(N)

// Memory complexity: O(N)

