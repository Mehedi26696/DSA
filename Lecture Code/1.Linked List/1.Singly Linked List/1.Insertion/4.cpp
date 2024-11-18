
// SIngly Linked List
// Insert at Tail

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

// new node insert at end
void InsertAtEnd(Node *&head, int d)
{
    // new node create

    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        return;
    }

    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
   
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
    // Node *node1 = new Node(5);
    // Node *head = node1;

    Node* head = NULL;
  

    print(head);
    InsertAtEnd(head, 12);
    print(head);
    InsertAtEnd(head, 13);
    print(head);

    return 0;
}