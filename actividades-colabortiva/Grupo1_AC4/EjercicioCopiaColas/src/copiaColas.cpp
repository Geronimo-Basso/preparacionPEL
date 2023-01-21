#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class colaGenerica
{
protected:
class nodoCola
{
public:
nodoCola* siguiente;
T elemento;
nodoCola (T x)
{
elemento = x;
siguiente = NULL;
}
};
nodoCola* frente;
nodoCola* final;
public:
colaGenerica()
{
frente = final = NULL;
}
void insertar (T elemento);
T quitar();
void borrarCola();
T frenteCola() const;
bool colaVacia() const;
~colaGenerica()
{
borrarCola();
}
T verContenido();
T maximoElementos();
T copiarCola(colaGenerica<int> listaElementos,colaGenerica<int> copia);
};

template <class T>
void colaGenerica<T>::insertar(T elemento)
{
nodoCola* nuevo;
nuevo = new nodoCola(elemento);
if (colaVacia())
{
frente = nuevo;
}
else
{
final -> siguiente = nuevo;
}
final = nuevo;
}

template <class T>
T colaGenerica<T>::quitar()
{
if(colaVacia())
throw "Cola vacía, no se puede extraer.";
T aux = frente -> elemento;
nodoCola* a = frente;
frente = frente -> siguiente;
delete a;
return aux;
}

template <class T>
T colaGenerica<T>::frenteCola() const
{
if (colaVacia())
throw "Cola vacía";
return frente -> elemento;
}

template <class T>
void colaGenerica<T>::borrarCola()
{
while(frente != NULL)
{
nodoCola* a;
a = frente;
frente = frente -> siguiente;
delete a;
}
final = NULL;
}

template<class T>
bool colaGenerica<T>::colaVacia() const
{
return frente == NULL;
}
template<class T>
T colaGenerica<T>::verContenido(){
	int num = 1;
	cout << num << "º elementos: " << frente ->elemento << endl;
	while(frente->siguiente!=NULL){
		num++;
		frente = frente -> siguiente;
		cout << num << "º elementos: " << frente->elemento<<endl;
	}

}
template<class T>
T colaGenerica<T>::copiarCola(colaGenerica<int> listaElementos,colaGenerica<int> copia){
	int num  = 0;
	int maxEle = listaElementos.maximoElementos();
	int arr[maxEle];
	arr[0] = frente->elemento;
	while(frente->siguiente!=NULL){
		num++;
        frente = frente->siguiente;
        arr[num] = frente->elemento;
        if(num == (maxEle-1)){
          for (int i = 0;  i < maxEle; ++i) {
  			copia.insertar(arr[((maxEle-1)-i)]);

		}
        cout<<"COPIA REAIZADA: " << endl;
  		copia.verContenido();

        }
	}


}
template<class T>
T colaGenerica<T>::maximoElementos(){
	if (colaVacia())
	throw "Cola vacía";
	int num = 1;

	while(frente->siguiente!=NULL){
		num++;
		frente=frente->siguiente;

	}
	return num;

}
int main() {
colaGenerica<int> listaElementos;
colaGenerica<int> copia;

listaElementos.insertar(3);
listaElementos.insertar(5);
listaElementos.insertar(7);
listaElementos.insertar(9);



listaElementos.copiarCola(listaElementos, copia);

	return 0;
}
