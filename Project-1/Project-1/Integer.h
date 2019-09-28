// Integer.h
// Autores: Jeoffrey Prado, Lorenzo Solorzano, Christian Cruz
// Descripcion: Clase Integer, permite trabajar con datos string, int y long

#ifndef INTEGER_H
#define INTEGER_H 

#define ZERO 0
#define ONE 1
#define TamVec 3


#include "Lista.h"
#include "Vector.h"

class Integer {
private:
	Lista<Vector>* ListaVector;
	int tam;
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
	int getam();
	void setTam(int t);
	void set_signo(char sig);
	Lista<Vector>* getLista();
	void setLista(Lista<Vector>* lista);


	//Metodos
	void agregar(string numero);
	Integer* suma( Integer*);
	Integer* resta(Integer*, Integer*);
	string NodotoString(Nodo<Vector>* s);
	Integer* multiplicacion(Integer*, Integer*);


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
