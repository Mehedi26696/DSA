

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Maxheap
    priority_queue<int> maxheap;

    maxheap.push(10);
    maxheap.push(15);
    maxheap.push(5);
    maxheap.push(20);

    cout << "Maxheap: ";
    while (!maxheap.empty())
    {
        cout << maxheap.top() << " ";
        maxheap.pop();
    }

    cout << endl;

    // Minheap
    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(10);
    minheap.push(15);
    minheap.push(5);
    minheap.push(20);

    cout << "Minheap: ";
    while (!minheap.empty())
    {
        cout << minheap.top() << " ";
        minheap.pop();
    }

    return 0;
}