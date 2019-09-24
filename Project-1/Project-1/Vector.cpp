#include "Vector.h"

Vector::Vector() {
	cant = 3;
	for (int i = 0; i < SIZE; i++) {
		vect[i] = NULL;
	}
}


Vector::~Vector() {	}


void Vector::insertar(int numero) {
	vect[cant--] = numero;

}


int Vector::getNumero(int i) {
	return vect[i];
}



string Vector::toString() {
	stringstream s;
	for (int i = 0; i < SIZE; i++) {
		if (vect[i] != 0) {
			s << vect[i] << " ";
		}
	}
	return s.str();
}



int Vector::getCantidad()
{
	return cant;
}


ostream& operator<<(ostream& salida, Vector& d) {
	salida << d.toString();
	return salida;
}
