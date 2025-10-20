// Create a custom Vector class that would support all the functionality given in main.cpp.

// Again: Declare your functions inside your class, but define them outside of it.

template <typename T>
class Vector {
    T *array = nullptr;
    size_t size_;
    size_t capacity_;

public:
    explicit Vector(size_t size = 0, T f = T{}) : array(static_cast<T *>(::operator new(sizeof(T) * size))),
                                                  size_(size),
                                                  capacity_(size) {
        for (int i = 0; i < size_; ++i) {
            new(array + i) T(f);
        }
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }

    Vector(std::initializer_list<T> lst) : array(static_cast<T *>(::operator new(sizeof(T) * lst.size()))),
                                           size_(lst.size()),
                                           capacity_(lst.size()) {
        size_t i = 0;
        for (T obj: lst) {
            new(array + i) T(obj);
            ++i;
        }
    }

    const T &operator[](size_t index) const {
        return array[index];
    }

    T &operator[](size_t index) {
        return array[index];
    }

    void push_back(const T &el) {
        if (size_ == capacity_) {
            if (capacity_ == 0) {
                reserve(1);
            } else {
                reserve(capacity_ * 2);
            }
        }
        new(array + size_) T(el);
        ++size_;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity <= capacity_) {
            return;
        }
        T *newArr = static_cast<T *>(::operator new(sizeof(T) * new_capacity));
        for (int i = 0; i < size_; ++i) {
            new(newArr + i) T(std::move(array[i]));
        }
        for (int i = 0; i < size_; ++i) {
            array[i].~T();
        }
        ::operator delete(array);
        capacity_ = new_capacity;
        array = newArr;
    }

    void shrink_to_fit() {
        if (capacity_ == size_) {
            return; 
        }

        if (size_ == 0) {
            ::operator delete(array);
            array = nullptr;
            capacity_ = 0;
            return;
        }

        T* newArr = static_cast<T*>(::operator new(sizeof(T) * size_));
        for (size_t i = 0; i < size_;i++) {
            new(newArr + i) T(std::move(array[i]));
            array[i].~T();
        }
        ::operator delete(array);
        array = newArr;
        capacity_ = size_;
    }


    void pop_back() {
        array[size_ - 1].~T();
        size_--;
    }

    Vector(const Vector &other) : size_(other.size_), capacity_(other.capacity_) {
        array = static_cast<T *>(::operator new(sizeof(T) * other.capacity_));
        for (int i = 0; i < size_; ++i) {
            new(array + i) T(other.array[i]);
        }
    }

    Vector &operator=(const Vector &other) {
        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < size_; ++i) {
            array[i].~T();
        }
        ::operator delete(array);

        size_ = other.size_;
        capacity_ = other.capacity_;
        array = static_cast<T *>(::operator new(sizeof(T) * other.capacity_));
        for (int i = 0; i < size_; ++i) {
            new(array + i) T(other.array[i]);
        }

        return *this;
    }

    bool operator==(const Vector &other) const {
        if (size_ != other.size_) {
            return false;
        }
        for (int i = 0; i < size_; ++i) {
            if (array[i] != other[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector &other) const {
        return !(*this == other);
    }

    void clear() {
        for (int i = 0; i < size_; i++) {
            array[i].~T();
        }
        size_ = 0;
    }

    bool empty() const {
        return size_ == 0;
    }

    void swap(Vector& other) noexcept {
        std::swap(array, other.array);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }

    T& operator[](size_t index){
        return array[index];
    }

    const T& operator[](size_t index) const {
        return array[index];
    }


    ~Vector() {
        for (int i = 0; i < size_; ++i) {
            array[i].~T();
        }
        ::operator delete(array);
    }
};
