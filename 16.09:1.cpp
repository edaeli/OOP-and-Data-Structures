#include <iostream>
#include <string>

template<typename... Args>
void foo(Args... args){
    std::cout<<"Hello"<<std::endl;
}

void print(){
    std::cout << "\n";
}

template<typename T,typename... Args>
void print(T first,Args... args){
    std::cout << first << ' ';
    print(args...);
}


int sum(){
    return 0;
}

template<typename... Rest,typename T>
T sum(T first,Rest... rest){
    return first + sum(rest...);
}


template<typename T>
T findMax(T first){
    return first;
}

template<typename... Rest,typename T>
auto findMax(T first,Rest... rest){
    auto maxx = findMax(rest...);
    if(first > maxx)
        return first;
    else
        return maxx;
}

int count(){
    return 0;
}

template<typename... Rest,typename T>
auto count(T first,Rest... rest){
    return (count(rest...) + 1);
}

std::string makeSentence(std::string first){
    return first + ".";
}

template<typename... Rest>
std::string makeSentence(std::string first,Rest... rest){
    return first + makeSentence(rest...);

}



/*
template<typename F,typename T>
auto callFunction(F function,T obj){
    return function(obj);
}

int square(int x){
    return x*x;
}

double dsquare(double x){
    return x*x;
}
*/

int main(){

    print(2,4.3);
    std::cout<<"---------------"<<std::endl;

    std::cout<<sum(5,2,4)<<std::endl;
    std::cout<<sum(4.3,4.2,7.1)<<std::endl;   

    std::cout<<"---------------"<<std::endl;

    //callFunction(print,4);


    std::cout<<findMax(4,3,5,1,6,0,2)<<std::endl;

    std::cout<<"---------------"<<std::endl;

    std::cout<<count(1,2,3,4,5,6,7)<<std::endl;

    std::cout<<"---------------"<<std::endl;

    std::cout<<makeSentence("s","nick","ers")<<std::endl;

    return 0;
}
