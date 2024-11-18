

// Circular Linked List

#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int data;
    Node *next;

    // constructor

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    
};

void InsertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        tail->next = newNode;
    }

    else
    {
        // non empty
        // assuming that the element present in the list

        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found curr is represent this element node

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *tail)
{
    Node *temp = tail;

    // using do while because if elements no is 1 then normal while can't print it
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail->next != temp->next);
    cout << endl;
}


int main()
{
    Node *tail = NULL;
    InsertNode(tail, 5, 3); // here 5 is random it doesn't matter because list is empty
    print(tail);
    InsertNode(tail, 3, 7);
    print(tail);
    InsertNode(tail, 7, 9);
    print(tail);
    InsertNode(tail, 9, 12);
    print(tail);

    //middle
    InsertNode(tail, 3, 34);
    print(tail);
    

    return 0;
}