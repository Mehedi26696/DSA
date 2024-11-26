
// You are given two head nodes of two sorted singly linked list as input. Write down an efficient algorithm
// (pseudocode) for combining both the lists into one. The resultant linked list must have to be sorted.
// Example: Linked list 1: {1,3,4} ; Linked list 2: {2, 5} => result: {1, 2, 3, 4, 5}



#include <bits/stdc++.h>
using namespace std;
struct ll
{
    struct node
    {
        int data;
        node *next;
    };

    node *head = NULL;
    node *tail = NULL;

    void insert(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    ll list1;
    ll list2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        list1.insert(x);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        list2.insert(x);
    }

    ll list; 

    ll::node *temp1 = list1.head;
    ll::node *temp2 = list2.head;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            list.insert(temp1->data);
            temp1 = temp1->next;
        }
        else
        {
            list.insert(temp2->data);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        list.insert(temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        list.insert(temp2->data);
        temp2 = temp2->next;
    }

    list.display();
    return 0;
}
