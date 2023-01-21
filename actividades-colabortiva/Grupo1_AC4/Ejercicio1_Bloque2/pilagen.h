using namespace std;
template < class T > class PilaGenerica
{
	class NodoPila
	{
		public: NodoPila * siguiente;
		T elemento;
		NodoPila(T x)
		{
			elemento = x;
			siguiente = NULL;
		}
	};
	NodoPila * cima;
	public: 
		PilaGenerica()
		{
			cima = NULL;
		}
	void meter(T elemento);
	T sacar();
	const
		T cimaPila();
	bool pilaVacia();
	void limpiarPila();
	~PilaGenerica()
	{
		limpiarPila();
	}
};
template < class T>
	bool PilaGenerica<T>::pilaVacia()
	{
		return cima == NULL;
	}

template < class T > void PilaGenerica<T>::meter(T elemento)
{
	NodoPila * nuevo;
	nuevo = new NodoPila(elemento);
	nuevo->siguiente = cima;
	cima = nuevo;
}
template < class T > T PilaGenerica<T>::sacar()
{
	if (pilaVacia())
	{
		cout << "Pila vacía, no se puede extraer elementos!" << endl;
	}

	T aux = cima->elemento;
	cima = cima->siguiente;
	return aux;
}	
template < class T>
	const T PilaGenerica<T>::cimaPila()
	{
		if (pilaVacia()) {cout << "Pila Vacía" << endl;}
		return cima->elemento;
	}	//Método para el vaciado de la pila 
template < class T > void PilaGenerica<T>::limpiarPila()
{
	NodoPila * n;
	while (!pilaVacia())
	{
		n = cima;
		cima = cima->siguiente;
		delete n;
	}
}