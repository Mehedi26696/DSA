
// Set Operations
#include <iostream>
using namespace std;

int parent[1000];
int size[1000];
int rank_arr[1000];

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
    rank_arr[v] = 0;  
    
}
int find_set(int v)
{
    int root = v;
    while (root != parent[root])
    {
        root = parent[root];
    }
    while (v != root)
    {
        int next = parent[v];
        parent[v] = root;
        v = next;
    }
    return root;
}

void union_naive(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return;
    parent[a] = b;
}

void union_by_size(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return;
    if (size[a] > size[b])
    {
        parent[b] = a;
        size[a] += size[b];
    }
    else
    {
        parent[a] = b;
        size[b] += size[a];
    }
}

void union_by_rank(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return;
    if (rank_arr[a] > rank_arr[b])
    {
        parent[b] = a;
    }
    else if (rank_arr[a] < rank_arr[b])
    {
        parent[a] = b;
    }
    else
    {
 
        a = find_set(a);
        b = find_set(b);
        if (size[a] > size[b])
        {
            parent[b] = a;
            size[a] += size[b];
            rank_arr[a]++;
        }
        else
        {
            parent[a] = b;
            size[b] += size[a];
            rank_arr[b]++;
        }
    }
}

int main()
{

    for (int i = 0; i < 1000; i++)
        parent[i] = -1;

    for (int i = 1; i <= 10; i++)
    {
        make_set(i);
    }

    union_by_rank(1, 2);
    union_by_rank(2, 3);
    union_by_rank(4, 5);

    cout << find_set(1) << endl;
    cout << find_set(2) << endl;
    cout << find_set(3) << endl;

    return 0;
}