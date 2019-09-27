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
#include <math.h>
using namespace std;

class Integer {
private:
	Lista<stack>* ListaStack;
	char signo;
	int tam;
public:
	// Constructores y Destructor
	Integer();
	Integer(const Integer&);
	Integer(const long long&);
	Integer(const string&);
	~Integer();

	// Sets y Gets
	char get_signo();
	int getam();
	void setTam(int t);
	void set_signo(char sig);
	Lista<stack>* getLista();
	void setLista(Lista<stack>* lista);


	//Metodos
	void agregar(string numero);
	Integer* suma(Integer*, Integer*);
	Integer* resta(Lista<stack>* lista1, Lista<stack>* lista2);
	string SumaStack(stack* s);
	string SumarNodo(Nodo<stack>* s);
	string NodotoString(Nodo<stack>* s);
	string sumaStack(Nodo<stack>* s, Nodo<stack>* s1);
	string restaStack(Nodo<stack>* s, Nodo<stack>* s1);
	string multiStack(Nodo<stack>* s, Nodo<stack>* s1);

	string CorteString(string s1, string s2, string n);

	
	Integer* multiplicacion(Integer* , Integer* s);

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
