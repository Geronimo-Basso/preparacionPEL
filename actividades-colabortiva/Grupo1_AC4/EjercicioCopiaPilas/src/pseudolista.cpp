#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T>
class PilaGenerica {
	class NodoPila {
	public:
		NodoPila *siguiente;
		T elemento;
		NodoPila(T x) {
			elemento = x;
			siguiente = NULL;
	}
	};
	NodoPila *cima;
public:
	PilaGenerica() {
		cima = NULL;
	}
	void insertar(T elemento);
	T quitar();
	T cipaPila();
	bool PilaVacia();
	const
	void limpiarPila();
	~PilaGenerica() {
		//limpiarPila();
	}
	T verContenido();
	T maximoElementos();
	T copiarPila(PilaGenerica<int> listaElementos,PilaGenerica<int> copia);
};
template <class T>
bool PilaGenerica<T>::PilaVacia()
{
return cima == NULL;
}

template <class T>
void PilaGenerica<T>::insertar(T elemento)
{
NodoPila* nuevo;
nuevo = new NodoPila(elemento);
nuevo -> siguiente = cima;
cima = nuevo;
}

template <class T>
T PilaGenerica<T>::quitar()
{
if(PilaVacia())
throw "Pila Vacía, no se puede extraer";
T aux = cima -> elemento;
cima = cima -> siguiente;
return aux;
}
template <class T>
T PilaGenerica<T>::cipaPila()
{
if (PilaVacia() == true)
throw "Pila Vacía";

return cima -> elemento;
}


template<class T>
T PilaGenerica<T>::verContenido()
{
if(PilaVacia())
throw "Pila Vacía";

int num = 1;
NodoPila* ver;
ver = cima;
cout << num << "º elementos: " << cima ->elemento << endl;
while(ver!=NULL){
num++;
cima = cima -> siguiente;
cout << num << "º elementos: " << cima -> elemento << endl;
}
}

template<class T>
T PilaGenerica<T>::copiarPila(PilaGenerica<int> listaElementos,PilaGenerica<int> copia)
{
	if(PilaVacia())
	throw "Pila Vacía";

	int max = listaElementos.maximoElementos();
	int num = 0;
	int arr[max];
	arr[0] = cima->elemento;
	while(cima->siguiente!= NULL){
	num++;
	cima = cima -> siguiente;
	arr[num] = cima -> elemento;
	if(num == (max - 1)){
		for (int i = 0;  i < max; ++i) {
			copia.insertar(arr[((max-1)-i)]);
		}
        cout<<"COPIA REAIZADA: " << endl;
		copia.verContenido();
	}
}
}
template<class T>
T PilaGenerica<T>::maximoElementos(){
	int num = 1;
	while(cima->siguiente != NULL){
		num++;
		cima = cima->siguiente;
	}
	return num;
}

int main() {
PilaGenerica<int> listaElementos;
PilaGenerica<int> copia;
listaElementos.insertar(1);
listaElementos.insertar(2);
listaElementos.insertar(3);
listaElementos.insertar(4);


//int num = listaElementos.maximoElementos();
//cout << "Numero de elementos: " <<  num << endl;
//listaElementos.verContenido();
listaElementos.copiarPila(listaElementos, copia);


	return 0;
}
