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
			this->signo = '-';
			auxiliar = numero.substr(0, 1);

		}
		else {
			this->signo = '+';
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
				ListaStack->agregar(pila);

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
	Integer* resultado = new Integer(); // valor a retonar

	string sumaS; // va concatenado valores 
	bool bandera = false;// evitar al if en la linea 102
	stack* stack1= nullptr; // guarda el stack de la lista 1;
	stack* stack2 = nullptr; // guarda el stack de la lista 2;

	unsigned int n1=0 ; //convirtes 
	unsigned int n2=0;
	unsigned int resul=0;

	Nodo<stack>* nodo1 = new Nodo<stack>(); // guarda el nodo de la lista1 para recorrer
	Nodo<stack>* nodo2  = new Nodo<stack>(); // guarda el nodo de la lista2 para recorrer

	if (lista1->getTamano() != 0 && lista2->getTamano() == 0) // si la lista1 tiene elementos y la lista2 = 0
	{
		nodo1 = lista1->getInicio();
		while (nodo1 != nullptr) 
		{
			sumaS += NodotoString(nodo1);
			nodo1 = nodo1->getSiguiente();
		}
		bandera = true;

	}
	
		
	if (lista1->getTamano() == 0 && lista2->getTamano() != 0) // si la lista2 tiene elementos y la lista1 = 0
	{

		nodo2 = lista2->getInicio();
		while (nodo2 != nullptr)
		{
			sumaS += NodotoString(nodo2);
			nodo2 = nodo1->getSiguiente();
		}
		bandera = true;


	}
	

	
	if(!bandera ) { // si NO ENTRO  a los metodos anteriores

		nodo1 = lista1->getInicio();
		nodo2 = lista2->getInicio();

		while (nodo1 != nullptr && nodo2 != nullptr) // en el momento que una lista sea mas larga que la otra para
		{
			
			sumaS += sumaStack(nodo1, nodo2); 
			nodo1 = nodo1->getSiguiente();
			nodo2 = nodo2->getSiguiente();

		}


		}

		if (nodo1 != nullptr && nodo2 == nullptr) // si lista es  mas larga que lista 2, continua con la lista 1
		{
			while (nodo1 != nullptr)
			{
				n1= stoul(NodotoString(nodo1));
				sumaS += std::to_string(n1);
				nodo1 = nodo1->getSiguiente();

			}
		}

		if (nodo2 != nullptr && nodo1 == nullptr) // si lista es  mas larga que lista 2, continua con la lista 2
		{
			while (nodo2 != nullptr)
			{
				n2 = stoul(NodotoString(nodo2));
				sumaS += std::to_string(n2);
				nodo2 = nodo1->getSiguiente();

			}
		}


	/*}*/
		resultado->agregar(sumaS); //agrega el String a la lista del la variable a retonar

		return resultado;

	

}


string Integer::StacktoString(stack* s)  // concatena los numeros de unStack en un String
{
	unsigned int suma = 0;
	string resultado;
	while (!s->isEmpty()) {
		suma += s->pop();
	}
	resultado = std::to_string(suma);

	return resultado;
}

string Integer::NodotoString(Nodo<stack>* s) // concatena los numeros del Stack del nodo  en un String
{
	

	return StacktoString(s->getDatos());

}

string Integer::sumaStack(Nodo<stack>* s, Nodo<stack>* s1)// recibe 2 nodos y va sumamando ada pocosion del stack de cada nodo
{
	stack* stack1 = s->getDatos();
	stack* stack2 = s1->getDatos();
	unsigned int sum = 0;
	string resul;
	while (!stack1->isEmpty() && !stack2->isEmpty()) {
	
		sum = stack1->pop() + stack2->pop();
		resul += std::to_string(sum);
	}

	if (stack2->isEmpty() && !stack1->isEmpty()) { // si la pila 2 ya esta vacia y la pila1 no
		while (!stack1->isEmpty()) {

			sum = stack1->pop();
			resul += std::to_string(sum);
		}
	}

	if (stack1->isEmpty() && !stack2->isEmpty()) { // si la pila 1 ya esta vacia y la pila2 no
		while (!stack2->isEmpty()) {

			sum = stack2->pop();
			resul += std::to_string(sum);
		}
	}
	return resul;
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
