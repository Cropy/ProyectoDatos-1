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
	string StacktoString(stack* s);
	string NodotoString(Nodo<stack>* s);
	string sumaStack(Nodo<stack>* s, Nodo<stack>* s1);



	// Sobrecarga operadores asignacion
	Integer& operator =(const Integer&);
	Integer& operator+=(const Integer&);
	Integer& operator-=(const Integer&);
	Integer& operator*=(const Integer&);
	Integer& operator/=(const Integer&);
	Integer& operator =(const long long&);
	Integer& operator+=(const long long&);
	Integer& operator-=(const long long&);
	Integer& operator*=(const long long&);
	Integer& operator/=(const long long&);
	Integer& operator =(const string&);
	Integer& operator+=(const string&);
	Integer& operator-=(const string&);
	Integer& operator*=(const string&);
	Integer& operator/=(const string&);

	// Sobrecarga operadores aritmeticos
	Integer& operator+( Integer&) ;
	Integer operator-(const Integer&) const;
	Integer operator*(const Integer&) const;
	Integer operator/(const Integer&) const;
	Integer operator+(const long long&) const;
	Integer operator-(const long long&) const;
	Integer operator*(const long long&) const;
	Integer operator/(const long long&) const;
	Integer operator+(const string&) const;
	Integer operator-(const string&) const;
	Integer operator*(const string&) const;
	Integer operator/(const string&) const;

	// Sobrecarga operadores comparacion
	bool operator<(const Integer&) const;
	bool operator>(const Integer&) const;
	bool operator<=(const Integer&) const;
	bool operator>=(const Integer&) const;
	bool operator==(const Integer&) const;
	bool operator!=(const Integer&) const;
	bool operator<(const long long&) const;
	bool operator>(const long long&) const;
	bool operator<=(const long long&) const;
	bool operator>=(const long long&) const;
	bool operator==(const long long&) const;
	bool operator!=(const long long&) const;
	bool operator<(const string&) const;
	bool operator>(const string&) const;
	bool operator<=(const string&) const;
	bool operator>=(const string&) const;
	bool operator==(const string&) const;
	bool operator!=(const string&) const;

	// Sobrecarga operadores E/S
	friend istream& operator>>(istream&, Integer&);
	friend ostream& operator<<(ostream&, const Integer&);

	// Extras
	string toString();
	Integer parse(string hilera);
	/*string to_string() const;
	int to_int() const;
	long to_long() const;
	long long to_long_long() const;*/
};
#endif // !INTEGER_H
