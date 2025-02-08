
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

    
    int middle(){
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
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
    cout<<ll.middle()<<endl;
    return 0;
}