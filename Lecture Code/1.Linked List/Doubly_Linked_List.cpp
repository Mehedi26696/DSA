

// Doubly Linked List

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

    void inserAtEnd(int data)
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
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
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

    void displayReverse()
    {

        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void deleteAtStart()
    {

        head = head->next;
        head->prev = NULL;
    }

    void deleteAtEnd()
    {

        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void deleteAt(int index)
    {

        if (index == 0)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->prev = temp;
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
    ll.displayReverse();

    ll.inserAtEnd(20);
    ll.inserAtEnd(25);
    ll.display();

    ll.insertAt(2, 30);
    ll.display();

    ll.deleteAtStart();
    ll.display();

    ll.deleteAtEnd();
    ll.display();

    ll.deleteAt(1);
    ll.display();

    return 0;
}