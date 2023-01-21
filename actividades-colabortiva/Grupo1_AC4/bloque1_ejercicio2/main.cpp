//
// Created by victo on 09/01/2023.
//
#ifndef ACTIVIDADGRUPAL4EJERCICIO3_LISTAENLAZADA_H
#define ACTIVIDADGRUPAL4EJERCICIO3_LISTAENLAZADA_H
using namespace std;
#include "iostream"
class ListaEnlazadaInt {
public:
    ListaEnlazadaInt();
    ~ListaEnlazadaInt();
    void insertarInicio(int valor);
    void insertarFinal(int valor);
    void eliminarInicio();
    void eliminarFinal();
    bool vacia() const;
    int tamanio() const;
    int obtenerInicio() const;
    int obtenerFinal() const;
public:
    struct NodoInt {
        int valor;
        NodoInt* siguiente;
    };
    NodoInt* inicio_;
    NodoInt* final_;
    int tamanio_;
};

ListaEnlazadaInt::ListaEnlazadaInt()
        : inicio_(nullptr), final_(nullptr), tamanio_(0) {}

ListaEnlazadaInt::~ListaEnlazadaInt() {
    while (!vacia()) {
        eliminarInicio();
    }
}

bool ListaEnlazadaInt::vacia() const {
    return tamanio_ == 0;
}
void ListaEnlazadaInt::insertarInicio(int valor) {
    NodoInt* nuevo_nodo = new NodoInt;
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = inicio_;
    inicio_ = nuevo_nodo;
    if (tamanio_ == 0) {
        final_ = inicio_;
    }
    tamanio_++;
}

void ListaEnlazadaInt::insertarFinal(int valor) {
    NodoInt* nuevo = new NodoInt;
    nuevo->valor = valor;
    nuevo->siguiente = nullptr;
    if (tamanio_ == 0) {
        inicio_ = nuevo;
    } else {
        final_->siguiente = nuevo;
    }
    final_ = nuevo;
    tamanio_++;
}

void ListaEnlazadaInt::eliminarInicio() {
    if (tamanio_ == 0) {
        return;
    }
    NodoInt* eliminar = inicio_;
    inicio_ = inicio_->siguiente;
    delete eliminar;
    tamanio_--;
    if (tamanio_ == 0) {
        final_ = nullptr;
    }
}

void ListaEnlazadaInt::eliminarFinal() {
    if (tamanio_ == 0) {
        return;
    }
    if (tamanio_ == 1) {
        delete inicio_;
        inicio_ = nullptr;
        final_ = nullptr;
    } else {
        NodoInt* eliminar = final_;
        NodoInt* penultimo = inicio_;
        while (penultimo->siguiente != final_) {
            penultimo = penultimo->siguiente;
        }
        penultimo->siguiente = nullptr;
        final_ = penultimo;
        delete eliminar;
        tamanio_--;
    }
}

int ListaEnlazadaInt::tamanio() const {
    return tamanio_;
}


#endif //ACTIVIDADGRUPAL4EJERCICIO3_LISTAENLAZADA_H

int main (){
    ListaEnlazadaInt lista;
    int valor1, valor2, valor3, valor4, valor5;
    cout << "inserte el valor 5: ";
    cin >> valor1;

    cout << "inserte el valor 4: ";
    cin >> valor2;

    cout << "inserte el valor 3: ";
    cin >> valor3;

    cout << "inserte el valor 2: ";
    cin >> valor4;

    cout << "inserte el valor 1: ";
    cin >> valor5;

    lista.insertarInicio(valor1);
    lista.insertarInicio(valor2);
    lista.insertarInicio(valor3);
    lista.insertarInicio(valor4);
    lista.insertarInicio(valor5);
    cout <<"representacion grafica de la lista enlazada:"<<endl;

    cout << "Los elementos de la lista son:" << std::endl;
    ListaEnlazadaInt::NodoInt* actual = lista.inicio_;
    for (int i = 0; i < lista.tamanio(); i++) {
        std::cout << "Elemento " << i+1 << ": " << actual->valor << std::endl;
        actual = actual->siguiente;
    }

    return 0;
}


