#include <iostream>

template<typename T>
class CircularDeque {
    T *_data{};
    int _size = 0;
    int _capacity = 0;
    int head = 0;
    int rear = 0;


public:
    explicit CircularDeque(int n) : _capacity(n) {
        _data = static_cast<T *>(::operator new(n * sizeof(T)));
    }


    ~CircularDeque() {
        for (int i = 0; i < _size; ++i) {
            (*this)[i].~T();
        }
        ::operator delete(_data);
    }

    void push_back(const T &var) {
        if (_size + 1 > _capacity) {
            CircularDeque temp(2 * _size);
            for (int i = 0; i < _size; ++i) {
                temp.push_back(_data[i]);
            }
            std::swap(*this, temp);
        }

        new(_data + rear) T(var);
        _size++;
        rear++;
        rear = rear % _capacity;
    }

    void pop_back() {
        rear--;
        rear = (rear + _capacity) % _capacity;
        _data[rear].~T();
        _size--;
    }

    void push_front(const T &var) {
        if (_size + 1 > _capacity) {
            CircularDeque temp(2 * _size);
            for (int i = 0; i < _size; ++i) {
                temp.push_back(_data[i]);
            }
            std::swap(*this, temp);
        }

        head--;
        head = (head + _capacity) % _capacity;
        new(_data + head) T(var);
        _size++;
    }

    void pop_front() {
        _data[head].~T();
        head++;
        head = head % _capacity;
        _size--;
    }

    T &operator[](size_t i) {
        return _data[(head + i) % _capacity];
    }

    const T& operator[](size_t i) const{
        return _data[(head + i) % _capacity];
    }

    
    bool isEmpty() const { 
        return _size == 0; 
    }
    int getSize() const { 
        return _size;
    }
    T& frontElem() {
        return _data[head];
    }

    T& backElem() {
        return _data[(rear - 1 + _capacity) % _capacity];
    }
    

};

int main() {
    
}