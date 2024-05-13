#include "MyVector.h"
#include "MyVector.cpp"
#include <iostream>
int main() {
    MyVector<int> vector ({1,-2,1213,43,5,6,7,-123,5,256,6,3,632,63});
    vector.sortBubble();
    for (auto el: vector ){
        std::cout << el << " ";
    }
    MyVector<int> vector2 (10);
    int a = 0;
    for (auto iter = vector2.begin(); !iter.is_end(); ++iter){
        *iter = a;
        a++;
    }
    vector2/2;
    std::cout << vector2;
}
