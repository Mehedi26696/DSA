
// Question:

// In general, memoization is a powerful optimization technique for recursive algorithms,
// but it should be used carefully depending on the specific characteristics of the problem
// being solved. Write down two cases where memoization would not be an effective
// strategy.

// Answer:


// 1. When the problem has a small input size, memoization would not be an effective strategy.
//    This is because the overhead of storing the results of subproblems in a table may outweigh
//    the benefits of avoiding redundant computations. In such cases, it may be more efficient to
//    simply solve the problem using a non-recursive approach.

// 2. When the problem has a large number of possible subproblems, memoization may not be an
//    effective strategy. This is because the memory required to store the results of all possible
//    subproblems may be prohibitive, and the time required to access and update the memoization
//    table may outweigh the benefits of avoiding redundant computations. In such cases, it may be
//    more efficient to use a different optimization technique, such as dynamic programming or
//    a different algorithm altogether.


// Question:

// Write a function in a linked list named deleteAtPosition that takes two parameters: the
// position of the node to be deleted and the head of the linked list. Implement the
// function in such a way that it deletes the node at the specified position and updates the
// pointers of the linked list accordingly. Assume that the linked list is 0-indexed, i.e., the
// first node is at position 0.
// Provide the time complexity of the function, considering n is the size of the linked list, and briefly
// explain why is that the case. Describe a scenario where you might use the deleteAtPosition function
// in a real-world application.


// Answer:

#include <iostream>
using namespace std;

struct ll {
     

    struct Node{
        int data;
        Node* next;
    };

    Node* head = NULL;
    Node* tail = NULL;

    void insert(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
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

    void deleteAtPosition(int position){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }

        if(position == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        for(int i = 0; temp != NULL && i < position - 1; i++){
            temp = temp->next;
        }

        if(temp == NULL || temp->next == NULL){
            cout << "Position out of range" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }


};

int main(){

    int n;
    cin>>n;
    ll linkedList;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        linkedList.insert(x);
    }
    linkedList.display();

    linkedList.deleteAtPosition(2);

    linkedList.display();

    linkedList.deleteAtPosition(0);

    linkedList.display();

    linkedList.deleteAtPosition(3);

    linkedList.display();

    return 0;
}

 



// Time complexity: O(n)
// The time complexity of the deleteAtPosition function is O(n), where n is the size of the linked list.

// This is because the function iterates through the linked list to find the node at the specified position,
// which requires traversing at most n nodes. Once the node is found, the function deletes the node and updates
// the pointers of the linked list, which can be done in constant time.

// A scenario where you might use the deleteAtPosition function in a real-world application is in a task management
// application where tasks are stored in a linked list. Users may want to delete a task at a specific position in the
// list, such as removing a completed task or rearranging the order of tasks. The deleteAtPosition function can be
// used to efficiently delete tasks at the specified position and update the list accordingly.

 