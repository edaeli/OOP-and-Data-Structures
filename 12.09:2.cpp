#include <iostream>
#include <string>

template<typename T1,typename T2> 
class Pair{
private:
    T1 a;
    T2 b;

public:

    Pair(T1 f, T2 s) : a(f), b(s) {}
    

    T1 getFirst() const {
         return a;
    }

    T2 getSecond() const {
         return b;
    }

    void setFirst(const T1& f) { 
        a = f; 
    }
    void setSecond(const T2& s) { 
        b = s;
    }


    void print() const {
        std::cout << a << " " << b << std::endl;
    }

};


template<typename T,int N> 
class FixedArray{
private:
    T data[N];
public:
    void set(int index,T value){
        data[index] = value;
    }

    T get(int index){
        return data[index];
    }

    int size(){
        return N;
    }

};

template<typename T,int N,int M>
class Matrix{
private:
    T data[N][M];
public:
    void set(int row,int col,T value){
        data[row][col] = value;
    }

    T get(int row,int col){
        return data[row][col];
    }

    void print(){
        for(int i = 0;i < N;i++){
            for(int j = 0;j < M;j++){
                std::cout<<data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    Matrix<T,N,M> operator+(const Matrix<T,N,M>& other) const{
        Matrix<T,N,M> s;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                s.set(i, j, data[i][j] + other.data[i][j]);
            }
        }
        return s;
    }

    int rows() const {
        return N; 
    }
    int cols() const {
        return M;
    }

};

template<typename T>
class Range{
private:
    T start;
    T end;
public:
    Range(T s,T e) : start(s),end(e){}

    bool contains(const T& value){
        if(value >= start && value <= end)
            return true;
        return false;
    }

    T length(){
        return end - start;
    }

    void print(){
        std::cout<<"[" << start << "," << end << "]"<<std::endl;
    }

};


int main(){
    Pair<int,double> p1(5,3.2);
    p1.print();

    std::cout << "----------------" << std::endl;

    FixedArray<int, 5> arr;

    for (int i = 0; i < arr.size(); i++) {
        arr.set(i, i * 10);
    }

    for (int i = 0; i < arr.size(); i++) {
        std::cout << "arr[" << i << "] = " << arr.get(i) << std::endl;
    }

    std::cout << "----------------" << std::endl;

    std::cout<<"int matrix"<<std::endl;

    Matrix<int, 2, 3> A, B;

    int val = 1;
    for (int i = 0; i < A.rows(); i++) {
        for (int j = 0; j < A.cols(); j++) {
            A.set(i, j, val);
            B.set(i, j, val * 10);
            val++;
        }
    }

    std::cout <<"matrix 1"<<std::endl;
    A.print();
    std::cout <<"matrix 2"<<std::endl;
    B.print();

    std::cout<<"sum"<<std::endl;

    Matrix<int, 2, 3> C = A + B;
    C.print();

    std::cout << "double matrix"<<std::endl;
    Matrix<double, 2, 2> D, E;
    D.set(0, 0, 1.1); D.set(0, 1, 2.2);
    D.set(1, 0, 3.3); D.set(1, 1, 4.4);

    E.set(0, 0, 0.9); E.set(0, 1, 1.8);
    E.set(1, 0, 2.7); E.set(1, 1, 3.6);

    std::cout << "Matrix 1"<<std::endl;
    D.print();
    std::cout<<"matrix 2"<<std::endl;
    E.print();

    std::cout<<"sum"<<std::endl;

    Matrix<double, 2, 2> F = D + E;
    F.print();

    std::cout << "----------------" << std::endl;

    Range<int> r1(3, 10);
    r1.print();
    std::cout << "length = " << r1.length() << std::endl;
    std::cout << "contains(5)? " << r1.contains(5) << std::endl;
    std::cout << "contains(20)? " << r1.contains(20) << std::endl;

    std::cout << "\n";

    // double
    Range<double> r2(1.5, 4.2);
    r2.print();
    std::cout << "length = " << r2.length() << std::endl;
    std::cout << "contains(3.3)? " << r2.contains(3.3) << std::endl;

    std::cout << "\n";

    // char
    Range<char> r3('a', 'f');
    r3.print();
    std::cout << "length = " << (int)r3.length() << std::endl;
    std::cout << "contains('c')? " << r3.contains('c') << std::endl;
    std::cout << "contains('z')? " << r3.contains('z') << std::endl;

    return 0;

}
