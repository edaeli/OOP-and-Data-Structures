#include <iostream>
#include <string>
#include <utility>

//1

template<typename T>
void foo(T& arg) {
    std::cout << arg << " [lvalue]" << std::endl;;
}

template<typename T>
void foo(T&& arg) {
    std::cout << arg << " [rvalue]" << std::endl;
}

template<typename T>
void betterPrint(T&& first) {
    foo(std::forward<T>(first));
}

template<typename T, typename... Rest>
void betterPrint(T&& first, Rest&&... rest) {
    foo(std::forward<T>(first));
    betterPrint(std::forward<Rest>(rest)...);
}

//2


class Person{
private:
    std::string name;
    int age;
public:
    Person(std::string n,int a) : name(std::move(n)),age(a){}

    void print() const {
        std::cout << name << " " << age << "\n";
    }
};


template<typename T,typename... Rest>
T makeObject(Rest&&... rest){
    return T(std::forward<Rest>(rest)...);
}

int main() {

    //1

    int x = 42;
    betterPrint(x, 100, "hello");

    std::cout << "---------------" << std::endl;

    //2

    auto person = makeObject<Person>("Alice", 25);
    person.print();
}
