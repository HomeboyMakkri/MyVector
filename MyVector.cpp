#include "MyVector.h"

template <class T>
MyVector<T>::MyVector(int length) : length(length){
    if (length <= 0){
        throw std::out_of_range("Invalid index");
    }
    arr = new T[length];
}

template <class T>
MyVector<T>::MyVector(const MyVector<T>& vector){
    length = vector.length;
    for (int i = 0; i < length; i++)
        arr[i] = vector->arr[i];
}

template <class T>
MyVector<T>::MyVector(MyVector <T>&& vector) noexcept{
    length = vector.length;
    arr = vector.arr;
    vector.arr = nullptr;
}

template <class T>
MyVector<T>::MyVector(std::initializer_list<T> lst) : length(lst.size()), arr(new T[lst.size()]) {
    std::copy(lst.begin(), lst.end(), arr);
}

template <class T>
MyVector<T>::~MyVector(){
    delete[] arr;
}

template <class T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &lst) {
    if (this == &lst){
        return *this;
    }
    delete arr;
    length = lst.length;
    arr = new T[length];
    for (int x = 0; x < length; x++)
        arr[x] = lst.arr[x];

    return *this;
}

template<class T>
int MyVector<T>::getLength() const{
    return length;
}

template<class T>
void MyVector<T>::setElem(int index,const T& elem){
    arr[index] = elem;
}

template<class T>
T& MyVector<T>::get_elem(int index){
    return arr[index];
}

template<class T>
T* MyVector<T>::to_array(){
    T* newArr = new T*[length];
    for(int i = 0; i < length; i++){
        newArr[i] = arr[i];
    }
    return newArr;
}


template<class T>
T& MyVector<T>::operator[](int index) {
    if ((index >= 0) && index < length) return arr[index];
    else throw std::out_of_range("Invalid index");
}

template<class T>
MyVector<T>& MyVector<T>::operator += (const MyVector<T> vector){
    for(int i = 0; i < length; i++){
        arr[i] +=vector.arr[i];
    }
    return *this;
}

template<class T>
MyVector<T>& MyVector<T>::operator -= (const MyVector<T> vector){
    for(int i = 0; i < length; i++){
        arr[i] -=vector.arr[i];
    }
    return *this;
}

template<class T>
MyVector<T>& MyVector<T>::operator *= (const T& val){
    for(int i = 0; i < length; i++){
        arr[i] *= val;
    }
    return *this;
}

template<class T>
MyVector<T>& MyVector<T>::operator /= (const T& val){
    for(int i = 0; i < length; i++){
        arr[i] /= val;
    }
    return *this;
}

template<class T>
void MyVector<T>::printFullVector(){
    int i = 0;
    std::string strOut = std::to_string(arr[i]);
    int symbols = length-1;
    while (symbols != 0){
        i++;
        strOut += ", ";
        strOut += std::to_string(arr[i]);
        symbols--;
    }
    std::cout << strOut;
}
template<class T>
void MyVector<T>::sortBubble(){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length - i - 1; j++){
            if (arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
        }
    }
}

