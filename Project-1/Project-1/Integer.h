// Integer.h
// Autores: Jeoffrey Prado, Lorenzo Solorzano, Christian Cruz
// Descripcion: Clase Integer, permite trabajar con datos string, int y long

#ifndef INTEGER_H
#define INTEGER_H 

#define ZERO 0
#define ONE 1

#include "Utiles.h"
#include "Lista.h"
#include"Stack.h"
using namespace std;


class Integer {
private:
	Lista<stack>* ListaStack;
	char signo;
public:
	// Constructores y Destructor
	Integer() {
		ListaStack = new Lista<stack>();
		signo = ' ';
	
	}
	Integer(const Integer&);
	Integer(const long long&);
	Integer(const string&);
	~Integer();

	// Sets y Gets
	string get_numero();
	char get_signo();
	void set_numero(string);
	void set_signo(char);

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
	Integer operator+(const Integer&) const;
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
	Integer parse(string);
	/*string to_string() const;
	int to_int() const;
	long to_long() const;
	long long to_long_long() const;*/
};
#endif // !INTEGER_H
