#include "Integer.h"

// Constructores y Destructor
Integer::Integer()
{
	ListaStack = new Lista<stack>();
	signo = ' ';
}
//
//Integer::Integer(const Integer&)
//{
//}
//
//Integer::Integer(const long long&)
//{
//}
//
//Integer::Integer(const string&)
//{
//}
//
//Integer::~Integer()
//{
//}

// Sets y Gets
char Integer::get_signo()
{
	return signo;
}

void Integer::set_signo(char sig)
{
	signo = sig;
}

Lista<stack>* Integer::getLista()
{
	return this->ListaStack;
}

void Integer::setLista(Lista<stack>* lista)
{
	this->ListaStack = lista;
}

// Metodos
void Integer::agregar(string numero) {
	int tam = 3;
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
	for (int i = 0; i < numero.size(); i += tam) {
		if (pila == nullptr) {
			pila = new stack();
		}
		if (numero.size() - i < tam && pila->isEmpty()) {
			auxiliar = numero.substr(i, numero.size() - i);
			pila->push(stoul(auxiliar));
			ListaStack->agregar(pila);
			return;
		}
		if (!pila->isFull()) {

			if (numero.size() - i <= tam) {
				auxiliar = numero.substr(i, numero.size() - i);
				pila->push(stoul(auxiliar));
				ListaStack->agregar(pila);
				return;

			}
			else {
				auxiliar = numero.substr(i, tam);
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

	unsigned int n1 = 0 ; //convirtes 
	unsigned int n2 = 0;
	unsigned int resul = 0;

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

		resultado->agregar(sumaS); //agrega el String a la lista del la variable a retonar
		return resultado;
}

Integer* Integer::resta(Lista<stack>* lista1, Lista<stack>* lista2) {
	Integer* resultado = new Integer(); // valor a retonar

	string restaR; // va concatenado valores 
	bool bandera = false;// evitar al if en la linea 102
	stack* stack1 = nullptr; // guarda el stack de la lista 1;
	stack* stack2 = nullptr; // guarda el stack de la lista 2;

	unsigned int n1 = 0; //convirtes 
	unsigned int n2 = 0;
	unsigned int resul = 0;

	Nodo<stack>* nodo1 = new Nodo<stack>(); // guarda el nodo de la lista1 para recorrer
	Nodo<stack>* nodo2 = new Nodo<stack>(); // guarda el nodo de la lista2 para recorrer

	if (lista1->getTamano() != 0 && lista2->getTamano() == 0) // si la lista1 tiene elementos y la lista2 = 0
	{
		nodo1 = lista1->getInicio();
		while (nodo1 != nullptr)
		{
			restaR += NodotoString(nodo1);
			nodo1 = nodo1->getSiguiente();
		}
		bandera = true;

	}

	if (lista1->getTamano() == 0 && lista2->getTamano() != 0) // si la lista2 tiene elementos y la lista1 = 0
	{

		nodo2 = lista2->getInicio();
		while (nodo2 != nullptr)
		{
			restaR += NodotoString(nodo2);
			nodo2 = nodo1->getSiguiente();
		}
		bandera = true;


	}


	if (!bandera) { // si NO ENTRO  a los metodos anteriores

		nodo1 = lista1->getInicio();
		nodo2 = lista2->getInicio();

		while (nodo1 != nullptr && nodo2 != nullptr) // en el momento que una lista sea mas larga que la otra para
		{

			restaR += restaStack(nodo1, nodo2);
			nodo1 = nodo1->getSiguiente();
			nodo2 = nodo2->getSiguiente();

		}


	}

	if (nodo1 != nullptr && nodo2 == nullptr) // si lista es  mas larga que lista 2, continua con la lista 1
	{
		while (nodo1 != nullptr)
		{
			n1 = stoul(NodotoString(nodo1));
			restaR += std::to_string(n1);
			nodo1 = nodo1->getSiguiente();

		}
	}

	if (nodo2 != nullptr && nodo1 == nullptr) // si lista es  mas larga que lista 2, continua con la lista 2
	{
		while (nodo2 != nullptr)
		{
			n2 = stoul(NodotoString(nodo2));
			restaR += std::to_string(n2);
			nodo2 = nodo1->getSiguiente();

		}
	}

	resultado->agregar(restaR); //agrega el String a la lista del la variable a retonar
	return resultado;
}

string Integer::StacktoString(stack* s)  // concatena los numeros de unStack en un String
{
	
	string resultado;
	while (!s->isEmpty()) {
		resultado += std::to_string(s->pop());
	}
	

	return resultado;
}

string Integer::NodotoString(Nodo<stack>* s)
{
	

	return StacktoString(s->getDatos());

}

string Integer::sumaStack(Nodo<stack>* s1, Nodo<stack>* s2)
{
	stack* stack1 = s1->getDatos();
	stack* stack2 = s2->getDatos();
	unsigned int sum = 0;
	string resul;
	while (!stack1->isEmpty() && !stack2->isEmpty()) {
	
		sum = stack1->pop() + stack2->pop();
		resul += std::to_string(sum);
	}
	return resul;
}

string Integer::restaStack(Nodo<stack>* s1, Nodo<stack>* s2) {
	stack* stack1 = s1->getDatos();
	stack* stack2 = s2->getDatos();
	unsigned int res = 0;
	string resul;
	
	while(!stack1->isEmpty() && !stack2->isEmpty()) {
		res = stack1->pop() - stack2->pop();
		resul += std::to_string(res);
	}
	
	return resul;
}

//string Integer::multiStack(Nodo<stack>* s1, Nodo<stack>* s2)
//{
//	stack* stack1 = s1->getDatos();
//	stack* stack2 = s2->getDatos();
//	unsigned int multi = 0;
//	string resul;
//	string cantSumas= StacktoString(stack2);
//	string sumando = StacktoString(stack1);
//
//	unsigned int i = 0;
//
//	while (i < stoul(cantSumas)) {
//		
//		multi += stoul(sumando);
//		i++;
//	}
//
//	return std::to_string(multi);
//	
//}

Integer* Integer::multiplicacion(Lista<stack>* lista1, Lista<stack>* lista2)
{
	Nodo<stack>* n1=lista1->getInicio();
	Nodo<stack>* n2= lista2->getInicio();
	string  l1, l2;
	int x = 0;
    int j = 0;
	int tam1 = lista1->cantNodos();
	int tam2 = lista2->cantNodos();

	Integer* resultado = new Integer();
	string numeroFinal;

	
		unsigned int* prod = new unsigned  int[(tam1+tam2)-1];

		// Initialize the porduct polynomial 
		for (int i = 0; i < (tam1 + tam2) - 1; i++)
			prod[i] = 0;

		// Multiply two polynomials term by term 

		// Take ever term of first polynomial 
		while (x<tam1)
		{
			l1 = NodotoString(n1);
			// Multiply the current term of first polynomial 
			// with every term of second polynomial. 
			while (j<tam2) {
				
				
				l2 = NodotoString(n2);

				prod[x + j] += stoul(l1) * stoul(l2);
				n2 = n2->getSiguiente();
				j++;

			}

			n1 = n1->getSiguiente();
			x++;
		}
		for (int i = 0; i < (tam1 + tam2) - 1; i++) {
		
			numeroFinal += std::to_string(prod[i]);
		
		}

		resultado->agregar(numeroFinal);

		return resultado;
	
	
	}
	


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

Integer& Integer::operator+(Integer& inte) 
{
	
	return *suma(this->getLista(), inte.getLista());

}

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

//// Sobrecarga operadores E/S
istream& operator>>(istream& o, Integer& obj)
{
	return o;
}

ostream& operator<<(ostream& o, Integer& obj)
{
	o << obj.toString();
	return o;
}

//// Extras
string Integer::toString()
{
	stringstream ss;
	ss << ListaStack->Print();
	return ss.str();
}

//Integer Integer::parse(string)
//{
//
//}

/*string to_string() const;
int to_int() const;
long to_long() const;
long long to_long_long() const;*/
