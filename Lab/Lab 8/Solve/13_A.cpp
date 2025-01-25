//13
//13
#include <iostream>
using namespace std;


struct llNode {
    llNode* next;
    int val;
};

struct LinkedList {
    llNode* head = NULL;
    llNode* tail = NULL;

    void insert_last(int x) {
 

        llNode* a = new llNode();   
        a->next = NULL;
        a->val = x;
        if (tail) {
            tail->next = a;
            tail = a;
        } else {
            head = a;
            tail = a;
        }
    }

    void show() {
        llNode* p = head;
        while (p) {
            cout << p->val <<endl;
            p = p->next;
        }
        
    }
};

struct llofAllNode {
    llofAllNode* next;
    LinkedList* list;
};

struct LinkedListofLinkedList {
    llofAllNode* head = NULL;
    llofAllNode* tail = NULL;

    void insert_last(LinkedList* x) {
 

 llofAllNode* a = new llofAllNode();   
        a->next = NULL;
        a->list = x;
        if (tail) {
            tail->next = a;
            tail = a;
        } else {
            head = a;
            tail = a;
        }
    }
};

LinkedList* sort(LinkedListofLinkedList* parent) {
    if (!parent->head) {

        return NULL;
    }

    llofAllNode* forward = parent->head;
    LinkedList* merged = forward->list;  
    forward = forward->next;
   
   // merge
    while (forward) {
        llNode* p1 = merged->head;
        llNode* p2 = forward->list->head;
        LinkedList* temp = new LinkedList();  
        while (p1 && p2) {

            // comaparison 
            if (p1->val <= p2->val) {
                temp->insert_last(p1->val);
                p1 = p1->next;
            } else {
                temp->insert_last(p2->val);
                p2 = p2->next;
            }
        }
  // remaining nodes

     
        while (p1) {
            temp->insert_last(p1->val);
            p1 = p1->next;
        }
        while (p2) {
            temp->insert_last(p2->val);
            p2 = p2->next;
        }

        // increment
        
        forward = forward->next;

        // merge update 
        merged = temp; 
        
    }

    return merged;
}

int main() {
    int n, m, v;
    cin >> n;
    LinkedListofLinkedList* parent = new LinkedListofLinkedList();

    // create
    for (int i = 0; i < n; i++) {
        LinkedList* l = new LinkedList();
        cin >> m;

        // 
        for (int j = 0; j < m; j++) {
            cin >> v;
            l->insert_last(v);
        }

        // insert to parent linked list
        parent->insert_last(l);
    }

    // sort function call

    LinkedList* sorted = sort(parent);

    sorted->show();

    return 0;

}