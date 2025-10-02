#include <iostream>
#include <string>
#include <array>
#include <vector>


struct ListNode {
    int data;
    ListNode* next;
    
    explicit ListNode(int val) : data(val), next(nullptr) {}
};

void printList(ListNode* head){
   while(head){
      std::cout << head->data << " ";
      head = head->next;
   }
   std::cout << std::endl;
}

template<typename T>
ListNode* createList(T value){
   return(new ListNode(value));
}

template <typename T, typename... Args>
ListNode* createList(T first, Args... rest) {
   ListNode* head = new ListNode(first);
   head->next = createList(rest...);
   return head;
}

//1

ListNode* findMiddle(ListNode* head){
   int size = 0;
   ListNode* tmp = head;
   while(tmp){
      size++;
      tmp = tmp->next;
   }
   for(int i = 0;i < size/2;i++){
      head = head->next;
   }
   return head;
}

//2

bool hasCycle(ListNode* head){
   ListNode* one = head;
   ListNode* two = head;

   while(two->next && two->next->next){
      one = one->next;
      two = two->next->next;
      if(one == two)
         return two;
   }
   return false;

}

//3


ListNode* deletedup(ListNode* head){
   ListNode* tmp = head;
   while(tmp && tmp->next){
      if(tmp->data != tmp->next->data){
         tmp = tmp->next;
      }
      else{
         tmp->next = tmp->next->next;
      }
   } 
   return head;
}

//4
ListNode* reverseList(ListNode* head) {
   ListNode* prev = nullptr;   
   ListNode* curr = head;      
   while (curr) {
      ListNode* head1 = curr->next; 
      curr->next = prev;              
      prev = curr;                     
      curr = head1;                 
   }
   return prev; 
}

//5

bool Palindrome(ListNode* head){
   ListNode* orig = head;
   ListNode* tmp = head;

   ListNode* mid = findMiddle(tmp);
   ListNode* rev = reverseList(mid);
   while(rev){
      if(orig->data != rev->data)
         return false;
      orig = orig->next;
      rev = rev->next;
   }

   return true;


}


int main(){

   //1
   ListNode* head = createList(1,2,3,4,5,6);
   std::cout << (findMiddle(head)->data) << std::endl;

   std::cout << "----------------------------" << std::endl;

   //2

   ListNode* head1 = new ListNode(1);
   head1->next = new ListNode(2);
   head1->next->next = new ListNode(3);
   head1->next->next->next = new ListNode(4);
   
   head1->next->next->next->next = head1->next;

   std::cout << std::boolalpha;
   std::cout << hasCycle(head1) << std::endl; 

   std::cout << "----------------------------" << std::endl;

   //3

   ListNode* head2 = createList(1,1,1,2,2,3,4,4);
   printList(deletedup(head2));

   std::cout << "----------------------------" << std::endl;

   //4

   ListNode* head3 = createList(1,2,3);
   printList(reverseList(head3));
   std::cout << "----------------------------" << std::endl;


   //5

   ListNode* head4 = createList(1,2,2,1);
   ListNode* head5 = createList(1,2,2,3);
   
   std::cout<<std::boolalpha;
   std::cout<<Palindrome(head4) << std::endl;
   std::cout<<Palindrome(head5) << std::endl;


   

   return 0;
}