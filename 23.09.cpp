#include <iostream>
#include <string>
#include <array>
#include <vector>

//1

void createAndFillVector(int n){
     std::vector<int>vec(n);
     for(int i = 0;i < vec.size();i++){
        vec[i] = i+1;
     }
     for(int x : vec){
        std::cout << x << " ";
     }
     std::cout<<std::endl;

     std::cout << "size-" << vec.size() << std::endl;
     std::cout << "capacity-" << vec.capacity();
     


}

//2

void workWithEmptyVector(){
   std::vector<int> vec;
   std::cout << "size-" << vec.size() << " ";
   std::cout << "capacity-" << vec.capacity() << std::endl;
   for(int i = 0;i < 9;i++){
      vec.push_back(i+1);
      std::cout << "size-" << vec.size() << " ";
      std::cout << "capacity-" << vec.capacity() << std::endl;
   }

   std::cout<<std::endl;

   for(int x : vec){
      std::cout << x << " ";
   }
   std::cout<<std::endl;
}



//3

std::vector<int> createVectorFromInput(){
   std::vector<int> vec;
   int n;
   while(1){
      std::cin >>n;
      if(n == 0)
         break;
      vec.push_back(n);
   }
   return vec;
}

//4

int removeElementsGreaterThan(std::vector<int> &vec,int n){
   int s = 0;
   for(int i = vec.size() - 1;i >= 0;i--){
      if(vec[i] > n){
         vec.pop_back();
         s++;
      }
   }
   return s;;
}

//5

void manageCapacity(std::vector<int> &vec){
   std::cout << "Current size - " << vec.size() << std::endl;
   std::cout << "Current capacity - " << vec.capacity() << std::endl;

   vec.reserve(500);
   for(int i = 1;i <= 500;i++){
      vec.push_back(i);
   }
}

//6

template<typename T>
void resizeVector(std::vector<T> &vec,int n,T value){
   vec.resize(n,value);
}

//7

std::vector<int> mergeSortedVectors(std::vector<int> vec1,std::vector<int> vec2){
   std::vector<int> merged;
   merged.reserve(vec1.size() + vec2.size());

   int i = 0;
   int j = 0;

   while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] < vec2[j]) {
            merged.push_back(vec1[i++]);
        } else {
            merged.push_back(vec2[j++]);
        }
    }

    while (i < vec1.size()) {
        merged.push_back(vec1[i++]);
    }
    while (j < vec2.size()) {
        merged.push_back(vec2[j++]);
    }

    return merged;

}

//8

