

// b) You are given the following code segment. Calculate the Big O runtime complexity with respect to input size N.

// void function(int arr[], int N) {

// arr denotes an array of integers of size N
// for (int i = 0; i < N; i++) {
//     for (int j = 0; j <=sqrt(i); j++) {
//         doSomething();
//     }
// }

// for (int i = 0; i < N; i++) {
//     int at = i;
//     while (at <= N) {
//         doSomething();
//         at *= 2;
//     }
// }

// }


// Answer: The first loop runs from 0 to N, and the inner loop runs from 0 to sqrt(i). The outer loop runs N times, and the inner loop runs sqrt(i) times,
// where i ranges from 0 to N. The total number of iterations can be calculated as follows:
// 1 + 2 + 3 + ... + sqrt(N) = O(sqrt(N)^2) = O(N)
// Therefore, the first part of the code has a time complexity of O(N).

// The second loop runs from 0 to N, and the inner loop runs log(N) times. The total number of iterations can be calculated as follows:
// 1 + 2 + 4 + 8 + ... + N = O(N)
// Therefore, the second part of the code has a time complexity of O(N).

// Combining both parts, the overall time complexity of the function is O(N).


