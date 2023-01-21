#include <iostream>
#include "ColaGen.h"

template <typename T> bool iguales(ColaGen<T> * cola0, ColaGen<T> * cola1){
    if (cola0->size() != cola1->size()){
        return false;
    }
    auto size = cola0->size();
    for (int i = 0; i < size; ++i) {
        if (cola0->pop() != cola1->pop()){
            return false;
        }
    }
    return true;
}

int main() {
    auto * cola0 = new ColaGen<int>;
    auto * cola1 = new ColaGen<int>;
    cola0->insertar_cola(1);
    cola0->insertar_cola(2);
    cola0->insertar_cola(3);
    cola1->insertar_cola(1);
    cola1->insertar_cola(2);
    cola1->insertar_cola(3);
    std::cout << iguales(cola0, cola1);
    return 0;
}
