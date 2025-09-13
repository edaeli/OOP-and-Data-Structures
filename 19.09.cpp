#include <iostream>
#include <string>
#include <array>

//1

std::array<int ,5> createArray(){
    std::array<int,5> arr = {1,2,3,4,5};
    return arr;
}

//2

std::array<int,10> fillArray(std::array<int,10> &arr,int x){
    for(int& i : arr){
        i = x;
    }
    return arr;
}

//3

template<int N>
int countEven(std::array<int, N> arr){
    int s = 0;
    for(int i = 0;i < arr.size();i++){
        if(arr[i]%2 == 0)
            s++;
    }
    return s;
}

//4

template<typename T,int N>
int findElement(std::array<T, N> arr,T other){
    for(int i = 0;i < arr.size();i++){
        if(arr[i] == other)
            return i;
    }
    return -1;
}

//5

template<typename T,int N>
void reverseArray(std::array<T,N> &arr){
    for(int i = 0;i < (arr.size())/2;i++){
        T n = arr[i];
        arr[i] = arr[arr.size()-i-1];
        arr[arr.size()-i-1] = n;
    }
}

//6

template<typename T,int N>
bool compareArrays(std::array<T,N> arr1,std::array<T,N> arr2){
    for(int i = 0;i < arr1.size();i++){
        if(arr1[i] != arr2[i])
            return false;
    }
    return true;
}


//7

template<typename T, int N, int M>
std::array<T, M> copySubArray(std::array<T, N> arr, int index, int count) {
    std::array<T, M> arr2{};
    if (index + count > N) {
        return arr2; 
    }

    for (int i = 0; i < M; i++) {
        arr2[i] = arr[index + i];
    }
    return arr2;
}

// 8

class Matrix3x3{
private:
    std::array<std::array<int, 3>, 3> data;
public:
    Matrix3x3(int a1,int a2,int a3,
              int a4,int a5,int a6,
              int a7,int a8,int a9){

              data = {{
                {a1,a2,a3},
                {a4,a5,a6},
                {a7,a8,a9}
              }};
    }


    int getElement(int row, int col){
        return data[row][col];
    }

    void setElement(int row,int col,int value){
        data[row][col] = value;
    }

    void transpose(){
        for(int i = 0;i < 3;i++)
            for(int j = i + 1;j < 3;j++)
                std::swap(data[i][j],data[j][i]);
    }

    void print(){
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                std::cout<<data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }



};

// 9

template<typename T,int N>
void shiftLeft(std::array<T,N>  &arr,int shift){
    for(int i = 0;i < shift;i++){
        T tmp = arr[0];
        for(int j = 0;j < arr.size()-1;j++){
            arr[j] = arr[j+1];
        }
        arr[arr.size() - 1] = tmp;
    }
}

//10

int triple(int x) {
    return x * 3;
}

template<typename T,int Rows,int Cols,typename P>
std::array<std::array<T, Rows>, Cols> process2DArray(std::array<std::array<T, Rows>, Cols> arr,P pred){

    std::array<std::array<T, Cols>, Rows> result{};

    for(int i = 0;i < Cols;i++){
        for(int j = 0;j < Rows;j++){
            result[i][j] = pred(arr[i][j]);;
        }
    }
    return result;
}

//11

template<typename T,int N>
bool validateArray(std::array<T, N> arr,T start,T end){
    for(int i = 0;i < arr.size();i++){
        if(arr[i] < start || arr[i] > end){
            return false;
        }
    }
    return true;
}

//12

template<int N>
std::array<int, 256> countFrequency(std::array<char, N> arr){
    std::array<int, 256> result{};
    for (char i : arr) {
        result[i]++;
    }
    return result;

}




int main(){

    //1
    std::array<int ,5> arr = createArray();
    for(int x : arr){
        std::cout<<x<<" ";
    }
    std::cout << std::endl;

    std::cout << "-----------------" << std::endl;

    //2
    std::array<int,10> array = {1,2,3,4,5,6,7,8,9,10};
    fillArray(array,13);
    for(int x : array){
        std::cout<<x<<" ";
    }
    std::cout << std::endl;

    std::cout << "-----------------" << std::endl;

    //3

    std::array<int,10> xmorexen = {1,2,3,4,5,6,7,8,9,11};

    std::cout << countEven<10>(xmorexen);
    std::cout << std::endl;

    std::cout << "-----------------" << std::endl;

    //4

    std::array<int,10> zoq = {3,5,6,6,7,5,15,6,9,11};
    std::cout<<findElement<int,10>(zoq,6) << std::endl;

    std::cout << "-----------------" << std::endl;

    //5

    std::array<int,10> banan = {3,5,6,6,7,5,15,6,9,11};
    reverseArray<int,10>(banan);
    for(int x : banan)
        std::cout << x << " ";
    
    std::cout << std::endl;

    std::cout << "-----------------" << std::endl;

    // 6

    std::array<int,10> dzmeruk = {3,5,6,6,7,5,15,6,9,11};
    std::array<int,10> dzmeruk2 = {3,5,6,6,7,5,15,6,9,11};
    std::array<int,10> sekh = {3,5,6,6,6,5,15,6,9,11};
    
    std::cout<<compareArrays<int,10>(dzmeruk,dzmeruk2) << std::endl;
    std::cout<<compareArrays<int,10>(dzmeruk,sekh) << std::endl;
    
    std::cout << "-----------------" << std::endl;

    // 7

    std::array<int, 10> ban = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto subban = copySubArray<int, 10, 5>(ban, 2, 5);

    for (int x : subban) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "-----------------" << std::endl;

    //8

    Matrix3x3 matrix(1, 2, 3,
                     4, 5, 6,
                     7, 8, 9);
    matrix.print();

    matrix.transpose();
    std::cout << "Transpose:" << std::endl;
    matrix.print();

    std::cout << "-----------------" << std::endl;

    //9
        
    std::array<int, 10> banman = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    shiftLeft<int,10>(banman,2);

    for(int x : banman)
        std::cout << x << " ";

    std::cout << "\n";

    std::cout << "-----------------" << std::endl;

    //10

    std::array<std::array<int, 3>, 3> arr2d = {{
        {{1, 2, 3}},
        {{4, 5, 6}},
        {{7, 8, 9}}
    }};

    auto tripled = process2DArray<int, 3, 3>(arr2d, triple);

    for (auto& row : tripled) {
        for (auto val : row){
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    //11

    std::array<int,10> arrr = {3,5,6,6,6,5,15,6,9,11};   
    
    std::cout << validateArray<int,10>(arrr,0,50) << std::endl;
    std::cout << validateArray<int,10>(arrr,10,50) << std::endl;

    std::cout << "-----------------" << std::endl;
    
    //12

    std::array<char, 5> text = {'h', 'e', 'l', 'l', 'o'};

    auto res = countFrequency<5>(text);

    for (char i : {'h', 'e', 'l', 'o'}) {
        std::cout  <<  i << "["<< res[i] << "]"<< "\n";
    }

    return 0;
}