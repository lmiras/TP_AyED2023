#ifndef LISTAS_HPP_INCLUDED
#define LISTAS_HPP_INCLUDED

template <typename T> struct Nodo {
	T dato;
	Nodo<T>* sig; 
};
template <typename T> void push(Nodo<T>* &pila, T valor, Nodo<T>* &ultim)
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->sig = pila;
	pila = nuevo;
	if(nuevo->sig==nullptr){
		ultim=nuevo;
	}
}

template <typename T> T pop(Nodo<T>* &pila, Nodo<T>* &ultim)
{
	if (pila == nullptr) {
		std::cout << "Error: pop en pila vacia" << std::endl;
		exit(EXIT_FAILURE);
		
	}
	T valor = pila->dato;
	Nodo<T>* aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}

template <typename T> void agregar(Nodo<T>*& cola, T valor,Nodo<T>* &ultim)
{
	
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->sig = nullptr;
	if (cola == nullptr) {
		cola = nuevo;
    

	}
        else {
		Nodo<T>* aux = ultim;
		aux->sig = nuevo;
        }
        ultim=nuevo;
	}

//la idea es evitar el while navegando por toda la lista, y que haya un puntero al ultimo directamente.

#endif // LISTAS_HPP_INCLUDED