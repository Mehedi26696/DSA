
// Consider a circular queue as shown in
// Figure: 1. Demonstrate the following operations.

// Step1: dequeue(), dequeue()
// Step2: enqueue(45),enque(55), enqueue(65) ,enqueue(75)

// Step3: enqueue(85), enque(95), enque(105)

// You have to show the resultant queue as well as the value of two pointers and Rear after completion of each step.

#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int size;
    int front;
    int rear;

   public:
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        if (front == -1) {
            front = rear;
        }
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
            return;
        }
        front = (front + 1) % size;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }

    void displayPointers() {
        cout << "Front: " << front << ", Rear: " << rear << endl;
    }
};

int main() {
    CircularQueue q(8);

    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(8);
    q.enqueue(1);

    q.display();
    q.displayPointers();

    cout<<"Step1: dequeue(), dequeue()\n";
    q.dequeue();
    q.dequeue();
    q.display();
    q.displayPointers();

    cout<<"Step2: enqueue(45), enqueue(55), enqueue(65), enqueue(75)\n";
    q.enqueue(45);
    q.enqueue(55);
    q.enqueue(65);
    q.enqueue(75);
    q.display();
    q.displayPointers();

    cout<<"Step3: enqueue(85), enqueue(95), enqueue(105)\n";
    q.enqueue(85);
    q.enqueue(95);
    q.enqueue(105);
    q.display();
    q.displayPointers();
    return 0;
}