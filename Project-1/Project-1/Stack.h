// Stack.h
// Autores: Jeoffrey Prado, Lorenzo Solorzano, Christian Cruz
// Descripcion: Clase Stack, permite trabajar con datos string, int y long


#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of the stack
#define SIZE 4

// Class for stack
class stack
{
	unsigned int* arr;
	int top;
	int capacity;

public:
	stack(int size = SIZE);		// constructor

	void push(unsigned int);
	unsigned pop();
	unsigned peek();

	int size();
	bool isEmpty();
	bool isFull();
};




