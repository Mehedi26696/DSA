

// Linked list : linear Data Structure - > collection of Nodes
// each node include data and next node address

// Using linked list we can modify array size during it's run time without copying it's values

// deleting elements ->  eassy


//simple linked list
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
int main()
{   
    //Dynamic
    Node* node1 = new Node(5);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    return 0;
}