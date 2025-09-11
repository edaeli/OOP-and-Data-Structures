#include <iostream>
#include <string>

template <typename T>
void printValue(const T& value) {
    std::cout << value << std::endl;
}


template <>
void printValue<bool>(const bool& value) {
    if(value)
        std::cout<<"true"<<std::endl;
    else
        std::cout << "false" << std::endl;
}

template <>
void printValue<char*>(char* const& value) {
    std::cout << "\"" << value << "\"" << std::endl;
}

template <>
void printValue<const char*>(const char* const& value) {
    std::cout << "\"" << value << "\"" << std::endl;
}


template <typename T>
bool isEqual(const T& a,const T& b) {
    return a == b;
}

template <>
bool isEqual<const char*>(const char* const& a, const char* const& b) {
    return std::strcmp(a, b) == 0;
}

template <typename T>
T copyValue(const T& value) {
    return value; 
}

template <typename T>
T* copyValue(T* ptr) {    
    return new T(*ptr);             
}

template<typename T1,typename T2>
class Pair{
private:
    T1 t1;
    T2 t2;
public:

    Pair(const T1& a, const T2& b) : t1(a), t2(b) {}

    void print(){
        std::cout << t1 << " " << t2 << std::endl;
    }
};

template <typename T>
class Pair<T, T> {
    T t1;
    T t2;
public:
    Pair(const T& a, const T& b) : t1(a), t2(b) {}

    void print() const {
        std::cout << "Pair of identical types: " 
                  << t1 << ", " << t2  << std::endl;
    }
};


int main() {
    printValue(42);          
    printValue(3.14);        
    printValue(true);        
    printValue(false);      
    printValue("Hello!");    
    
    char str[] = "World";
    printValue(str);        

    std::cout<< "---------------" << std::endl;

    std::cout << std::boolalpha;

    std::cout << isEqual(10, 10) << std::endl;          
    std::cout << isEqual(10, 20) << std::endl;          
    std::cout << isEqual(3.14, 3.14) << std::endl;      
    std::cout << isEqual(true, false) << std::endl;    

    const char* s1 = "Hello";
    const char* s2 = "Hello";
    const char* s3 = "World";

    std::cout << isEqual(s1, s2) << std::endl;          
    std::cout << isEqual(s1, s3) << std::endl;          

    std::cout<<"--------------"<<std::endl;

    int a = 42;
    int b = copyValue(a);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    int* p1 = new int(100);
    int* p2 = copyValue(p1);   
    std::cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << std::endl;

    *p2 = 200; 
    std::cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << std::endl;

    delete p1;
    delete p2;

    std::cout << "---------------" << std::endl;

    Pair<int, double> p3(10, 3.14);
    p3.print(); 

    Pair<std::string, std::string> p4("Hello", "World");
    p4.print(); 

    Pair<int, int> p5(5, 7);
    p5.print(); 
    return 0;
}
