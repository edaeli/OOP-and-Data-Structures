#include <iostream>
#include <string>
#include <array>

//1

int sum(){
    return 0;
}

template<typename... Rest>
int sum(int first,Rest... rest){
    return first + sum(rest...);
}

//2

template<typename T>
T findMax(T value) {
    return value; 
}

template<typename T, typename... Rest>
auto findMax(T first, Rest... rest) {
    auto maxx = findMax(rest...);
    if(first > maxx)
        return first;
    return maxx;
}

//3

int countArgs() {
    return 0; 
}

template<typename T, typename... Rest>
int countArgs(T first, Rest... rest) {
    return countArgs(rest...) + 1;
}

//4
std::string makeSentence(std::string value) {
    return value + "."; 
}

template<typename... Rest>
std::string makeSentence(std::string first, Rest... rest) {
    return first + makeSentence(rest...); 
}

//5

class Logger{
private:
    int count;
public:
    Logger(int a) : count(a){}

    void log(){
        return;
    }

    template<typename T, typename... Rest>
    void log(T first, Rest... rest){
        for(int i = 0;i < count;i++){
            std::cout << " ";
        }
        std::cout<<first << std::endl;
        log(rest...);
    }

};

//6

int square(int x) {
    return x * x;
}

template<typename P,typename T>
void applyAndPrint(P pred,T value){
    std::cout<<pred(value) << std::endl;

}

template<typename P,typename T,typename... Rest>
void applyAndPrint(P pred,T first,Rest... rest){
    std::cout << pred(first) << std::endl;
    applyAndPrint(pred,rest...);
}

//7

template<typename T1, typename T2>
auto makePairList(T1 a, T2 b) {
    return std::pair<T1, T2>(a, b);
}

template<typename T1, typename T2, typename... Rest>
auto makePairList(T1 a, T2 b, Rest... rest) {
    return std::pair(a, makePairList(b, rest...));
}




int main(){

    //1

    std::cout<<sum(5,2,4)<<std::endl;   
    std::cout<<"---------------"<<std::endl;

    //2
    std::cout << findMax(3, 7, 2, 9, 5) << std::endl;
       
    std::cout<<"---------------"<<std::endl;

    //3

    std::cout << countArgs(3, 7, 2, 9, 5) << std::endl;
    std::cout<<"---------------"<<std::endl;

    //4
    
    std::cout << makeSentence("s", "nick", "ers") << std::endl;
    std::cout<<"---------------"<<std::endl;

    //5

    Logger logger(4);  
    logger.log("Hello", 42, 3.14, 'A');
    std::cout<<"---------------"<<std::endl;

    //6

    applyAndPrint(square, 2, 3, 4, 5);
    std::cout<<"---------------"<<std::endl;

    //7
    auto pair1 = makePairList(5, 'c');
    std::cout << pair1.first << ", " << pair1.second << "\n";  

    auto pair2 = makePairList(5, 'c', 4.32);
    std::cout << pair2.first << ", " 
              << pair2.second.first << ", "
              << pair2.second.second << "\n";

    auto pair3 = makePairList(1, 2, 3, 4);
    std::cout << pair3.first << " , "
              << pair3.second.first << " , "
              << pair3.second.second.first << " , "
              << pair3.second.second.second << "\n";

}