

// Forward and Backward traverse
// we know tail


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
void printForward(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printBackward(Node *&tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    printForward(head);

    InsertAtTail(tail, 7);
    printForward(head);
    InsertAtTail(tail, 8);
    printForward(head);
    InsertAtTail(tail, 9);
    printForward(head);
    InsertAtTail(tail, 12);
    printForward(head);

    printBackward(tail);
    return 0;
}