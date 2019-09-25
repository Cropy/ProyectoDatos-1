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
	while(!datos->isEmpty())
		ss << this->datos->pop();
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