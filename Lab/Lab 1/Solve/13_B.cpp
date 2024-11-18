//13
//13
#include <iostream>
using namespace std;

struct ll
{

    struct student
    {
        student *next;
        string name;
        int roll;
    };
    student *head = NULL;
    student *tail = NULL;

    void insert_first(string name, int roll)
    {
        // Your code starts here #001
        student *a = new student();
        a->name = name;
        a->roll = roll;
        a->next = NULL;
        if (head == NULL)
        {
            head = a;
            tail = a;
            return;
        }

        a->next = head;
        head = a;

        // Your code ends here #001
    }

    void print()
    {
        // prints elements from head to tail
        // Your code starts here #002

        // Your code ends here #002

        student * temp = head;

        while (temp)
        {
            /* code */
            cout<<temp->name <<" "<<temp->roll<<endl;
            temp = temp->next;
        }
        
    }
};

int main()
{

    ll list;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        int roll;
        cin >> name;
        cin >> roll;
        list.insert_first(name, roll);
    }

    // Your code ends here #003
    list.print();
    return 0;
}