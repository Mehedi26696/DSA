
// queue using linked list
// Queue is a linear data structure that follows the First In First Out (FIFO) rule. It is similar to a line of people waiting for a service.
// The person who comes first is served first. The queue is used in many applications like CPU scheduling, Disk Scheduling, etc.

#include <iostream>
using namespace std;

struct queue
{
    struct Node
    {
        int data;
        Node *next;
        Node(int x)
        {
            data = x;
            next = NULL;
        }
    };

    Node *front = NULL;

    Node *back = NULL;
    void push(int x)
    {
        Node *n = new Node(x);
        if (front == NULL)
        {
            front = n;
            back = n;
            return;
        }

        back->next = n;
        back = n;
    }

    void pop()
    {
        if (front == NULL)
        {
            cout << "No elements in queue" << endl;
            return;
        }

        if (front == back)
        {
            front = NULL;
            back = NULL;
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "No elements in queue" << endl;
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }


};

int main()
{
    queue q;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;

    if (q.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
    return 0;
}