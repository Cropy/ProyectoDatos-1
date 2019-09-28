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
	T* getDatos();
	Nodo<T>* getSiguiente();
	void setDatos(T* dato);
	void setSiguiente(Nodo<T>* sig);
	string toString();
};

template<class T>
string Nodo<T>::toString() {
	
	return datos->toString();
}


template<class T>
Nodo<T>::Nodo() {
	datos = new T();
	siguiente = nullptr;
}

template<class T>
T* Nodo<T>::getDatos() {
	return datos;
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente() {
	return siguiente;
}

template<class T>
void Nodo<T>::setDatos(T* dato) {
	this->datos = dato;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* sig) {
	this->siguiente = sig;
}
#endif NODO_H