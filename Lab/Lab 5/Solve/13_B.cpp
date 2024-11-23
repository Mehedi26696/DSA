

#include <bits/stdc++.h>
using namespace std;
struct ll
{

    struct node
    {

        int data[2];
        node *next;
    };

    node *head = NULL;
    node *tail = NULL;

    void insert(int a, int b)
    {
        node *temp = new node();
        temp->data[0] = a;
        temp->data[1] = b;
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

    void sort()
    {
        node *temp = head;
        while (temp != NULL)
        {
            node *temp1 = temp->next;
            while (temp1 != NULL)
            {
                if (temp->data[0] > temp1->data[0])
                {
                    int t = temp->data[0];
                    temp->data[0] = temp1->data[0];
                    temp1->data[0] = t;

                    t = temp->data[1];
                    temp->data[1] = temp1->data[1];
                    temp1->data[1] = t;
                }

                else if (temp->data[0] == temp1->data[0])
                {
                    if (temp->data[1] > temp1->data[1])
                    {
                        int t = temp->data[0];
                        temp->data[0] = temp1->data[0];
                        temp1->data[0] = t;

                        t = temp->data[1];
                        temp->data[1] = temp1->data[1];
                        temp1->data[1] = t;
                    }
                }
                temp1 = temp1->next;
            }
            temp = temp->next;
        }
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data[0] << " " << temp->data[1] << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    ll l;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        l.insert(a, b);
    }
    l.sort();
    l.display();
    return 0;
}