
// Middle of a Linked List (Recursive)
#include<iostream>
using namespace std;

struct LL {
    struct node {
        int data;
        node *next;
    };
    node *head = nullptr;
    node *tail = nullptr;

    void insert_last (int x) {
        node *a = new node;
        a->data = x;
        a->next = nullptr;
        if(head==nullptr) {
            head = a;
            tail = a;
        }
        else {
            tail->next = a;
            tail = a;
        }
    }
    void middle_recursive(node *&head, node *&slow, node *&fast, node *&prev) {
        if (fast == nullptr || fast->next == nullptr) {
            if (prev != nullptr) {
                cout << slow->data << endl;
            } else {
                head = nullptr;
            }
            return;
        }
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        middle_recursive(head, slow, fast, prev);
    }

    void middle(node *head) {
        if (head == nullptr) {
            return;
        }
        node *slow = head;
        node *fast = head;
        node *prev = nullptr;
        middle_recursive(head, slow, fast, prev);
    }
    void print() {
        node *p = head;
        while(p) {
            cout<<p->data<<" ";
            p = p->next;
        }
    }
    ~LL() {
        node *p = head;
        while(p) {
            node *temp = p;
            p = p->next;
            delete temp;
        }
    }
};
int main() {
   
    LL list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        list.insert_last(num);
    }
    list.middle(list.head);
    list.print();
    return 0;
}