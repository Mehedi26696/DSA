

//reverse the linked list by k nodes

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};  


//insert at tail
void InsertAtTail(Node* &tail,int d){
    //new node create

    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;  //we can use tail = tail->next;
}

Node* reverse(Node* head, int k){
    
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL){
        head->next = reverse(forward, k);
    }

    return prev;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int len;
    cin >> len;
    int k;
    cin >> k;

    for(int i = 0; i < len; i++){
        int x;
        cin >> x;
        if(head == NULL){
            Node* temp = new Node(x);
            head = temp;
            tail = temp;
        }
        else{
            InsertAtTail(tail, x);
        }
    }
    head = reverse(head, k);
    print(head);
    return 0;  
}
 