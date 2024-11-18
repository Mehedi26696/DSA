//13
//13
//13
//13

#include<iostream>
using namespace std;

struct LinkedList{

   //struct diclare
   struct Node{
      int data;
      Node* next;
   };
   
   //head and tail initiallize
   Node* head = NULL;
   Node* tail = NULL;
   
   void insertAtfirst(int data){

      //new node create
      Node* newNode = new Node();
      newNode->data = data;
      newNode->next = NULL;

      if(head == NULL){
         head = newNode;
         tail = newNode;
      }
      else{
         newNode->next = head;
         head = newNode;
      }
   }

   void insertAtLast(int data){

      //new node create
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

   void Display(){
      Node* temp = head;
      while(temp!=NULL){
         cout<<temp->data<<endl;
         temp =temp->next;
      }
   }



};

int main(){

   int n;
   cin>>n;

   LinkedList list;

   for(int i =0;i<n;i++){
      int p,v;
      cin>>p>>v;
      if(p==0){
         list.insertAtfirst(v);
      }
      else{
         list.insertAtLast(v);
      }
   }

   list.Display();
   return 0;
}