// Lista.h
// Autores: Jeoffrey Prado, Lorenzo Solorzano, Christian Cruz
// Descripcion: Clase Lista

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <sstream>

template <class T>
class Lista {
private:
	Nodo<T>* inicio;
	int tamano;
public:
	Lista();
	~Lista();
	int getTamano();
	void setTamano(int num);
	Nodo<T>* getInicio();
	void agregar(T*);
	T* buscar(T*);
	void eliminarLista();
	string toString();
};

template <class T>
Lista<T>::Lista() {
	tamano = 0;
	inicio = nullptr;
}

template <class T>
Lista<T>::~Lista() {
	eliminarLista();
}

template<class T>
int Lista<T>::getTamano()
{
	Nodo<T>* tmp = inicio;
	while (tmp != nullptr) {
		tamano++;
		tmp = tmp->getSiguiente();
	}
	return tamano;
}

template<class T>
void Lista<T>::setTamano(int num) {
	this->tamano = num;
}

template<class T>
 Nodo<T>* Lista<T>::getInicio()
{
	return this->inicio;
}

template <class T>
void Lista<T>::agregar(T* dato) {
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo->setDatos(dato);
	nuevo->setSiguiente(nullptr);
	if (inicio == nullptr) {		
		inicio = nuevo;
		tamano++;
	}
	else {
		nuevo->setSiguiente(inicio);
		inicio = nuevo;
		tamano++;
	}
}

template <class T>
T* Lista<T>::buscar(T* dato) {
	Nodo<T>* auxilio = inicio;
	while (!auxilio) {
		if (dato == auxilio) {
			auxilio->setSiguiente(auxilio->getSiguiente());
		}
	}
}

template <class T>
void Lista<T>::eliminarLista() {
	Nodo<T>* auxilio;
	while (!inicio) {
		auxilio = inicio;
		inicio->setSiguiente(inicio->getSiguiente());
		delete auxilio;
	}
	tamano = 0;
}

template<class T>
string Lista<T>::toString()
{
	stringstream ss;
	Nodo<T>* walk = inicio;
	while (walk) 
	{
		ss << walk->getDatos()->toString() << endl;
		walk = walk->getSiguiente();
	}
	return ss.str();
}

template<class T>
ostream& operator << (ostream& salida, Lista<T>& l) {
	salida << l.toString();
	return salida;
}
#endif LISTA_H

