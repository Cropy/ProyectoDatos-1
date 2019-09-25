#pragma once
#include"Stack.h"
#include<sstream>
#include<string>
#include<iostream>
#include"Lista.h"
#include "Integer.h"


using namespace std;


int main() {

	stack* s = new stack();
	stack* s1 = new stack();
	stack* s2 = new stack();
	



	unsigned int n1 = 111;
	unsigned int n2 = 222;
	unsigned int n3 = 33;
	unsigned int n4 = 4;



	Integer *i1 = new Integer();
	Integer* i2 = new Integer();


	i1->agregar("22223333");
	i2->agregar("3");


	

     Integer* g= i1->multiplicacion(i1->getLista(), i2->getLista());

	cout << *g << endl;

	









	system("pause");
	return 0;
}


//template<typename T>
//Vector<T>* Vector<T>::multiplicar(Vector<T>* v) {
//	Vector<T>* result = new Vector<T>();
//	T aux4[5] = { 0, 0, 0, 0, 0 };
//	T aux3[5] = { 0, 0, 0, 0, 0 };
//	T aux2[5] = { 0, 0, 0, 0, 0 };
//	T aux1[5] = { 0, 0, 0, 0, 0 };
//	Pila<T>* p = new Lista<T>();
//	int residuo = 0;
//	for (int i = 3; i >= 0; i--) {
//		for (int j = 4; j >= 0; j--) {
//			if (j > 0)p->push(this->getElemento(i) * v->getElemento(j - 1));
//			while (!p->isEmpty()) {
//				residuo = residuo + p->pop();
//			}
//			switch (i) {
//			case 3:
//				aux4[j] = residuo % 10;
//				break;
//			case 2:
//				aux3[j] = residuo % 10;
//				break;
//			case 1:
//				aux2[j] = residuo % 10;
//				break;
//			case 0:
//				aux1[j] = residuo % 10;
//				break;
//			}
//			p->push(residuo / 10);
//			residuo = 0;
//		}
//	}
//	while (!p->isEmpty()) {
//		residuo = residuo + p->pop();
//	}
//	if (residuo != 0)exedente = residuo;
//	residuo = 0;
//	for (int i = 7; i >= 0; i--) {
//		switch (i) {
//		case 7:
//			p->push(aux4[4]);
//			break;
//		case 6:
//			p->push(aux4[3]);
//			p->push(aux3[4]);
//			break;
//		case 5:
//			p->push(aux4[2]);
//			p->push(aux3[3]);
//			p->push(aux2[4]);
//			break;
//		case 4:
//			p->push(aux4[1]);
//			p->push(aux3[2]);
//			p->push(aux2[3]);
//			p->push(aux1[4]);
//			break;
//		case 3:
//			p->push(aux4[0]);
//			p->push(aux3[1]);
//			p->push(aux2[2]);
//			p->push(aux1[3]);
//			break;
//		case 2:
//			p->push(aux3[0]);
//			p->push(aux2[1]);
//			p->push(aux1[2]);
//			break;
//		case 1:
//			p->push(aux2[0]);
//			p->push(aux1[1]);
//			break;
//		case 0:
//			p->push(aux1[0]);
//			break;
//		}
//		while (!p->isEmpty()) {
//			residuo = residuo + p->pop();
//		}
//		if (i > 3) {
//			result->setElemento(i - 4, residuo % 10);
//			p->push(residuo / 10);
//			residuo = 0;
//		}
//		else {
//			if (i == 3) {
//				result->setExedente(residuo % 10);
//				p->push(residuo / 10);
//			}
//
//			if (i == 2) {
//				result->setExedente(result->getExedente() + (residuo % 10) * 10);
//				p->push(residuo / 10);
//			}
//			if (i == 1) {
//				result->setExedente(result->getExedente() + (residuo % 10) * 100);
//				p->push(residuo / 10);
//			}
//			if (i == 0) {
//				result->setExedente(result->getExedente() + (residuo % 10) * 1000);
//				p->push(residuo / 10);
//			}
//			residuo = 0;
//		}
//	}
//	result->setExedente(result->getExedente() + this->getExedente() + v->getExedente());
//	return result;
//}






