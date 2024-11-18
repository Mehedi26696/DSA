

#include <bits/stdc++.h>
using namespace std;

struct STACK
{
    struct Stack
    {
        int val;
        Stack *next;
    };

    Stack *head = NULL;
    Stack *tail = NULL;

    void push(int ch)
    {
        Stack *node = (Stack *)malloc(sizeof(Stack));
        node->val = ch;
        node->next = NULL;

        if (head == NULL)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void pop()
    {
        if (head->next == NULL)
        {
            return;
        }

        Stack *node = head;
        while (node->next != tail)
        {
            node = node->next;
        }
        tail = node;
        tail->next = NULL;
    }

    int top()
    {
        return tail->val;
    }

    bool empty()
    {
        if (head->next == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    STACK stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;
    
    cout << stk.empty() << endl;
    return 0;
}