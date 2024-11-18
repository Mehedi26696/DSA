// reverse a linked list

//Iterative Method

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *reverse(Node *head) 
{
    Node *prev = NULL;
    Node *current = head;
    Node *forward;
    while (current != NULL)
    {
        forward = current->next;
        current->next = prev; //current move one step back
        prev = current;  //prev move one step ahead
        current = forward;
    }
    return prev;
}

void InsertAtTail(Node* &head,Node *&tail, int d)
{
     

    Node *temp = new Node(d); //new node create
    if (tail == NULL) //if tail is null then head and tail point to same node
    {
        tail = temp;
        head = temp;
    }
    else  //if tail is not null then tail point to new node
    {
        tail->next = temp;
        tail = temp;
    }
}

void print(Node *head) //traverse linked list and print
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int length;
    cin>>length;
    for (int i = 1; i <=length; i++) 
    {   
        int x;
        cin>>x;
        InsertAtTail(head,tail,x); //Insert at Tail
    }
    head = reverse(head); //reverse linked list
    print(head); //print linked list
    return 0;
}
