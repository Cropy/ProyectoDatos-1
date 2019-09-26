// Integer.h
// Autores: Jeoffrey Prado, Lorenzo Solorzano, Christian Cruz
// Descripcion: Clase Integer, permite trabajar con datos string, int y long

#ifndef INTEGER_H
#define INTEGER_H 

#define ZERO 0
#define ONE 1

#include "Utiles.h"
#include "Lista.h"
#include "Stack.h"

#include <iostream>
#include <sstream>
using namespace std;

class Integer {
private:
	Lista<stack>* ListaStack;
	char signo;
public:
	// Constructores y Destructor
	Integer();
	Integer(const Integer&);
	Integer(const long long&);
	Integer(const string&);
	~Integer();

	// Sets y Gets
	char get_signo();
	void set_signo(char sig);
	Lista<stack>* getLista();
	void setLista(Lista<stack>* lista);

	//Metodos
	void agregar(string numero);
	Integer* suma(Lista<stack>* lista1, Lista<stack>* lista2);
	Integer* resta(Lista<stack>* lista1, Lista<stack>* lista2);
	string StacktoString(stack* s);
	string NodotoString(Nodo<stack>* s);
	string sumaStack(Nodo<stack>* s, Nodo<stack>* s1);
	string restaStack(Nodo<stack>* s, Nodo<stack>* s1);
	//string multiStack(Nodo<stack>* s, Nodo<stack>* s1);

	//
	//Integer* multiplicacion(Lista<stack>* lista1, Lista<stack>* lista2);

	// Sobrecarga operadores asignacion
	Integer& operator=(Integer&);
	Integer& operator+=(Integer&);
	Integer& operator-=(Integer&);
	//Integer& operator*=(Integer&);
	//Integer& operator/=(Integer&);

	// Sobrecarga operadores aritmeticos
	Integer& operator+(Integer&);
	Integer& operator-(Integer&);
	//Integer& operator*(Integer&);
	//Integer& operator/(Integer&);

	//// Sobrecarga operadores comparacion
	//bool operator<(Integer&);
	//bool operator>(Integer&);
	//bool operator<=(Integer&);
	//bool operator>=(Integer&);
	//bool operator==(Integer&);
	//bool operator!=(Integer&);

	// Sobrecarga operadores E/S
	friend ostream& operator<<(ostream&, Integer&);

	// Extras
	string toString();
	Integer parse(string hilera);
};
#endif // !INTEGER_H
