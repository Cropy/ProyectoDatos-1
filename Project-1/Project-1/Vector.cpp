#include "Vector.h"

Vector::Vector(){
	cantidad = 0;
	
	for (int i = 0; i < SIZE; i++)
		vector[i] = NULL;
}

Vector::~Vector() {

}

int Vector::getCantidad() { return cantidad; }

void Vector::setCantidad(int cant) {
	cantidad = cant;
}

void Vector::insertar(unsigned int num) {
	vector[cantidad++] = num;
}

unsigned int Vector::getNumero(int i) {
	return vector[i];
}

string Vector::toString() {
	stringstream ss;
	for (int i = 0; i < SIZE; i++) {
		ss << vector[i] << endl;
	}
	return ss.str();
}

ostream& operator<<(ostream& output, Vector& vec) {
	output << vec.toString() << endl;
	return output;
}
