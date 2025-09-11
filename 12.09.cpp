#include <iostream>




template<typename T>
void printelement(const T&elem) {
    std::cout << elem << std::endl;
}

template<typename T>
void mySwap(T& a,T& second_element) {
    T tmp = a;
    a = second_element;
    second_element = tmp;
}

template<typename T>
T sumArray(const T* array, int size){
    T sum{};
    for (int i = 0;i < size;i++) {
        sum += array[i];
    }
    return sum;

}


bool isEven(const int& x) {
    return x % 2 == 0;
}


template<typename T,typename P>
T* filter(const T* arr, int size, P pred,int& newsize) {
    newsize = 0;
    for (int i = 0; i < size; i++) {
        if (pred(arr[i])) {
    newsize++;
    }
 }
    T* filtered = new T[newsize];

    int index = 0;
    for (int i = 0; i < size;i++) {
        if (pred(arr[i])) {
            filtered[index++] = arr[i];
        }
    }
    return filtered;
}




int main() {
    printelement(5);
    printelement(5.7);
    printelement("goh em");

    printelement("-----------------------");

    int x = 5, y = 10;
    mySwap(x, y);
    printelement(x);
    printelement(y);

    double p = 5.4, q = 10.7;
    mySwap(p, q);
    printelement(p);
    printelement(q);

    std::string s1 = "banana", s2 = "Lyovi";
    mySwap(s1, s2);
    printelement(s1);
    printelement(s2);

    printelement("-----------------------");

    int arr[5] = { 1,2,3,4,5 };
    double arr1[5] = { 1.1,2.2,3.3,4.4,5.5 };
    std::string arr2[5] = {"liza", "Radik", "Putin", "Trump", "avagyan rubo"};


    printelement(sumArray(arr, 5));
    printelement(sumArray(arr1, 5));
    printelement(sumArray(arr2, 5));

    printelement("-----------------------");

    int arr5[5] = { 1,2,3,4,5 };

    int newsize = 0;

    int *arr8 = filter(arr5, 5, isEven, newsize);

    for (int i = 0;i < newsize;i++) {
        printelement(arr8[i]);
    }



}