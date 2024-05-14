#ifndef M_VECTOR_MYVECTOR_H
#define M_VECTOR_MYVECTOR_H
#include <initializer_list>
#include <cstddef>
#include <iostream>

template <typename T>
class MyVector;

template <typename T>
class Iterator {
private:
    T* cur;
    const MyVector<T>& object;
public:
    explicit Iterator<T> (const MyVector<T>& obj, T* cur):object(obj), cur(cur){};
    Iterator<T> next() const { ++cur; return *this; }
    T value() const { return *cur; }
    [[nodiscard]] bool is_end() const { return *this == object.end(); }
    Iterator<T> &operator++() { ++cur; return *this; }
    T &operator*() const { return *cur; }
    bool operator ==(const Iterator<T> &b) const { return cur == b.cur; }
    bool operator !=(const Iterator<T> &b) const { return cur!= b.cur; }
};


template <typename T>
class MyVector {

    friend class Iterator<T>;

    template<class Type>
    friend std::ostream& operator <<(std::ostream& os, const MyVector<Type>& lst);
    template<class Type>
    friend MyVector<Type> operator +(const MyVector<Type>& v1, const MyVector<Type>& v2);
    template<class Type>
    friend MyVector<Type> operator -(const MyVector<Type>& v1, const MyVector<Type>& v2);
    template<class Type>
    friend MyVector<Type> operator *(const MyVector<Type>& v1, const Type& val);
    template<class Type>
    friend MyVector<Type> operator /(const MyVector<Type>& v1, const Type& val);

private:
    int length;
    T* arr = nullptr;
public:
    explicit MyVector(int length);
    MyVector(const MyVector<T>& vector);
    MyVector(MyVector <T>&& vector) noexcept ;
    MyVector(std::initializer_list<T> lst);
    ~MyVector();
    MyVector<T>& operator =(const MyVector<T>& lst);
    [[nodiscard]] int getLength() const;
    void setElem(int index,const T& elem);
    T& get_elem(int index);
    T* to_array();
    T& operator[](int index);
    void printFullVector(); //my own programing view
    void sortBubble(); //lmao goat
    MyVector<T>& operator += (MyVector<T> vector);
    MyVector<T>& operator -= (MyVector<T> vector);
    MyVector<T>& operator *= (const T& val);
    MyVector<T>& operator /= (const T& val);
    Iterator<T> begin() const { return Iterator<T> (*this, arr); }
    Iterator<T> end() const { return Iterator<T> (*this, arr+length) ; }
};

template<typename Type>
std::ostream& operator<<(std::ostream& os, const MyVector<Type>& lst) {
    for (int i = 0; i < lst.length; ++i) {
        os << lst.arr[i] << ' ';
    }
    return os;
}

template<typename Type>
MyVector<Type> operator+(const MyVector<Type>& v1, const MyVector<Type>& v2) {
    if (v1.length != v2.length) {
        throw std::invalid_argument("Vectors must have the same size for addition");
    }
    MyVector<Type> result(v1);
    for (int i = 0; i < v1.length; ++i) {
        result.arr[i] += v2.arr[i];
    }
    return result;
}

template<typename Type>
MyVector<Type> operator-(const MyVector<Type>& v1, const MyVector<Type>& v2) {
    if (v1.length != v2.length) {
        throw std::invalid_argument("Vectors must have the same size for subtraction");
    }
    MyVector<Type> result(v1);
    for (int i = 0; i < v1.length; ++i) {
        result.arr[i] -= v2.arr[i];
    }
    return result;
}

template<typename Type>
MyVector<Type> operator*(const MyVector<Type>& v1, const Type& val) {
    MyVector<Type> result(v1.length);
    for (int i = 0; i < v1.length; i++) {
        result.arr[i] = v1.arr[i] * val;
    }
    return result;
}

template<typename Type>
MyVector<Type> operator/ (const MyVector<Type>& v1, const Type& val){
    if (val == static_cast<Type>(0)) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    MyVector<Type> result(v1.length);
    for (int i = 0; i < v1.length; i++) {
        result.arr[i] = v1.arr[i] / val;
    }
    return result;
}

#endif //M_VECTOR_MYVECTOR_H
