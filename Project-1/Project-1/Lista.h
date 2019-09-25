// Lista.h
// Autores: Jeoffrey Prado, Lorenzo Solorzano, Christian Cruz
// Descripcion: Lista Integer, permite trabajar con datos string, int y long

#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <sstream>
#include "Nodo.h"
using namespace std;

template <class T>
class Lista {
private:
	Nodo<T>* inicio;
	int tamano;
public:
	Lista();
	int getTamano();
	Nodo<T>* getInicio();
	void agregar(T*);
	//void eliminar(T*);
	T* buscar(T*);
	void eliminarLista();
	string Print();
	int cantNodos();
	
	~Lista();
};


template<class T>
inline int Lista<T>::cantNodos()
{
	int tam = 0;
	Nodo<T>* tmp = inicio;
	if (tmp == nullptr)
		return tam;
	
	while (tmp != nullptr) {
		tam++;
	    tmp= tmp->getSiguiente();
	}
	return tam;
}
template <class T>
Lista<T>::Lista() {
	tamano = 0;
	inicio = nullptr;
}

template<class T>
inline int Lista<T>::getTamano()
{
	return tamano;
}

template<class T>
inline Nodo<T>* Lista<T>::getInicio()
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

//template <class T>
//void Lista<T>::eliminar(T* dato) {
//	if (inicio != nullptr) {
//		throw 1;
//	}
//	Nodo<T> auxiliar;
//	auxiliar = inicio;
//	if (*inicio->getDatos() == *dato) {
//		inicio = inicio->getSiguiente();
//		delete auxiliar;
//	}
//	else {
//		Nodo<T>* auxiliar2;
//		auxiliar2 = auxiliar->getSiguiente();
//		while (auxiliar2 != nullptr) {
//			auxiliar->setSiguiente(auxiliar2->getSiguiente());
//			delete auxiliar2;
//			break;
//		}
//		auxiliar = auxiliar2;
//		auxiliar2->setSiguiente(auxiliar2->getSiguiente());
//	}
//	delete auxiliar;
//}

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
inline string Lista<T>::Print()
{
	stringstream ss;
	Nodo<T>* walk = inicio;
	while (walk) 
	{
		ss << walk->print();
		walk = walk->getSiguiente();
	}
	return ss.str();
}



template <class T>
Lista<T>::~Lista() {
	eliminarLista();
}

template<class T>
inline ostream& operator << (ostream& salida, Lista<T>& l) {
	salida << l.toString();
	return salida;
}
#endif LISTA_H

