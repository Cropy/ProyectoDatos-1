#pragma once
#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <sstream>

using namespace std;

template <class T> class Nodo;

template <class T>
class Nodo {
private:
	T* datos;
	Nodo<T>* siguiente;
public:
	Nodo();
	T* getDatos();
	Nodo* getSiguiente();
	void setDatos(T* dato);
	void print();
	void setSiguiente(Nodo* siguiente);
};

template <class T>
Nodo<T>::Nodo() {
	datos = nullptr;
	siguiente = nullptr;
}

template <class T>
T* Nodo<T>::getDatos() {
	return datos->peek();
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
inline void Nodo<T>::print()
{
	cout << this->datos->peek();

}

template <class T>
void Nodo<T>::setSiguiente(Nodo* siguiente) {
	this->siguiente = siguiente;
}


#endif NODO_H
