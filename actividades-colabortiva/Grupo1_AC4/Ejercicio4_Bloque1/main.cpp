#include <iostream>
using namespace std;

class NodoLista{
public:
    int elemento;
    NodoLista* siguiente;
    NodoLista* primero;

    NodoLista(int x){
        elemento = x;
        siguiente = 0;
        primero = 0;
    };

    void push(int num){

        NodoLista* nuevo = new NodoLista(num); //Creamos un nuevo nodo con el valor que queremos insertar

        if (primero == NULL){ // Si la lista está vacía, el nuevo nodo será el primero
            primero = nuevo;
        }
        else {

            NodoLista* aux = primero; //Creamos un puntero auxiliar que recorrerá la lista

            int cont = 0;

            while (aux != NULL) { //Se recorre la lista hasta llegar al último nodo y saber cuantos hay
                aux = aux->siguiente;
                cont++;
            }

            int mid = cont / 2; //Se calcula la mitad de la lista
            aux = primero;
            for (int i = 0; i < mid; i++) { //Se recorre la lista hasta llegar a la mitad e insertar el nuevo nodo
                aux = aux->siguiente;
            }

            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }

    void impresion(){
        NodoLista* aux = primero; //Creamos un puntero auxiliar que recorrerá la lista

        while (aux != NULL) {
            if (aux->elemento % 2 != 0) { //Se calcula si el elemento es impar
                cout << aux->elemento << endl;
            }
            aux = aux->siguiente; //Se avanza al siguiente nodo
        }
    }
};

int main() {

    NodoLista* v = new NodoLista(0);

    int num=0;

    while (num!=-1)
    {
        cout << "Introduce el número que quieras\n";
        cout << "Introduce el número -1 para finalizar el programa\n";
        cin >> num;
        if (num!=-1)
        {
            v->push(num);
        }
        else{
            cout << "\n";
        }
    }

    v->impresion();

    return 0;
}