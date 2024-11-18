


// reverse a linked list

//Recursive Method -1


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

void recursiveReverse(Node* &head, Node *curr, Node *prev)
{
    if (curr == NULL) //if current is null then head point to previous
    {
        head = prev; 
        return;
    }
    Node *forward = curr->next; //forward move one step ahead
    recursiveReverse(head, forward, curr);  //recursive call
    curr->next = prev; //current move one step back
}
Node *reverse(Node *head) 
{
    Node *prev = NULL;
    Node *current = head;

    recursiveReverse(head, current, prev); 

    return head; 
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