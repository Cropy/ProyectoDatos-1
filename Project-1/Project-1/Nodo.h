// Nodo.h
// Autores: Jeoffrey Prado, Christian Cruz, Lorenzo Solorzano
// Descripcion: Clase Nodo, utilizado en la lista enlazada

#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class Nodo {
private:
	T* datos;
	Nodo<T>* siguiente;
public:
	Nodo();
	Nodo* reverse(Nodo* list);
	T* getDatos();
	Nodo* getSiguiente();
	void setDatos(T* dato);
	string print();
	void setSiguiente(Nodo* siguiente);
	unsigned int pop();
};




template <class T>
Nodo<T>::Nodo() {
	datos = nullptr;
	siguiente = nullptr;
}

template<class T>
Nodo<T>* Nodo<T>::reverse(Nodo* list)
{
	
		Nodo* ptr = list;

		if (list->getSiguiente() != nullptr)
		{
			ptr = reverse(list->getSiguiente());

			(list->getSiguiente())->setSiguiente(list);
			list->setSiguiente(nullptr);
		}

		return ptr;
	
}

template <class T>
T* Nodo<T>::getDatos() {
	return datos;
}

template <class T>
Nodo<T>* Nodo<T>::getSiguiente() {
	return siguiente;
}

template <class T>
void Nodo<T>::setDatos(T* dato) {
	this->datos = dato;
}

template<class T>
inline string Nodo<T>::print()
{
	stringstream ss;
	unsigned int x=0;

	

	T* aux = new T();
	T* stack = this->datos;
	aux = stack->invertirPila(stack);
	
	while (!aux->isEmpty()) {
		x =aux->pop();
		ss << x;
	}
	return ss.str();

}

template <class T>
void Nodo<T>::setSiguiente(Nodo* siguiente) {
	this->siguiente = siguiente;
}

template<class T>
inline unsigned int Nodo<T>::pop()
{
	return this->datos->pop();
}
#endif NODO_H