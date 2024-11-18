
// Singly Linked List
// Insert at Middle

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
};
//new node insert before head
void InsertAtHead(Node* &head,int d){
    //new node create

    Node* temp = new Node(d);
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

void InsertAtPosition(Node *&head,Node* &tail, int position, int d)
{    
    //insert at Start
    if(position == 1){
        InsertAtHead(head,d);
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
    
    //insert at last
    if (temp->next == NULL)
    {
         InsertAtTail(tail,d);
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

    InsertAtPosition(head,tail, 3, 78);

    print(head);
    
    //add first position
    InsertAtPosition(head,tail, 1, 23);

    print(head);
    //last position
    InsertAtPosition(head,tail, 7, 33);

    print(head);

    cout<<"Head - " << head->data<<endl;
    cout<<"Tail - "<<tail->data<<endl;

    return 0;
}