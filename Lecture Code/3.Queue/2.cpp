
//queue using array
// enqueue - push
// dequeue - pop
// front - peek
// size - size
// empty - empty

//Time complexity of all the operations is O(1)

#include <iostream>
using namespace std;



class queue {
    int* arr;
    int front;
    int back;

    int n;
    public:
    queue(int data) {
        n = data;
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x) {
        if(back == n-1) {
            cout << "Queue Overflow" << endl;
            return;
        }
        
        arr[++back] = x;
        if(front == -1) {
            front++;
        }
    }

    void pop() {
        if(front == -1 || front > back) {
            cout << "No elements in queue" << endl;
            return;
        }
        front++;
    }

    int peek() {
        if(front == -1 || front > back) {
            cout << "No elements in queue" << endl;
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        if(front == -1 || front > back) {
            return true;
        }
        return false;
    }
};

int main() {

    int n;
    cout << "Enter the size of the queue: ";
    cin >> n;
    queue q(n);

    for (int i = 0; i < n; i++)
    {
         int x;
         cin >> x;
         q.push(x);
    }
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    if(q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }
    return 0;
}