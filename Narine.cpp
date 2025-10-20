#include <iostream>
#include <string>
#include <cmath>
#include <vector>


#define PI 3.14

class Shape {
public:
    virtual double area() {};
    virtual void print() = 0;
};


class Circle : public Shape {
private:
    double r;
public:

    Circle(double radius) : r(radius){}
    Circle() : r(0.0){}


    double area() override {
        return PI*r*r;
    }

    void print() override  {
        std::cout << "Circle : " << this->area();
    }

    friend std::ostream& operator<<(std::ostream& os, const Circle& other);

};

std::ostream& operator<<(std::ostream& os, const Circle& other){
    os << other.r << "\n";
    return os;
}


class  Rectangle : public Shape {
private:
    double w;
    double h;
public:

    Rectangle(double we,double he) : w(we), h(he){}
    Rectangle() : w(0.0), h(0.0){}


    double area() override {
        return w*h;
    }

    void print() override {
        std::cout << "Rectangle: " << this->area();
    }

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& other);

};

std::ostream& operator<<(std::ostream& os, const Rectangle& other){
    os << other.w << " " << other.h << "\n";
    return os;
}

class  Triangle : public Shape {
private:
    double a;
    double h;
public:

    Triangle(double ae,double he) : a(ae), h(he){}
    Triangle() : a(0.0), h(0.0){}


    double area() override{
        return (a*h)/2;
    }

    void print() override {
        std::cout << "Triangle: " << this->area();
    }

    friend std::ostream& operator<<(std::ostream& os, const Triangle& other);

};

std::ostream& operator<<(std::ostream& os, const Triangle& other){
    os << other.a << " " << other.h << "\n";
    return os;
}


int main(){
    std::vector<Shape> vec(3);

    Circle circ(5);
    Rectangle rec(5,10);
    Triangle tri(20,10);
    
    vec[0] = circ;
    vec[1] = rec;
    vec[2] = tri;

    double s = 0;

    for(int i = 0;i < 3;i++){
        s += vec[0].area();
    }

    std::cout << s << std::endl;



}