int findSubsequence(std::vector<int> vec1,std::vector<int> vec2){
   for (int i = 0; i <= vec1.size() - vec2.size();i++) {
        bool flag = true;
        for (int j = 0; j < vec2.size(); j++) {
            if (vec1[i + j] != vec2[j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            return i; 
    }
    return -1; 
}

//9

std::vector<std::vector<int>> groupAdjacent(std::vector<int> vec){
   std::vector<std::vector<int>> groups;
   std::vector<int> current;
   current.push_back(vec[0]);

   for(int i = 1;i < vec.size();i++){
      if(vec[i] == vec[i-1])
         current.push_back(vec[i]);
      else{
         groups.push_back(current);
         current.clear();
         current.push_back(vec[i]);
      }
   }
   groups.push_back(current);

   return groups;

}

//10

bool isEven(int x) { return x % 2 == 0; }

template<typename T,typename P>
std::vector<T> filterVector(std::vector<T> vec,P pred){
   std::vector<T> filtered;
   for(int i = 0;i < vec.size();i++){
      if(pred(vec[i]) == 1)
         filtered.push_back(vec[i]);
   }

   return filtered;
}

//11

class DynamicMatrix{
private:
   std::vector<std::vector<int>> vec;
   int row,col;
public:
   DynamicMatrix(int r,int c) : row(r),col(c) {
      vec = std::vector<std::vector<int>>(row, std::vector<int>(col, 0));
   }

   int getElement(int r,int c){
      return vec[r][c];
   }

   void setElement(int r,int c,int value){
      vec[r][c] = value;
   }

   void addRow(){
      vec.push_back(std::vector<int>(col, 0));
      row++;
   }

   void addColumn(){
      for (auto& rows : vec) {
            rows.push_back(0);
      }
      col++;
   }

   void print(){
        for (int i = 0;i < row;i++) {
            for (int j = 0;j <  col;j++)
                std::cout << vec[i][j] << " ";
            std::cout << "\n";
        }
    }


};

//12


std::vector<int> findIntersection(std::vector<int> vec1,std::vector<int> vec2){
   std::vector<int> tmp;
   for(int x : vec1){
      for(int y : vec2){
         if(x == y){
            tmp.push_back(x);
         }
      }
   }

   std::sort(tmp.begin(), tmp.end());
   std::vector<int> res;   

   for (int i = 0; i < tmp.size(); i++) {
        if (res.empty() || res.back() != tmp[i]) {
            res.push_back(tmp[i]);
        }
    }

   return res;
}

//13

class VectorStats{
private:
   std::vector<double> vec;
public:
   VectorStats(std::vector<double> data) : vec(data){}

   double mean(){
      double s = 0;
      for(double x : vec){
         s += x;
      }
      return s / vec.size();
   }

   double median(){

      std::vector<double> tmp = vec;  
      std::sort(tmp.begin(), tmp.end());

      if(tmp.size() % 2 == 1)
         return tmp[tmp.size()/2];
      return (tmp[tmp.size()/2 - 1] + tmp[tmp.size()/2]) / 2.0;
   }

   void addValue(double value) {
      vec.push_back(value);
   }

   void removeValue(double value) {
      auto it = std::find(vec.begin(), vec.end(), value);
      if (it != vec.end()) {
         vec.erase(it); 
      }
   }



};

int main(){

   //1

   int n;
   std::cin >> n;
   createAndFillVector(n);
   std::cout << std::endl;

   std::cout << "-----------------------"  << std::endl;

   //2

   workWithEmptyVector();

   std::cout << "-----------------------" << std::endl;

   //3

   std::vector<int> inputVec = createVectorFromInput();

   std::cout << "vector size - " << inputVec.size() << " " << std::endl;

   for(int x : inputVec){
      std::cout << x << " ";
   }
   std::cout << "\n";

   std::cout << "-----------------------"  << std::endl;

   //4

   std::vector<int> v = {1, 3, 5, 7, 9};
   int removed = removeElementsGreaterThan(v, 5);

   for(int x : v){
      std::cout << x << " ";
   }
   std::cout << "\n";
   std::cout << removed << std::endl;

   std::cout << "-----------------------"  << std::endl;


   //5
   
   std::vector<int> v1 = {1, 3, 5, 7, 9};
   manageCapacity(v1);
   
   std::cout << "Size after - " << v1.size() << std::endl;
   std::cout << "Capacity after - " << v1.capacity() << std::endl;

   std::cout << "-----------------------"  << std::endl;

   //6

   std::vector<int> v2 = {1, 2, 3};
   resizeVector(v2, 5, 42);

   for(int  x : v2){
      std::cout << x << " ";
   }
   std::cout << "\n";

   std::cout << "-----------------------"  << std::endl;

   //7

   std::vector<int> vec1 = {1, 3, 5, 7};
   std::vector<int> vec2 = {2, 4, 6, 8, 9};
   std::vector<int> merged = mergeSortedVectors(vec1, vec2);

   for(int x : merged){
      std::cout << x << " ";
   }
   std::cout<<"\n";

   std::cout << "-----------------------"  << std::endl;

   //8

   std::vector<int> main_vec = {1, 2, 3, 4, 5, 6};
   std::vector<int> sub_vec = {3, 4, 5};
   int index = findSubsequence(main_vec, sub_vec);

   std::cout << index << std::endl;

   std::cout << "-----------------------"  << std::endl;

   //9


   std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};
   std::vector<std::vector<int>> groups = groupAdjacent(vec);

   std::cout << "-----------------------"  << std::endl;
   
   //10

   std::vector<int> victor = {1, 2, 3, 4, 5, 6};
   std::vector<int> filtered = filterVector(victor, isEven);

   for(int x : filtered){
      std::cout << x << " ";
   }
   std::cout << std::endl;

   std::cout << "-----------------------"  << std::endl;

   //11

   DynamicMatrix matrix(3, 3);

   matrix.setElement(1, 1, 42);  
   matrix.addRow();              
   matrix.addColumn();          
   matrix.print();

   std::cout << "-----------------------"  << std::endl;

   //12

   std::vector<int> a = {1, 2, 3, 4};
   std::vector<int> b = {3, 4, 5, 6};

   std::vector<int> inter = findIntersection(a, b);

   for (int x : inter)
      std::cout << x << " ";
   std::cout << std::endl;

   std::cout << "-----------------------"  << std::endl;

   //13

   VectorStats stats({1.0, 2.0, 3.0, 4.0});
   std::cout << "Mean: " << stats.mean() << "\n";    
   std::cout << "Median: " << stats.median() << "\n"; 

   stats.addValue(5.0);
   stats.removeValue(2.0);


   return 0;

}