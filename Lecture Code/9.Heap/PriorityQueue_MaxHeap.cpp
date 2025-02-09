

#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
private:
    vector<pair<int, int>> heap; // (value, priority) pairs

    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int leftChild(int i)
    {
        return (2 * i) + 1;
    }
    int rightChild(int i)
    {
        return (2 * i) + 2;
    }

    // Heapify-down (for extractMax)
    void heapifyDown(int i)
    {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        if (left < heap.size() && heap[left].second > heap[largest].second)
        {
            largest = left;
        }
             
        if (right < heap.size() && heap[right].second > heap[largest].second)
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Heapify-up (for insert)
    void heapifyUp(int i)
    {
        while (i > 0 && heap[parent(i)].second < heap[i].second)
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Insert a (value, priority) pair
    void push(int value, int priority)
    {
        heap.push_back({value, priority});
        heapifyUp(heap.size() - 1);
    }

    // Extract element with the highest priority (largest priority number)
    void pop()
    {
        if (heap.empty())
        {
            cout << "Heap is empty!" << endl;
            return;
        }
        pair<int, int> maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);  
    }

    // Get the element with the highest priority without removing it
    pair<int, int> top()
    {
        if(heap.empty())
        {
            return make_pair(-1, -1);
        }

        return heap[0];

    }

    // Check if heap is empty
    bool empty()
    {
        return heap.empty();
    }

    // Print heap contents
    void display()
    {
        cout << "Max-Heap (value, priority): ";
        for (auto &p : heap)
            cout << "(" << p.first << ", " << p.second << ") ";
        cout << endl;
    }
};

int main()
{
    MaxHeap pq;

    pq.push(10, 3); // Value: 10, Priority: 3
    pq.push(5, 1);  // Value: 5, Priority: 1 (lowest priority)
    pq.push(20, 4); // Value: 20, Priority: 4 (highest priority)
    pq.push(1, 2);  // Value: 1, Priority: 2

    pq.display(); // Expected output: (20,4) (10,3) (5,1) (1,2)

    cout << "Highest Priority Element: (" << pq.top().first << ", " << pq.top().second << ")\n";

    pq.pop();

    pq.display(); // Updated heap

    cout << "Highest Priority Element: (" << pq.top().first << ", " << pq.top().second << ")\n";

    pq.pop();

    pq.display(); // Updated heap

    return 0;
}
