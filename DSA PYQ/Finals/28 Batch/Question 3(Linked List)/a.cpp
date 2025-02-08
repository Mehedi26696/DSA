



// (a) Design a Linked List with following properties:
// 1. Insert an element at the start or end of the list in O(1) time.
// 2. Delete an element from the middle position in O(1) time.



#include <iostream>
#include <unordered_map>

using namespace std;


struct DL{

    struct Node{
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    Node* head = NULL;
    Node* tail = NULL;
    Node* mid = NULL;
    unordered_map<int, Node*> nodeMap;
     
    void insertAtStart(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            mid = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            if(nodeMap.size() % 2 == 0) 
            {
                mid = mid->prev;
            }
        }
        nodeMap[data] = newNode;
    }

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            mid = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            if(nodeMap.size() % 2 == 1)  
            {
                mid = mid->next;
            }
        }
        nodeMap[data] = newNode;
    }

    void deleteFromMiddle() {
        if (mid == NULL) return; // List is empty

        Node* temp = mid;
        if (mid->prev)  
        {
            mid->prev->next = mid->next;
        }
        if (mid->next)  {

            mid->next->prev = mid->prev;
        }

        if (nodeMap.size() % 2 == 0)
        {
            mid = mid->prev;
        }
        else
        {
            mid = mid->next;
        }

        nodeMap.erase(temp->data);
        delete temp;
    }
    void printList(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main() {
    DL dl;
    dl.insertAtStart(1);
    dl.insertAtStart(2);
    dl.insertAtStart(3);
    dl.insertAtStart(4);
    dl.insertAtStart(5);

    dl.insertAtEnd(6);
    dl.insertAtEnd(7);
    dl.insertAtEnd(8);
    dl.insertAtEnd(9);
    dl.insertAtEnd(10);

    dl.printList();

    dl.deleteFromMiddle();

    dl.printList();

    dl.deleteFromMiddle();

    dl.printList();

    return 0;
}

// Time Complexity: O(1) for all operations