//Integer* Integer::multiplicacion(Integer* l) {
//	bool bandera = true;
//	Integer* auxLocal = new Integer(l);
//	Integer* auxExterno = new Integer(this);
//	Integer* resultado = new Integer();
//	Lista<Integer*>* estudioCapacidad = new Lista<Integer*>();
//	Integer* estudio = new Integer();
//	Lista<Integer*>* aux = new Lista<Integer*>();
//	Pila<Vector<int>> p = new Lista<Vector<int>*>();
//	Vector<int>* residuo = new Vector<int>();
//	Vector<int>* local;
//	while (!auxLocal->getLista()->isEmpty()) {
//		local = auxLocal->getLista()->sacarFinal();
//		while (!auxExterno->getLista()->isEmpty()) {
//			p->push(local->multiplicar(auxExterno->getLista()->sacarFinal()));
//			while (!p->isEmpty()) {
//				residuo = residuo->sumar(p->pop());
//			}
//			if (bandera) {
//				aux->enqueue(new Integer(new Vector<int>(0)));
//				bandera = false;
//				estudio = aux->sacarFinal();
//				estudio->insertarDigito(residuo->getT());
//			}
//			else {
//				estudio = aux->sacarFinal();
//				estudio->insertarVector(new Vector<int>(0));
//				estudio->insertarDigito(residuo->getT());
//			}
//			aux->enqueue(estudio);
//			residuo = new Vector<int>(residuo->getExedente());
//			p->push(new Vector<int>(residuo->getT()));
//			while (residuo->getExedente() > 0) {//no sabemos el tamaño del residuo asi que metemos todo el residuo en la pila
//				residuo = new Vector<int>(residuo->getExedente());
//				p->push(new Vector<int>(residuo));
//			}
//			residuo->reset();
//		}
//		auxExterno = new Integer(this);
//		bandera = true;
//	}
//	while (!p->isEmpty()) {
//		residuo = residuo->sumar(p->pop());
//	}
//	estudio = aux->sacarFinal();
//	estudio->insertarDigito(residuo->getT());
//	aux->enqueue(estudio);
//	while (residuo->getExedente() > 0) {
//		residuo = new Vector<int>(residuo->getExedente());
//		estudio = aux->sacarFinal();
//		estudio->insertarDigito(residuo->getT());
//		aux->enqueue(estudio);
//	}
//	residuo->reset();
//	int listaPops = 1;
//	while (!aux->isEmpty()) {
//		for (int i = 1; i <= listaPops; i++) {//mete en la pila los valores a sumar
//			estudio = aux->pop();
//			p->push(estudio->getLista()->sacarFinal());
//			estudioCapacidad->push(estudio);
//		}
//		for (int i = 1; i <= listaPops; i++) {
//			estudio = estudioCapacidad->pop();
//			if (!estudio->getLista()->isEmpty())aux->push(estudio);
//		}
//		if (listaPops < aux->cont())listaPops++;
//		if (listaPops > aux->cont())listaPops--;
//
//		////////////Mete en la pila los valores a sumar//////
//
//
//		while (!p->isEmpty()) {//suma valores en la pila
//			residuo = residuo->sumar(p->pop());
//		}
//		resultado->insertarVector(new Vector<int>());
//		resultado->insertarDigito(residuo->getT());
//		residuo = new Vector<int>(residuo->getExedente());
//		resultado->insertarDigito(residuo->getT());
//		while (residuo->getExedente() > 0) {
//			residuo = new Vector<int>(residuo->getExedente());
//			resultado->insertarDigito(residuo->getT());
//		}
//	}
//
//	return resultado;
//}