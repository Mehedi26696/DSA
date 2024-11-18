// Forward and Backward traverse
// we don't know tail

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

void printBackward(Node *&head)
{
    Node *temp = head;

    while (temp->next != NULL)
    {

        temp = temp->next;
    }

    Node *curr = temp;
    while (curr != NULL)
    {

        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    printForward(head);

    InsertAtHead(head, 7);
    printForward(head);

    InsertAtHead(head, 12);
    printForward(head);

    InsertAtHead(head, 15);
    printForward(head);

    printBackward(head);

    return 0;
}