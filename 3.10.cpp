#include <iostream>
#include <string>
#include <array>
#include <vector>


struct ListNode {
    int data;
    ListNode* next;
    
    explicit ListNode(int val) : data(val), next(nullptr) {}
};

//1

void printList(ListNode* head){
   while(head){
      std::cout << head->data << " ";
      head = head->next;
   }
   std::cout << std::endl;
}

//2

size_t listLength(ListNode* head){
   size_t s = 0;
   while(head){
      s++;
      head = head->next;
   }
   return s;
}

//3

bool findNode(ListNode* head, int value){
   while(head){
      if(head->data == value)
         return true;
      head = head->next;
   }
   return false;
}

//4 

ListNode* deleteValue(ListNode* head, int value){
   ListNode* tmp = head;
   while(tmp->next && tmp->next->next){
      if(tmp->next->data != value){
         tmp = tmp->next;
      }
      else{
         tmp -> next = tmp->next->next;
      }
   }
   return head;

}

//5
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


//6
int binary(ListNode* head){
   int result = 0;
   while(head){
      result = result*2;
      result += head->data;
      head = head->next;
   }
   return result;
}

int main() {

   //1

   ListNode* head = new ListNode(1);
   head->next = new ListNode(2);
   head->next->next = new ListNode(3);

   printList(head);

   std::cout << "----------------------------" << std::endl;

   //2

   std::cout << listLength(head) << std::endl;

   std::cout << "----------------------------" << std::endl;

   //3

   std::cout << std::boolalpha; 
   std::cout << findNode(head, 2) << std::endl; 
   std::cout << findNode(head, 5) << std::endl; 

   std::cout << "----------------------------" << std::endl;

   //4

   head = deleteValue(head, 2);
   printList(head);

   std::cout << "----------------------------" << std::endl;

   //5

   ListNode* head1 = createList(1,2,3,4,5);
   printList(head1);

   std::cout << "----------------------------" << std::endl;

   //6

   ListNode* head2 = createList(1,0,1,1);
   std::cout << binary(head2) << std::endl;

   std::cout << "----------------------------" << std::endl;


   return 0;
}
