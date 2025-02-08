
#include <bits/stdc++.h>
using namespace std;

struct LL
{

    struct Node
    {

        int data;
        Node *next;
        Node *prev;
    };

    Node *head = NULL;
    Node *tail = NULL;

    void insertAtStart(int data)
    {

        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data)
    {

        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAt(int index, int data)
    {

        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (index == 0)
        {
            insertAtStart(data);
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void display()
    {

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverse()
    {

        Node *temp = NULL;
        Node *current = head;
        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != NULL)
        {
            head = temp->prev;
        }
    
    }
 

 
};

int main()
{

    LL ll;

    ll.insertAtStart(5);
    ll.insertAtStart(10);
    ll.insertAtStart(15);
    ll.display();
 

    ll.insertAtEnd(20);
    ll.insertAtEnd(25);
    ll.display();

    ll.insertAt(2, 30);
    ll.display();

    ll.reverse();
    ll.display();
 

    return 0;
}