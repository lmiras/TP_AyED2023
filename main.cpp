#include <iostream>
#include "lista.hpp"
using namespace std;

struct Pizza {
	string gusto;
	int cant;
};

// ============ ENTEROS
int criterio_int(int a, int b)
{
	return a - b;
}

// ============ STRING
int criterio_str(string a, string b)
{
	return (a < b) ? -1 : (a > b);
}

// ============ Pizza buscando por GUSTO
int criterio_pizza(Pizza a, Pizza b)
{
	if (a.gusto == b.gusto)
		return 0;
	else
		return a.gusto > b.gusto ? 1 : -1;
}

ostream& operator << (ostream &os, Pizza& p)
{
	os << p.gusto << " : " << p.cant;
	return os;
}


template <typename T> void mostrar(Nodo<T>* lista)
{
	while (lista != nullptr) {
		cout << lista->dato << endl;
		lista = lista->sig;
	}
}

template <typename T> T* buscar_lineal(T clave, Nodo<T>* lista,Nodo<T>* opcion, int (*criterio)(T, T))
{
	//opcion es para elegir si sultimo(para cola) o ultimo(pila)
	while (lista != opcion->sig) {
		if (criterio(lista->dato, clave) == 0)
			return &lista->dato;
		lista = lista->sig;
	}
	return nullptr;
}

int main()
{
	//pultimo es el puntero de la pila que apunta al final.
	//sultimo es el puntero de la cola que apunta al final.
	//tultimo es el puntero de la lista que apunta al final.
	Nodo<int> *pila = nullptr;
	Nodo<int> *pultimo = nullptr;
	//pop(pila);//provoco error para ver como funciona
	push(pila, 1,pultimo);
	push(pila, 2,pultimo);
	push(pila, 3,pultimo);
	cout << "Pila (1 2 3)" << endl;
	mostrar(pila);
	cout << endl << "Eliminamos" << endl;
	while (pila != nullptr)
		cout << pop(pila,pultimo) << endl;
	cout << endl << "Confirmamos pila vacía:" << endl;
	mostrar(pila);
	cout << "fin mostrar pila" << endl;
	cout << "-----------------" << endl;

	Nodo<string> *cola = nullptr;
	Nodo<string> *sultimo = nullptr;
	agregar(cola, "uno"s,sultimo);
	agregar(cola, "dos"s,sultimo);
	agregar(cola, "tres"s,sultimo);
	cout << endl << "Cola (uno dos tres)" << endl;
	mostrar(cola);
	cout << endl << "Eliminamos" << endl;
	while (cola != nullptr)
		cout << pop(cola,sultimo) << endl;
	cout << endl << "Confirmamos cola vacía:" << endl;
	mostrar(cola);
	cout << "fin mostrar cola" << endl;
	cout << "-----------------" << endl;

	agregar(cola, "Juan"s,sultimo);
	agregar(cola, "Pedro"s,sultimo);
	agregar(cola, "María"s,sultimo);
	cout << endl << "Datos para la búsqueda" << endl;
	mostrar(cola);
	string nombre;
	cout << endl << "Ingrese el nombre a buscar: ";
	while (cin >> nombre) {
		if (buscar_lineal(nombre, cola,sultimo, criterio_str) != nullptr)
			cout << nombre << " SI está en la lista" << endl;
		else
			cout << nombre << " NO está en la lista" << endl;
		cout << "Ingrese el nombre a buscar: ";
	}

	cin.clear(); // como force EOF debo limpiar los bits de error
	cout << endl << "-----------------" << endl;
	Nodo<Pizza> *lista = nullptr;
	Nodo<Pizza> *tultimo = nullptr;
	agregar(lista,{"Muza", 4},tultimo);
	agregar(lista, {"Fugazzeta", 1},tultimo);
	agregar(lista, {"Especial", 3},tultimo);
	agregar(lista, {"Pizzaiola", 2},tultimo);
	cout << endl << "Pedidos en la lista:" << endl;
	mostrar(lista);
	Pizza pizzaClave;
	Pizza *ptrPizza;
	cout << endl << "Ingrese el gusto a buscar: ";
	while (cin >> pizzaClave.gusto) {
		ptrPizza = buscar_lineal(pizzaClave, lista,tultimo, criterio_pizza);
		if (ptrPizza != nullptr)
			cout << pizzaClave.gusto << " SI está en la lista ==> " << *ptrPizza << endl;
		else
			cout << pizzaClave.gusto << " NO está en la lista" << endl;
		cout << "Ingrese el nombre a buscar: ";
	}
	return EXIT_SUCCESS;
};
