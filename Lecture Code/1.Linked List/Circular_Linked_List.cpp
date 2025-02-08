
// Circular Linked List

#include <iostream>
using namespace std;

struct LL{

    struct Node{
        int data;
        Node* next;
    };

  
    Node* tail = NULL;

    void InsertNode(int element, int d)
    {
        // empty list
        if (tail == NULL)
        {
            Node *newNode = new Node();
            newNode->data = d;
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

            Node *temp = new Node();
            temp->data = d;
            temp->next = curr->next;
            curr->next = temp;
        }
    }

    void print()
    {
        Node *temp = tail;

        // using do while because if elements no is 1 then normal while can't print it
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail);
    }

};

int main(){
    LL ll;
    ll.InsertNode(0, 1);
    ll.InsertNode(1, 2);
    ll.InsertNode(2, 3);
    ll.InsertNode(3, 4);
    ll.InsertNode(4, 5);
    ll.print();
}