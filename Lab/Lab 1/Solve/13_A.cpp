//13
//13
#include<iostream>
using namespace std;
class Node
{
     public:
     int val;
     Node* next;
     Node(int x){
        this->next = NULL;
        this->val = x;
     }
};

void insertatTail(Node* &head,Node* &tail,int x){

     
      Node* temp = new Node(x);
    
      if(tail == NULL){
         
        tail = temp;
        head = temp;
      }

      tail->next = temp;
      tail  = temp;
    
}

void print(Node* head){
     
     while (head!=NULL)
     {
         cout<<head->val<<endl;
         head = head->next;
     }
     
}


int main(){

    Node* head =NULL;
    Node* tail = NULL;

    int n;
    cin>>n;
    for (int i = 0; i <  n; i++)
    {
         int d;
         cin>>d;
         insertatTail(head,tail,d);
    }
    print(head);
    return 0;
}