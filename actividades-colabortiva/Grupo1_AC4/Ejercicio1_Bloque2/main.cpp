#include <iostream>
#include "pilagen.h"

using namespace std;

bool checkPalindromo(PilaGenerica<char> c, string palabra) //Función para comprobar si la palabra es palíndromo
{
    bool b = true;
    int i = 0;
    while (!c.pilaVacia())
    {
        cout << "STRING: " << palabra[i] << " -- CIMAPILA: " << c.cimaPila() << endl; //Comprobación de la pila
        if (palabra[i] != c.cimaPila()) //Si la letra de la palabra es distinta a la de la pila, no es palíndromo
        {
            b = false;
        }
        c.sacar();
        i++;
    }

    return b;
}

int main(int, char**) {
    PilaGenerica<char> palabra;
    PilaGenerica<char> pila2;
    string sPalabra;
    cout << "Introduce una palabra: " << endl;
    cin >> sPalabra;
    
    for (long long unsigned int i = 0; i < sPalabra.length(); ++i) //Meter la palabra en la pila
    {
        palabra.meter(sPalabra[i]);
    }

    if(checkPalindromo(palabra, sPalabra)) { //Comprobar si es palíndromo
        cout << sPalabra << " es un palindromo" << endl;
    } else { //Si no lo es, mostrarlo
        cout << sPalabra << " no es un palindromo" << endl;
    }
    
}
