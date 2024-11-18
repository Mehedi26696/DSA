

// Doubly Linked List
// InsertAtHead

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

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    if(head!=NULL){
        head->prev = temp;
    }
    head = temp;
}
int main()
{
    // Node *node1 = new Node(5);
    // Node *head = node1;
    Node *head = NULL;
    print(head);
    

    InsertAtHead(head, 7);
    print(head);

    InsertAtHead(head, 8);
    print(head);

    


   
    return 0;
}