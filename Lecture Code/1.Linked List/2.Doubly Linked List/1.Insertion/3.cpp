


// Doubly Linked List
// InsertATail

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

// get length of a linked list
int getlength(Node *&head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {

        temp = temp->next;
        length++;
    }
    return length;
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

 
int main()
{
    // Node *node1 = new Node(5);
    // Node *head = node1;
    //Node* tail = node1;
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    cout << getlength(head) << endl;

    InsertAtTail(head,tail, 7);
    print(head);
    cout << getlength(head) << endl;
    InsertAtTail(head,tail, 8);
    print(head);
    cout << getlength(head) << endl;
    InsertAtTail(head,tail, 9);
    print(head);
    cout << getlength(head) << endl;
    return 0;
}