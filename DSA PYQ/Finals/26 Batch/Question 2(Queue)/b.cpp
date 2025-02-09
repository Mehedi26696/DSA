
// b) Consider a case of linear queue. Suppose the rear pointer is increased by one before each enqueue operation 
// and the front pointer is increased by one after each dequeue operation. Show an example that claims the queue is
//  full but still there is space? How to solve it in linear queue?

// Answer:
// The queue is full but still there is space when the rear pointer is at the last index of the array and the front pointer is at the first index of the array.

// In this case, the queue is full, but there is still one space available in the array.
// To solve this issue, we can implement a circular queue. In a circular queue, the rear pointer is incremented by one before each enqueue operation, 
// and the front pointer is incremented by one after each dequeue operation.
// This way, the queue can wrap around the array and utilize the available space efficiently.

// Example:
// Consider a linear queue with an array of size 5:
// arr = [3, 5, 8, 1,_]
// front = 0
// rear = 4

// The queue is full, but there is still one space available in the array.

// To solve this issue, we can implement a circular queue. In a circular queue, the rear pointer is incremented by one before each enqueue operation, 
// and the front pointer is incremented by one after each dequeue operation. This way, the queue can wrap around the array and utilize the available space efficiently.

// Example:
// Consider a circular queue with an array of size 5:
// arr = [3, 5, 8, 1, _]
// front = 0
// rear = 4

// After enqueue(7):
// arr = [3, 5, 8, 1, 7]
// front = 0
// rear = 0

// The circular queue can now utilize the available space efficiently and avoid the issue of a full queue with available space.


