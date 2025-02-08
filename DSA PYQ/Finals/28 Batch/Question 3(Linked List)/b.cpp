
// (b) Write a code to find a linked list circular or not. 


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

    Node* head = NULL;
    Node* tail = NULL;
    
    void insertAtStart(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFromMiddle(Node* node){
        if(node == NULL || node->next == NULL){
            return;
        }
        Node* temp = node->next;
        node->data = temp->data;
        node->next = temp->next;
        delete temp;
       
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isCircular(){
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main(){
    LL ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);
    ll.insertAtEnd(6);
    ll.insertAtEnd(7);
    ll.insertAtEnd(8);
    ll.insertAtEnd(9);
    ll.insertAtEnd(10);
    ll.tail->next = ll.head;
    cout << (ll.isCircular() ? "Circular" : "Not Circular") << endl;
    return 0;
}