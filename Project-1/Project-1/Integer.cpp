#include "Integer.h"

Lista<stack>* Integer::getLista()
{
	return this->ListaStack;
}

void Integer::setLista(Lista<stack>* lista)
{
	this->ListaStack = lista;
}

void Integer::agregar(string numero) {
	stack* pila = nullptr;
	string auxiliar;
	bool bandera = false;
	if (!bandera) {
		if (numero.at(0) == '-') {
			signo = '-';
			auxiliar = numero.substr(0, 1);

		}
		else {
			signo = '+';
		}
		bandera = true;
	}
	for (int i = 0; i < numero.size(); i += 4) {
		if (pila == nullptr) {
			pila = new stack();
		}
		if (numero.size() - i < 4 && pila->isEmpty()) {
			auxiliar = numero.substr(i, numero.size() - i);
			pila->push(stoul(auxiliar));
		}
		if (!pila->isFull()) {

			if (numero.size() - i <= 4) {
				auxiliar = numero.substr(i, numero.size() - i);
				pila->push(stoul(auxiliar));

			}
			else {
				auxiliar = numero.substr(i, 4);
				pila->push(stoul(auxiliar));
			}
			cout << "Agregando a pila " << endl;
		}
		
		if(pila->isFull())
		{
			cout << "Agregando a  nodo a Lista" << endl;

			ListaStack->agregar(pila);
			pila = nullptr;
		}
	}

}

Integer* Integer::suma(Lista<stack>* lista1, Lista<stack>* lista2)
{
	Integer* resultado = 0;
	unsigned int suma = 0;

	stack* stack1 = new stack();
	Nodo<stack>* nodo1 = new Nodo<stack>();

	if (lista1->getTamano() != 0 && lista2->getTamano() == 0)
	{
		nodo1 = (Nodo<stack>*)lista1->getInicio();
		while (nodo1->getSiguiente() != nullptr)
		{

			stack1 = nodo1->getDatos();
			while (!stack1->isFull())
				suma = stack1->pop();
                resultado->agregar(std::to_string(suma));
	    }
		      nodo1 = nodo1->getSiguiente();
	}

		if (lista1->getTamano() == 0 && lista2->getTamano() != 0)
		{



		}
		return resultado;

	

}

//// Constructores y Destructor
//Integer::Integer()
//{
//
//}
//
//Integer::Integer(const Integer& inte)
//{
//
//}
//
//Integer::Integer(const long long& num)
//{
//
//}
//
//Integer::Integer(const string& hil)
//{
//
//}
//
//Integer::~Integer()
//{
//
//}
//
//// Sets y Gets
//string Integer::get_numero() { return numero; }
//char Integer::get_signo() { return signo; }
//void Integer::set_numero(string num) { numero = num; }
//void Integer::set_signo(char sig) { signo = sig; }
//
//// Sobrecarga operadores asignacion
//Integer& Integer::operator =(const Integer& inte)
//{
//
//}
//
//Integer& Integer::operator+=(const Integer& inte)
//{
//
//}
//
//Integer& Integer::operator-=(const Integer& inte)
//{
//
//}
//
//Integer& Integer::operator*=(const Integer& inte)
//{
//
//}
//
//Integer& Integer::operator/=(const Integer& inte)
//{
//
//}
//
//Integer& Integer::operator =(const long long& inte)
//{
//
//}
//
//Integer& Integer::operator+=(const long long& inte)
//{
//
//}
//
//Integer& Integer::operator-=(const long long& inte)
//{
//
//}
//
//Integer& Integer::operator*=(const long long& inte)
//{
//
//}
//
//Integer& Integer::operator/=(const long long& inte)
//{
//
//}
//
//Integer& Integer::operator =(const string& inte)
//{
//
//}
//
//Integer& Integer::operator+=(const string& inte)
//{
//
//}
//
//Integer& Integer::operator-=(const string& inte)
//{
//
//}
//
//Integer& Integer::operator*=(const string& inte)
//{
//
//}
//
//Integer& Integer::operator/=(const string& inte)
//{
//
//}
//
//// Sobrecarga operadores aritmeticos
//Integer Integer::operator+(const Integer& inte) const
//{
//
//}
//
//Integer Integer::operator-(const Integer& inte) const
//{
//
//}
//
//Integer Integer::operator*(const Integer& inte) const
//{
//
//}
//
//Integer Integer::operator/(const Integer& inte) const
//{
//
//}
//
//Integer Integer::operator+(const long long& inte) const
//{
//
//}
//
//Integer Integer::operator-(const long long& inte) const
//{
//
//}
//
//Integer Integer::operator*(const long long& inte) const
//{
//
//}
//
//Integer Integer::operator/(const long long& inte) const
//{
//
//}
//
Integer& Integer::operator+( Integer& inte) 
{
	
	return *suma(this->getLista(), inte.getLista());

}
//
//Integer Integer::operator-(const string& inte) const
//{
//
//}
//
//Integer Integer::operator*(const string& inte) const
//{
//
//}
//
//Integer Integer::operator/(const string& inte) const
//{
//
//}
//
//// Sobrecarga operadores comparacion
//bool Integer::operator<(const Integer& inte) const
//{
//
//}
//
//bool Integer::operator>(const Integer&) const
//{
//
//}
//
//bool Integer::operator<=(const Integer& inte) const
//{
//
//}
//
//bool Integer::operator>=(const Integer& inte) const
//{
//
//}
//
//bool Integer::operator==(const Integer& inte) const
//{
//
//}
//
//bool  Integer::operator!=(const Integer& inte) const
//{
//
//}
//
//bool  Integer::operator<(const long long& inte) const
//{
//
//}
//
//bool  Integer::operator>(const long long& inte) const
//{
//
//}
//
//bool  Integer::operator<=(const long long& inte) const
//{
//
//}
//
//bool  Integer::operator>=(const long long& inte) const
//{
//
//}
//
//bool  Integer::operator==(const long long& inte) const
//{
//
//}
//
//bool  Integer::operator!=(const long long& inte) const
//{
//
//}
//
//bool  Integer::operator<(const string& inte) const
//{
//
//}
//
//bool  Integer::operator>(const string& inte) const
//{
//
//}
//
//bool  Integer::operator<=(const string& inte) const
//{
//
//}
//
//bool  Integer::operator>=(const string& inte) const
//{
//
//}
//
//bool  Integer::operator==(const string& inte) const
//{
//
//}
//
//bool  Integer::operator!=(const string& inte) const
//{
//
//}
//
//// Sobrecarga operadores E/S
////friend istream& operator>>(istream& o, Integer& obj)
////{
////
////}
////
////friend ostream& operator<<(ostream& o, const Integer& obj)
////{
////
////}
//
//// Extras
//string Integer::toString()
//{
//
//}
//
//Integer Integer::parse(string)
//{
//
//}
//
///*string to_string() const;
//int to_int() const;
//long to_long() const;
//long long to_long_long() const;*/
