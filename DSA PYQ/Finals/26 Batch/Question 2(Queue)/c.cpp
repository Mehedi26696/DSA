
// c) Assume that a stack is implemented by a singly linked list. Write down a pseudocode of push and pop operation of the stack.

// Pseudocode
// push(value):
//     newNode = createNode(value)
//     newNode->next = top
//     top = newNode

// pop():
//     if top is NULL:
//         print "Stack is empty"
//         return
//     temp = top
//     top = top->next
//     delete temp


#include <iostream>
using namespace std;

struct LL{

    struct Node{
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
    };

    Node* top = NULL;

    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if(top == NULL){
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display(){
        Node* temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }



};


int main(){
    LL stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.display();
    stack.pop();
    stack.display();
    stack.pop();
    stack.display();
    stack.pop();
    stack.display();
    stack.pop();
    stack.display();
    return 0;
}