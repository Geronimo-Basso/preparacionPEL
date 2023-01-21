#include <iostream>
#ifndef ACTIVIDADGRUPAL_4_PILAGEN_H
#define ACTIVIDADGRUPAL_4_PILAGEN_H
template <typename T> class PilaGen {
protected:
    class  Nodo{
    public:
        T elemento;
        Nodo * siguiente;
        Nodo(T e){
            elemento = e;
            siguiente = 0;
        }
    };
    Nodo * primero;
public:
    PilaGen(){
        primero = 0;
    }
    void insertar_cabeza(T e){
        Nodo * nuevo = new Nodo(e);
        nuevo->siguiente = primero;
        primero = nuevo;
    }

    bool es_vacia(){
        return primero == 0;
    }

    int size(){
        int contador = 0;
        bool existe_enlace = true;
        Nodo* aux = primero;
        while (existe_enlace == true){
            if (aux->siguiente != 0){
                aux = aux->siguiente;
                ++contador;
            } else {
                existe_enlace = false;
            }
        }
        if (contador !=0){
            return contador+1;
        }
        return contador;
    }

    void eliminar_cabeza(){
        Nodo * aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    T pop(int pos) {
        Nodo *aux = primero;
        if (pos > size()) {
            std::cout << "No se puede extraer en dicha posicion" << std::endl;
        } else {
            Nodo *aux = primero;
            for (int i = 0; i < pos; ++i) {
                aux = aux->siguiente;
            }
            T salida = aux->elemento;
            eliminar_cabeza();
            return salida;
        }
    }

};
#endif //ACTIVIDADGRUPAL_4_PILAGEN_H
