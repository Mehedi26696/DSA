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
   node *head = NULL;
   node *tail = NULL;

   void insert_last(int x)
   {
      // insert x at last

      // Your code starts here #001

      node *newNode = new node();
      newNode->val = x;
      newNode->next = NULL;

      if (head == NULL)
      {
         head = newNode;
         tail = newNode;
      }
      else
      {
         tail->next = newNode;
         tail = newNode;
      }

      // Your code ends here #001
   }

   void delete_range(int l, int u)
   {
      // deletes values within the range l and u, inclusive

      // Your code starts here #002

      if (head == NULL)
      {
         return;
      }

      node *a = head;
      if(head==tail){
         head = NULL;
         return;
      }
      
      while (a->next->val != l)
      {
         a = a->next;
      }

      node *b = head;

      while (b->val != u)
      {
         b = b->next;
      }

      a->next = b->next;

      // Your code ends here #002
   }

   void print()
   {
      // prints elements from head to tail

      // Your code starts here #003

      if (head == NULL)
      {
         return;
      }
      node *temp = head;
      while (temp != NULL)
      {
         cout << temp->val << endl;
         temp = temp->next;
      }

      // Your code ends here #003
   }
};

int main()
{

   // Your code starts here #004
   ll list;

   int n;
   cin >> n;

   for (int i = 0; i < n; i++)
   {
      int v;
      cin >> v;
      list.insert_last(v);
   }

   int l, u;
   cin >> l >> u;

   list.delete_range(l, u);

   list.print();

   // Your code ends here #004
   return 0;
}