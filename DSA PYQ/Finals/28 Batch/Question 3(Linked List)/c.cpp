
// (c) sort the linked list

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

    void sort(){
        Node* current = head;
        Node* index = NULL;
        int temp;
        if(head == NULL){
            return;
        }else{
            while(current != NULL){
                index = current->next;
                while(index != NULL){
                    if(current->data > index->data){
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
};

int main(){
    LL ll;
    ll.insertAtEnd(5);
    ll.insertAtEnd(3);
    ll.insertAtEnd(8);
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(7);
    ll.insertAtEnd(6);
    ll.insertAtEnd(4);
    cout << "Original Linked List: ";
    ll.print();
    ll.sort();
    cout << "Sorted Linked List: ";
    ll.print();
    return 0;
}