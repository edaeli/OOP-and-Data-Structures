#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <forward_list>
#include <stdexcept>


//1

std::forward_list<int>  createAndFillList(int n){
   std::forward_list<int> list;
   for(int i = 1;i <= n;i++){
      list.push_front(i);
   }
   return list;
}

//2


bool insertAfterPosition(std::forward_list<int> &list,int pos,int value){
   int index = 0;
   for(auto it = list.begin();it != list.end();it++){
      if(index == pos){
         list.insert_after(it,value);
         return true;
      }
      index++;
   }
   return false;
}

//3

int removeAllOccurrences(std::forward_list<int> &list,int value){
   int s = 0;
   auto i = list.before_begin();
   auto it = list.begin();
   while(it != list.end()){
      if(*it == value){
         it = list.erase_after(i);
         s++;
      }
      else{
         i++;
         it++;
      }
   }
   return s;
}

//4

void mergeSortedLists(std::forward_list<int> &list1,std::forward_list<int> &list2){
   auto i = list1.before_begin();
   auto it1 = list1.begin();
   auto it2 = list2.begin();

   while(it1 != list1.end() && it2 != list2.end()){
      if(*it1 <= *it2){
         it1++;
         i++;
      }
      else{
         it1 = list1.insert_after(i,*it2);
         it2++;
      }
   }

   while(it2 != list2.end()){
      list1.insert_after(i,*it2);
      it2++;
      i++;
   }
   list2.clear();

}

//5

void moveElementsToFront(std::forward_list<int> &list,int value){
   std::forward_list<int> res;

   for(int x : list){
      if(x == value){
         res.push_front(x);
      }
   }

   for(int x : list){
      if(x != value){
         res.push_front(x);
      }
   }

   res.reverse();

   list = res;
}

//6

bool isOdd(int x) { return x % 2 != 0; }

template<typename P>
int removeIf(std::forward_list<int> &list,P p){
   int size_after = 0;
   int size_before = 0;

   for(int x : list){
      size_before++;
   }

   list.remove_if(p);
   for(int x : list){
      size_after++;
   }

   return size_before - size_after;
}




//8
class TaskManager {
private:
    std::vector<std::forward_list<std::string>> tasks; 

public:
    TaskManager(int levels) : tasks(levels) {}

    void addTask(int priority, const std::string& task) {
      auto& list = tasks[priority];
      if (list.empty()) {
         list.push_front(task);
         return;
      }

      auto it = list.before_begin();
      for (auto next = list.begin(); next != list.end();next++)
         it = next;
      list.insert_after(it, task);
    }

   std::string getNextTask() {
      for (int i = 0; i < tasks.size(); ++i){
         auto& list = tasks[i];
         if (!list.empty()) {
            std::string task = list.front();
            list.pop_front();
            return task;
         }
      }
      return "No tasks available";
    }

   void removeTask(int priority, const std::string& task) {

      auto& list = tasks[priority];
      auto prev = list.before_begin();
      auto it = list.begin();

      while (it != list.end()) {
         if (*it == task) {
            list.erase_after(prev);
               return;
         }
         ++prev;
         ++it;
      }
    }

    void printAllTasks() const {
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << "Priority " << i << ": ";
            if (tasks[i].empty()) {
                std::cout << "(no tasks)";
            } else {
                for (const auto& task : tasks[i])
                    std::cout << task << "; ";
            }
            std::cout << "\n";
        }
    }
};


//9

void printList(const std::forward_list<int>& fl) {
    for (int x : fl) 
      std::cout << x << " ";
    std::cout << "\n";
}

void insertionSort(std::forward_list<int>& fl) {
   std::forward_list<int> res;

   for(int x : fl){
      auto prev = res.before_begin();
      auto curr = res.begin();

      while(curr != res.end() && *curr <= x){
         curr++;
         prev++;
      }

      res.insert_after(prev,x);

      printList(res);
   }

   fl = res;
    
}

int main(){

   //1

   std::forward_list<int> list = createAndFillList(5);
   std::cout << "create and fill list" << std::endl;
   for(int x : list){
      std::cout << x << " ";
   }
   std::cout<<std::endl;

   std::cout << "----------------------------" << std::endl;


   //2

   std::cout << "insert after" << std::endl;

   std::forward_list<int> fl = {1, 2, 3, 4};
   insertAfterPosition(fl, 1, 99); 

   for(int x : fl){
      std::cout << x << " ";
   }
   std::cout<<std::endl;

   std::cout << "----------------------------" << std::endl;

   //3

   std::cout << "removeAllOccurrences" << std::endl;

   std::forward_list<int> fl1 = {1, 2, 3, 2, 4, 2};
   int removed = removeAllOccurrences(fl1, 2);

   for(int x : fl1){
      std::cout << x << " ";
   }
   std::cout<<std::endl;

   std::cout << removed << std::endl;

   std::cout << "----------------------------" << std::endl;

   //4

   std::cout << "removeAllOccurrences" << std::endl;

   

   std::forward_list<int> fl4 = {1, 3, 5};
   std::forward_list<int> fl5 = {2, 4, 6, 8};
   mergeSortedLists(fl4, fl5);

   for(int x : fl4){
      std::cout << x << " ";
   }
   std::cout<<std::endl;

   std::cout << "----------------------------" << std::endl;

   //5

   std::cout << "moveElementsToFront" << std::endl;

   std::forward_list<int> fl6 = {1, 3, 2, 3, 4, 3};
   moveElementsToFront(fl6, 3);

   for (int x : fl6)
      std::cout << x << " ";
   std::cout << "\n";

   std::cout << "----------------------------" << std::endl;


   //6

   std::cout << "Remove If" << std::endl;
   
   std::forward_list<int> f7 = {1, 2, 3, 4, 5, 6};
   int removedd = removeIf(f7, isOdd);

   std::cout << "Removed: " << removedd << "\n";
   for (int x : f7)
      std::cout << x << " ";
   std::cout << "\n";


   std::cout << "----------------------------" << std::endl;


   //9

   std::cout << "sort" << std::endl;
    std::forward_list<int> f = {5, 2, 8, 1, 9};
    insertionSort(f);
    std::cout << "Sorted: ";
    printList(f);

   return 0;


}

