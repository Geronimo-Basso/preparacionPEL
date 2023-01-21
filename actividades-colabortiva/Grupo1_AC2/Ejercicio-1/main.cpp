#include <iostream>
#include <string>
using namespace std;

template<typename T> class Pila {
private:
    int listaLibros[10];
    int elementos;
public:
    Pila() :
            elementos(0) {
    }
    void insertLibro(int i) {
        if (elementos < 10) {
            listaLibros[elementos] = i;
            elementos++;
        } else {
            cout << "Error: Pila llena";
        }
    }
    ;

    int definirElementos() {
        int numero;
        try {
            cout << "introduce un numero" << endl;
            cin >> numero;
            if (cin.fail()) {
                throw 1;
            }
            if (numero == 0) {
                cout << "el numero 0 no sera almacenado\n" << endl;
            }
        } catch (int err) {
            cout << "numero no validado\n";
        }
        return numero;

    }

    void showNumeros() {
        if (elementos == 0) {
            cout << "NO EXISTEN ELEMENTOS PARA MOSTRAR\n" << endl;

        }
        for (int i = 0; i < elementos; i++) {
            cout << "Posición elemento: " << i + 1 << "\n";
            cout << "Nombre del libro: " << listaLibros[i] << "\n";

        }
    }

    void eliminar() {
        cin.ignore();
        int pos;
        cout << "Introduce la posición del elemento que deseas eliminar\n"
             << endl;
        cin >> pos;
        for (int j = pos; j < elementos; j++) {
            listaLibros[j - 1] = listaLibros[j];

        }
        elementos = elementos - 1;
    }
};

int main() {
    int num;
    int erigei;
    bool continuar = true;
    Pila<int> listaElementos;
    while (continuar) {
        cout << "----Introduce la opción que deseas realizar----\n"
                "1- Insertar valores en la Pila\n"
                "2- Ver valores almacenados\n"
                "3- Eliminar elementos\n"
                "4- Salir del bucle\n";
        cin.clear();
        cin.sync();
        cin >> erigei;
        switch (erigei) {
            case 1:
                num = listaElementos.definirElementos();
                if (num != 0) {
                    listaElementos.insertLibro(num);
                }
                break;
            case 2:
                listaElementos.showNumeros();
                break;

            case 3:
                listaElementos.eliminar();
                break;

            case 4:
                cout << "FIN DEL PROGRAMA" << "\n";
                continuar = false;
                break;
            default:
                cout << "es caso que as seleccionado no existe\n";
                break;
        }
    };
}
;
