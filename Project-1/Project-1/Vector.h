// Vector.h
// Autores: Jeoffrey Prado, Lorenzo Solorzano, Christian Cruz
// Descripcion: Clase Vector

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <sstream>
using namespace std;

//CAPACIDAD PREDETERMINADA DEL VECTOR
#define SIZE 3

class Vector {
private:
	
	unsigned int vector[SIZE];
	int cantidad;
public:
	Vector();
	~Vector();
	int getCantidad();
	void setCantidad(int cant);
	void insertar(unsigned int num);
	unsigned int getNumero(int i);
	string toString();
	friend ostream& operator<<(ostream& output, Vector& vec);
};
#endif VECTOR_H



