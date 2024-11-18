//Singly Linked List
//Insert at Head

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

//new node insert before head
void InsertAtHead(Node* &head,int d){
    //new node create

    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
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

int length(Node* &head){
    int cnt = 0;
    Node* temp = head;
    while (temp!=NULL)
    {
        cnt++;
         temp = temp->next;
    }
    return cnt;
    
}

bool search(Node* &head,int target){
    Node* temp = head;
    while (temp!=NULL)
    {
         if(temp->data == target){
            return true;
         }
         temp = temp->next;
    }
     return false;
    
}
int main()
{   
    //Dynamic
    // Node* node1 = new Node(5);
    
    // Node* head = node1;

    Node* head = NULL;

    print(head);

    InsertAtHead(head,12);

    print(head);

    
    InsertAtHead(head,15);

    print(head);
    
    cout<<length(head)<<endl;
    cout<<search(head,12)<<endl;

    return 0;
}