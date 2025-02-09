


// b) Suppose that there are only two stacks as a data structure in the land of Dark Algorithms. But you have to solve a very important problem which can only be solved using a queue
// efficiently. So, you can understand that you have to implement the queue first using stack in order to solve the problem.
// Implement a queue using only stack.
// Analyze the time and space complexity of your algorithm.


#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> stack1, stack2;

public:
    // Enqueue operation (O(1))
    void enqueue(int x) {
        stack1.push(x);
    }

    // Dequeue operation (O(n) in worst case)
    int dequeue() {
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int frontElement = stack2.top();
        stack2.pop();
        return frontElement;
    }

    // Check if queue is empty
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Dequeued: " << q.dequeue() << endl; // 1
    cout << "Dequeued: " << q.dequeue() << endl; // 2

    q.enqueue(4);
    cout << "Dequeued: " << q.dequeue() << endl; // 3
    cout << "Dequeued: " << q.dequeue() << endl; // 4

    return 0;
}

// Time complexity:
// Enqueue operation: O(1)
// Dequeue operation: O(n) in worst case
// isEmpty operation: O(1)

// Space complexity: O(n) where n is the number of elements in the queue