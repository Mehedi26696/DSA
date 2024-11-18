
// reverse a linked list

//Recursive Method -2
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

Node* reverseRecursive(Node* &head) {
    if (head == NULL || head->next == NULL) { //if head is null or head next is null then return head
        return head;
    }
    Node* rest = reverseRecursive(head->next); //recursive call
    head->next->next = head; //reverse the link
    head->next = NULL;  //make next of head null
    return rest;
}

void InsertAtTail(Node* &head, Node* &tail, int d) {
    Node *temp = new Node(d);
    if (tail == NULL) {
        tail = temp;
        head = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; // Add a newline for better output formatting
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int length;
    cin >> length;
    for (int i = 1; i <= length; i++) {
        int x;
        cin >> x;
        InsertAtTail(head, tail, x);
    }
    head = reverseRecursive(head);
    print(head);
    return 0;
}
