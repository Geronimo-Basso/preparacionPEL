#include "vector"
using namespace std;

#ifndef PREPARACION_VECTORSORTING_H
#define PREPARACION_VECTORSORTING_H
class VectorSorting{
    template<typename T> vector<T> ordenar(vector<T> entrada){
        int size = entrada.size();
        vector<T> salida;
        for (int i = 0; i < size; ++i) {
            int min_Distance = numeric_limits<int>::max();
            int min_number = 0;
            for (int j = 0; j < entrada.size(); ++j) {
                if (entrada[j] < min_Distance){
                    min_Distance = entrada[j];
                    min_number = j;
                }
            }
            salida.push_back(entrada[min_number]);
            entrada.erase(entrada.begin()+min_number);
        }
        return salida;
    }
};
#endif //PREPARACION_VECTORSORTING_H
