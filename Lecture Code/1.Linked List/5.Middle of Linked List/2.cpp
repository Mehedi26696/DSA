


//Middle of a linked list
// Given a singly linked list, find the middle of the linked list. For example, if the given linked list is 1->2->3->4->5 then the output should be 3.
// If there are even nodes, then there would be two middle nodes, we need to print the second middle element. For example, if the given linked list is 1->2->3->4->5->6 then the output should be 4.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

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

void InsertAtTail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        tail = temp;
        head = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

int MiddleElement(Node *head,int length)
{   
    Node* temp = head;
    for(int i=0;i<length/2;i++){
        temp = temp->next;
    }
    return temp->data;
    
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int length;
    cin >> length;

    for (int i = 0; i < length; i++)
    {
        int d;
        cin >> d;
        InsertAtTail(head, tail, d);
    }
    cout << MiddleElement(head,length) << endl;

    return 0;
}