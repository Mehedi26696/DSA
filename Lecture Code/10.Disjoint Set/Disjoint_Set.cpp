

// Disjoint Set Union (DSU) or Union Find is a data structure that keeps track of elements which are partitioned into disjoint sets. It supports two main operations:

// Find: Determine which set a particular element is in. Find returns an integer representing a set that contains the given element.
// Union: Join two sets into a single set.


#include <iostream>
using namespace std;


int parent[1000];
int size[1000];
int rank_arr[1000];

void make_set(int v){
    parent[v] = v;
    size[v] = 1;
    rank_arr[v] = 0;
}

int find_set(int v){  
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_naive(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a==b) return;
    parent[a] = b;
}

void union_by_size(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a==b) return;
    if(size[a] >size[b]){
        parent[b] = a;
        size[a] += size[b];
    }
    else{
        parent[a] = b;
        size[b] += size[a];
    }
}

void union_by_rank(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a==b) return;
    if(rank_arr[a] >rank_arr[b]){
        parent[b] = a;
    }
    else if (rank_arr[a] < rank_arr[b]){
        parent[a] = b;
    }
    else{ 
        parent[b] = a;
        rank_arr[a]++;
    }
}

int main() {

    for(int i=0;i<1000;i++)
        parent[i] = -1;
    
    for(int i=1;i<=10;i++){
        make_set(i);
    }

    union_naive(1,2);
    union_naive(2,3);
    union_naive(4,5);
    union_naive(6,7);
    union_naive(7,8);

    cout<<find_set(1)<<endl;
    cout<<find_set(2)<<endl;
    cout<<find_set(3)<<endl;
    

    return 0;
}


// Time Complexity: O(logn) for both find_set and union operations.
// Space Complexity: O(n) where n is the number of elements in the set.
