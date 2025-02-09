
// circular queue implementation using array


#include <iostream>
using namespace std;


int arr[5];

int front = -1;
int rear = -1;

void enqueue(int x) {
    if((rear+1)%5 == front) {
        cout << "Queue is full" << endl;
        return;
    }
    if(front == -1) {
        front = 0;
    }
    rear = (rear+1)%5;
    arr[rear] = x;
}

void dequeue() {
    if(front == -1) {
        cout << "No elements in queue" << endl;
        return;
    }
    if(front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front+1)%5;
    }
}

int peek() {
    if(front == -1) {
        cout << "No elements in queue" << endl;
        return -1;
    }
    return arr[front];
}

bool empty() {
    if(front == -1) {
        return true;
    }
    return false;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    cout << peek() << endl;
    dequeue();
    enqueue(7);
    cout << peek() << endl;
    enqueue(8);
    cout << peek() << endl;
    if(empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }
    return 0;
} 