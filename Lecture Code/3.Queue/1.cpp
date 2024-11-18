
//Queue
//Queue is a linear data structure that follows the First In First Out (FIFO) rule. It is similar to a line of people waiting for a service. 
//The person who comes first is served first. The queue is used in many applications like CPU scheduling, Disk Scheduling, etc.

//Operations on Queue
//1. push() : This function is used to insert an element into the queue at the end.
//2. pop() : This function is used to delete an element from the queue from the start.
//3. front() : This function is used to get the front element of the queue from the start.
//4. size() : This function is used to get the size of the queue.
//5. empty() : This function is used to check if the queue is empty or not.

//Implementation of Queue using STL
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1); //pushing elements into the queue
    q.push(2);
    q.push(3);
    cout << q.front() << endl; //front element of the queue
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl; //size of the queue
    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }   
    return 0;
}

