
// b) Write down an algorithm to find the second largest element of a given singly linked list.  


#include <iostream>
#include <climits>
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

    void insert(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int secondLargest(){
        Node* temp = head;
        int first = INT_MIN;
        int second = INT_MIN;
        while(temp != NULL){
            if(temp->data > first){
                second = first;
                first = temp->data;
            } else if(temp->data > second && temp->data != first){
                second = temp->data;
            }
            temp = temp->next;
        }
        return second;
    }
};

int main() {
    LL ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);
    ll.insert(7);
    ll.insert(8);
    ll.insert(9);
    ll.insert(10);
    ll.display();
    cout << "Second largest element: " << ll.secondLargest() << endl;
    return 0;
}