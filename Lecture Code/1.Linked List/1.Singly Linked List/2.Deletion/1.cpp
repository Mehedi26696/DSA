
// deletion

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor

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
// new node insert before head
void InsertAtHead(Node *&head, int d)
{
    // new node create

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// new node insert after Tail
void InsertAtTail(Node *&tail, int d)
{
    // new node create

    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp; // we can use tail = tail->next;
}

void InsertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // insert at Start
    if (position == 1)
    {
        InsertAtHead(head, d);
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
        InsertAtTail(tail, d);
        return;
    }

    // creating a node for d

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// traverse linked list and print
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

void DeleteNode(Node *&head, int position)
{
    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
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

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    // Dynamic
    Node *node1 = new Node(5);

    Node *head = node1;

    Node *tail = node1;

    print(head);
    InsertAtTail(tail, 12);
    print(head);

    InsertAtTail(tail, 15);
    print(head);

    InsertAtTail(tail, 17);
    print(head);

    InsertAtPosition(tail, head, 3, 78);

    print(head);

    // add first position
    InsertAtPosition(tail, head, 1, 23);

    print(head);
    // last position
    InsertAtPosition(tail, head, 7, 33);

    print(head);

    cout << "Head - " << head->data << endl;
    cout << "Tail - " << tail->data << endl;

    DeleteNode(head,4);

    print(head);


    return 0;
}