
// Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).
// Operations on Stack:
// Mainly the following three basic operations are performed in the stack:
// Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
// Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
// Peek or Top: Returns the top element of the stack.
// isEmpty: Returns true if the stack is empty, else false.


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