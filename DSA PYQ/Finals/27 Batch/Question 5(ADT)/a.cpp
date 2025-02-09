
// a) We know that a queue can be implemented using various data structures, including arrays and linked lists.

// I.Is there any relationship between the above statement and the nature of queues being an Abstract Data Type (ADT)? You should start your answer with the proper introduction of ADT.

// II.With a suitable example, discuss how the implementation choice of an ADT can impact the benefits of a circular queue.
 

// Answer:

// I. An Abstract Data Type (ADT) is a mathematical model for data types where a data type is defined by its behavior from the point of view of a user of the data, 
// specifically in terms of possible values, possible operations on data of this type, and the behavior of these operations. 
//The ADT does not specify how the data type is implemented. The user of the ADT is only concerned with what the data type represents and what operations can be performed on it.
// The user does not need to know how the data type is implemented. The user only needs to know what operations can be performed on the data type and 
// what the behavior of these operations is.

// II. The implementation choice of an ADT can impact the benefits of a circular queue.
// A circular queue is a data structure that uses a single, fixed-size array to implement a queue.
// The circular queue has the advantage of being able to use the entire array, even if some of the elements are not being used.
// This allows the circular queue to have a larger capacity than a regular queue, which can be useful in situations where the queue needs to store a large number of elements.
// The circular queue also has the advantage of being able to efficiently implement the enqueue and dequeue operations, as the elements can be added and removed from the front and
//  back of the queue in constant time.


