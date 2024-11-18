
//Middle of singly linked list using recursion

#include <iostream>
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


void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* middleUtil(Node* head, Node* slow, Node* fast) {
    if (fast == NULL || fast->next == NULL) {
        return slow;
    }
    return middleUtil(head, slow->next, fast->next->next);
}

Node* middle(Node* head) {
    return middleUtil(head, head, head);
}

int main()
{
    // Dynamic
    Node *node1 = new Node(5);

    Node *head = node1;

    Node *tail = node1;

    InsertAtTail(tail, 12);

    InsertAtTail(tail, 15);

    InsertAtTail(tail, 17);


    print(head);

    Node *mid = middle(head);

    cout << "Middle - " << mid->data << endl;

    return 0;
}

