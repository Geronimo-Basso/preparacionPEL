//
// Created by victo on 09/01/2023.
//
#include "ListaEnlazada.h"
#include <iostream>

using namespace std;

int main() {
    ListaEnlazadaInt lista;
    lista.insertarInicio(0);
    lista.insertarInicio(0);
    lista.insertarInicio(0);
    lista.insertarInicio(0);
    lista.insertarInicio(0);
    cout << "Ingrese el valor del elemento a insertar al inicio: ";
    int valor1;
    cin >> valor1;
    lista.insertarInicio(valor1);

    cout << "Ingrese el valor del elemento a insertar entre dos nodos: ";
    int valor3;
    cin >> valor3;
    cout << "Ingrese el índice del nodo anterior al que se insertará el nuevo elemento: ";
    int indice;
    cin >> indice;
    if (indice < 0 || indice >= lista.tamanio()) {
        cout << "Índice fuera de rango. No se puede insertar el elemento." << endl;
    } else {
        ListaEnlazadaInt::NodoInt* actual = lista.inicio_;
        for (int i = 0; i < indice; i++) {
            actual = actual->siguiente;
        }
        cout << "Ingrese el valor del elemento a insertar al final: ";
        int valor2;
        cin >> valor2;
        lista.insertarFinal(valor2);

        ListaEnlazadaInt::NodoInt* nuevo = new ListaEnlazadaInt::NodoInt;
        nuevo->valor = valor3;
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
    std::cout << "Los elementos de la lista son:" << std::endl;
    ListaEnlazadaInt::NodoInt* actual = lista.inicio_;
    for (int i = 0; i < lista.tamanio(); i++) {
        std::cout << "Elemento " << i+1 << ": " << actual->valor << std::endl;
        actual = actual->siguiente;
    }

    return 0;
}
