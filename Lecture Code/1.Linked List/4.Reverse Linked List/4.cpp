
//reverse a doubly linked list
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    Node *prev;
    int data;
    Node *next;

    // constructor

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

// traverse a linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
 
void InsertAtTail(Node* &head, Node* &tail,int d){
    Node* temp = new Node(d);
    if(tail==NULL){
        tail = temp;
        head = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

Node* reverse(Node* head){
    Node* temp = NULL;
    Node* current = head;
    while(current!=NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp!=NULL){
        head = temp->prev;
    }
    return head;
}



 
int main()
{
    // Node *node1 = new Node(5);
    // Node *head = node1;
    //Node* tail = node1;
    Node* head = NULL;
    Node* tail = NULL;
    
    int length;
    cin>>length;

    for(int i=0;i<length;i++){
        int d;
        cin>>d;
        InsertAtTail(head,tail,d);
    }
    head = reverse(head);
    print(head);
 
    return 0;
}