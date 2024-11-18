

// Doubly Linked List
// Delete Node

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

    ~Node()
    {
        int value = this->data;
        // memory free

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory is free for node with data  " << value << endl;
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

void InsertAtHead(Node* &tail,Node *&head, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void InsertAtTail(Node *&tail,Node* &head, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void InsertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // insert at start
    if (position == 1)
    {
        InsertAtHead(tail,head, d);
        return;
    }

    // new node create

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // insert at last
    if (temp->next == NULL)
    {
        InsertAtTail(tail,head, d);
        return;
    }

    // creating a node for d

    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void DeleteNode(Node *&head, int position)
{
    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = head->next;
        // memory free start node
        temp->next =NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        curr->next->prev = prev;
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next= NULL;
        delete curr;
    }
}
int main()
{
    // Node *node1 = new Node(5);
    // Node *head = node1;
    // Node *tail = node1;

    Node *head = NULL;
    Node *tail = NULL;

    print(head);
    InsertAtTail(tail,head, 7);
    print(head);
    InsertAtTail(tail,head, 12);
    print(head);
    InsertAtTail(tail,head, 14);
    print(head);

    InsertAtPosition(tail, head, 2, 34);
    print(head);
    InsertAtPosition(tail, head, 5, 44);
    print(head);

    DeleteNode(head,1);
    print(head);

    DeleteNode(head,3);
    print(head);

    return 0;
}