//13
//13
//13
//13
#include <iostream>
using namespace std;

struct ll
{

    struct node
    {
        node *next;
        int val;
    };
    node *head=NULL;
    node *tail=NULL;

    void insert_last(int x)
    {
        //insert x at last
        //Your code starts here #001
         
         node* newNode = new node();
         newNode->val = x;
         newNode->next = NULL;

         if(head == NULL){
            head = newNode;
            tail = newNode;
         }
         else{
            tail->next = newNode;
            tail = newNode;
         }
        
        //Your code ends here #001
    }

    void sort(){
        //Sorts the linked list

        //Your code starts here #002
         
         node* a = head;
         while(a!=NULL){
            node* b = a->next;
            while(b!=NULL){
               if(a->val>b->val){
                  int t = a->val;
                  a->val = b->val;
                  b->val = t;
               }
               
               b = b->next;
            }

            a = a->next;
         }
        
        //Your code ends here #002
    }

    void print()
    {
        //prints elements from head to tail
        //Your code starts here #003
         
         node* temp = head;

         while(temp!=NULL){
            cout<<temp->val<<endl;
            temp = temp->next;
         }
        
        //Your code ends here #003
    }
};


int main()
{

    //Your code starts here #004
    
     ll list;

     int n;
     cin>>n;
     for(int i =0;i<n;i++){
      int v;
      cin>>v;
      list.insert_last(v);
     }

     list.sort();

     list.print();
        
    //Your code ends here #004
    return 0;


}