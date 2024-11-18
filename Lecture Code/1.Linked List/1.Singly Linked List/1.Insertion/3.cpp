
//SIngly Linked List
//Insert at Tail


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

//new node insert after Tail
void InsertAtTail(Node* &tail,int d){
    //new node create

    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;  //we can use tail = tail->next;
}


//traverse linked list and print
void print(Node* &head){
    Node* temp = head;
    while (temp!=NULL)
    {
         cout<<temp->data<<" ";
         temp = temp->next;
    }
    cout<<endl;
    
}
int main()
{   
    //Dynamic
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;
 
    
    print(head);
    InsertAtTail(tail,12);
    print(head);
    InsertAtTail(tail,18);
    print(head);
    


    return 0;
}