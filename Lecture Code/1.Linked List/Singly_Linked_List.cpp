

// Linked list : linear Data Structure - > collection of Nodes
// each node include data and next node address

// Using linked list we can modify array size during it's run time without copying it's values


#include <bits/stdc++.h>
using namespace std;

struct LL{

    struct Node{
        int data;
        Node* next;
    };

    Node* head = NULL;
    Node* tail = NULL;

    

    void insertAtStart(int data){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = head;
        head = newnode;
        if (tail == NULL) {
            tail = newnode;
        }
    }

    void insertAt(int data, int pos){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = NULL;

        if(pos == 0){
            newnode->next = head;
            head = newnode;
        }else{
            Node* temp = head;
            for(int i=0; i<pos-1; i++){
                temp = temp->next;
                if (temp->next == NULL) {
                    tail = newnode;
                }
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void insertAtEnd(int data){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }  

    void deleteAtStart(){
        if (head == NULL) {
            cout<<"List is empty"<<endl;
        }else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteAt(int pos){
        if (head == NULL) {
            cout<<"List is empty"<<endl;
        }else{
            Node* temp = head;
            if (pos == 0) {
                head = head->next;
                delete temp;
            }else{
                for(int i=0; i<pos-1; i++){
                    temp = temp->next;
                }
                Node* temp1 = temp->next;
                temp->next = temp1->next;
                delete temp1;
            }
        }
    }

    void deleteAtEnd(){
        if (head == NULL) {
            cout<<"List is empty"<<endl;
        }else{
            Node* temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }

            tail = temp;
            Node* temp1 = temp->next;
            temp->next = NULL;
            delete temp1;
        }
    }
};


int main()
{
    LL ll; 
  
    ll.insertAtStart(5);
    ll.insertAtStart(4);
    ll.insertAtStart(3);
    ll.insertAtStart(2);
    ll.insertAtStart(1);
    ll.display();

    ll.insertAt(10, 3);
    ll.display();

    ll.insertAtEnd(20);
    ll.display();

    ll.deleteAtStart();
    ll.display();

    ll.deleteAt(2);
    ll.display();

    ll.deleteAtEnd();
    ll.display();
    return 0;
}