 
// Question

// We know that a queue can be implemented using various data structures, including arrays and linked
// lists. Is there any relationship between the above statement and the nature of queues being an
// Abstract Data Type (ADT)?
// Now, with a suitable example, discuss how the implementation choice of an ADT can impact the
// benefits of a circular queue.

// Answer

// Yes, there is a relationship between the statement and the nature of queues being an Abstract Data
// Type (ADT). An ADT is a type of data structure that is defined by its operations, not by its
// implementation. This means that the operations of the data structure are well-defined, but the
// implementation details can vary. For example, a queue is defined by its operations, such as enqueue
// (add an element to the back of the queue) and dequeue (remove an element from the front of the
// queue), but the implementation details of how these operations are carried out can vary. A queue can
// be implemented using an array, a linked list, or other data structures, but as long as the
// operations are well-defined, it is still a queue.

// The implementation choice of an ADT can impact the benefits of a circular queue. A circular queue is a
// type of queue in which the front and back of the queue are connected, forming a circle. This allows
// elements to be added and removed from the queue in a circular manner, which can be more efficient
// than a regular queue in some cases. For example, if the front of the queue is at the end of the
// array, elements can be added to the front of the queue by wrapping around to the beginning of the
// array, which can be more efficient than shifting all the elements in the array to make room for the
// new element.


// Implementation of Circular Queue using Array

#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int c)
    {
        arr = new int[c];
        capacity = c;
        size = 0;
        front = 0;
        rear = -1;
    }

    int getFront()
    {
        if (size == 0)
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (size == 0)
            return -1;
        return arr[rear];
    }

    void enqueue(int x)
    {
        if (size == capacity)
            return;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    int dequeue()
    {
        if (size == 0)
            return -1;
        int frontElement = arr[front];
        front = (front + 1) % capacity;
        size--;
        return frontElement;
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    q.dequeue();
    q.enqueue(6);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    return 0;
}
