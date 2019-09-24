#ifndef VECTOR
#define VECTOR
#define SIZE 4

#include <iostream>
#include <sstream>
using namespace std;

class Vector {
private:
	int cant;
	int vect[SIZE];

public:
	Vector();
	~Vector();
	void insertar(int numero);
	int getNumero(int i);
	string toString();
	int getCantidad();
};
ostream& operator << (ostream&, Vector&);

#endif // !VECTOR