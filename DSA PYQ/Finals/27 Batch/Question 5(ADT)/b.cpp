

// b) You have been provided with a linked list L1 and two integers, M and N. You are tasked
// with implementing a function (provide a pseudocode) that generates a new linked list L2 from L1 based on the following guidelines:
// - Retain the first M nodes in the linked list
// - Delete the next N nodes
// - Connect the remaining nodes to the first M nodes
// Finally, make the resulting linked list as a circular linked list

#include <iostream>
using namespace std;

struct LL
{
    struct Node
    {
        int data;
        Node *next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

    Node *head = NULL;
    Node *tail = NULL;

    void insert(int data)
    {
        Node *new_node = new Node(data);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void generateCircularLinkedList(LL &l2, LL &l1, int M, int N)
    {
        if (l1.head == NULL)
        {
            return;
        }

        Node *current = l1.head;
        int count = 1;

        // Retain the first M nodes
        while (count <= M && current != NULL)
        {
            l2.insert(current->data);
            current = current->next;
            count++;
        }

        if (current == NULL)
        {
            return;
        }

        // Skip the next N nodes
        count = 1;
        while (count <= N && current != NULL)
        {
            current = current->next;
            count++;
        }

        if (current == NULL)
        {
            return;
        }

        // Connect the remaining nodes to the first M nodes
        Node *temp = current;
        while (temp != NULL)
        {
            l2.insert(temp->data);
            temp = temp->next;
        }

        // Make the resulting linked list circular
        if (l2.head != NULL)
        {
            l2.tail->next = l2.head;
        }
    }

    void printCircular()
    {
        Node *temp = head;
        if (temp == NULL)
        {
            return;
        }

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main()
{
    LL l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(7);
    l1.insert(8);
    l1.insert(9);
    l1.insert(10);
    l1.print();

    LL l2;

    l2.generateCircularLinkedList(l2, l1, 3, 2);

    l2.printCircular();
    return 0;
}