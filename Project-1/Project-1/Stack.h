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
	int* arr;
	int top;
	int capacity;

public:
	stack(int size = SIZE);		// constructor

	void push(int);
	int pop();
	int peek();

	int size();
	bool isEmpty();
	bool isFull();
};

// Constructor to initialize stack
stack::stack(int size)
{
	arr = new int[size];
	capacity = size;
	top = -1;
}

// Utility function to add an element x in the stack
void stack::push(int x)
{
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << x << endl;
	arr[++top] = x;
}

// Utility function to pop top element from the stack
int stack::pop()
{
	// check for stack underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << peek() << endl;

	// decrease stack size by 1 and (optionally) return the popped element
	return arr[top--];
}

// Utility function to return top element in a stack
int stack::peek()
{
	if (!isEmpty())
		return arr[top];
	else
		exit(EXIT_FAILURE);
}

// Utility function to return the size of the stack
int stack::size()
{
	return top + 1;
}

// Utility function to check if the stack is empty or not
bool stack::isEmpty()
{
	return top == -1;	// or return size() == 0;
}

// Utility function to check if the stack is full or not
bool stack::isFull()
{
	return top == capacity - 1;	// or return size() == capacity;
}



