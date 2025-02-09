
// For a given integer K, write a procedure which deletes the Kth element from a doubly linked list. Your procedure should cover all the cases:
// i) delete first element,
// ii) delete last element, and
// iii) delete any element other than the first and last element.

// In case of unavailability of the data, it will print a message.

#include <iostream>
using namespace std;

struct ll {
    
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;
    Node* tail = NULL;

    void insert(int data) {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void delete_kth(int k) {
        Node* temp = head;
        int i = 1;

        if (k == 1) {
            head = head->next;
            head->prev = NULL;
            delete temp;
            return;
        }

        while (temp != NULL && i < k) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Data not available" << endl;
            return;
        }

        if (temp->next == NULL) {
            temp->prev->next = NULL;
            delete temp;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    ll l;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l.insert(x);
    }
    
    l.display();
    int k;
    cin >> k;
    l.delete_kth(k);
    l.display();

    return 0;
}