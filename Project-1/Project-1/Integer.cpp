#include "Integer.h"

// Constructores y Destructor
Integer::Integer()
{
	ListaStack = new Lista<stack>();
	signo = ' ';
}

Integer::Integer(const Integer&)
{
}

Integer::Integer(const long long&)
{
}

Integer::Integer(const string&)
{
}

Integer::~Integer()
{
}

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
	int n = 3;
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
	for (int i = 0; i < numero.size(); i += n) {
		if (pila == nullptr) {
			pila = new stack();
		}
		if (numero.size() - i < n && pila->isEmpty()) {
			auxiliar = numero.substr(i, numero.size() - i);
			pila->push(stoul(auxiliar));
			ListaStack->agregar(pila);
			return;
		}
		if (!pila->isFull()) {

			if (numero.size() - i <= n) {
				auxiliar = numero.substr(i, numero.size() - i);
				pila->push(stoul(auxiliar));
				ListaStack->agregar(pila);
				return;

			}
			else {
				auxiliar = numero.substr(i, n);
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

Integer* Integer::suma(Integer* i1, Integer* i2)
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

	if (i1->getLista()->getTamano() != 0 && i2->getLista()->getTamano() == 0) // si la lista1 tiene elementos y la lista2 = 0
	{
		resultado = i1;
		
		bandera = true;
		return resultado;

	}
			
	if (i1->getLista()->getTamano() == 0 && i2->getLista()->getTamano() != 0) // si la lista2 tiene elementos y la lista1 = 0
	{

		resultado = i2;
		bandera = true;
		return resultado;

	}


	if (!bandera) { // si NO ENTRO  a los metodos anteriores

		nodo1 = i1->getLista()->getInicio();
		nodo2 = i2->getLista()->getInicio();

		while (nodo1 != nullptr && nodo2 != nullptr) // en el momento que una lista sea mas larga que la otra para
		{

			sumaS += sumaStack(nodo1, nodo2);
			nodo1 = nodo1->getSiguiente();
			nodo2 = nodo2->getSiguiente();

		}




		if (nodo1 != nullptr && nodo2 == nullptr) // si lista es  mas larga que lista 2, continua con la lista 1
		{
			while (nodo1 != nullptr)
			{
				n1 = stoul(SumarNodo(nodo1));
				sumaS += std::to_string(n1);
				nodo1 = nodo1->getSiguiente();

			}
		}

		if (nodo2 != nullptr && nodo1 == nullptr) // si lista es  mas larga que lista 2, continua con la lista 2
		{
			while (nodo2 != nullptr)
			{
				n2 = stoul(SumarNodo(nodo2));
				sumaS += std::to_string(n2);
				nodo2 = nodo1->getSiguiente();

			}
		}

	}
		resultado->agregar(sumaS); //agrega el String a la lista del la variable a retonar
		return resultado;
	}


	Integer* Integer::resta(Lista<stack> * lista1, Lista<stack> * lista2) {
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

		//if (lista1->getTamano() != 0 && lista2->getTamano() == 0) // si la lista1 tiene elementos y la lista2 = 0
		//{
		//	nodo1 = lista1->getInicio();
		//	while (nodo1 != nullptr)
		//	{
		//		restaR += NodotoString(nodo1);
		//		nodo1 = nodo1->getSiguiente();
		//	}
		//	bandera = true;

		//}

		//if (lista1->getTamano() == 0 && lista2->getTamano() != 0) // si la lista2 tiene elementos y la lista1 = 0
		//{

		//	nodo2 = lista2->getInicio();
		//	while (nodo2 != nullptr)
		//	{
		//		restaR += NodotoString(nodo2);
		//		nodo2 = nodo1->getSiguiente();
		//	}
		//	bandera = true;


	//}

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
			n1 = stoul(SumarNodo(nodo1));
			restaR += std::to_string(n1);
			nodo1 = nodo1->getSiguiente();

		}
	}

	if (nodo2 != nullptr && nodo1 == nullptr) // si lista es  mas larga que lista 2, continua con la lista 2
	{
		while (nodo2 != nullptr)
		{
			n2 = stoul(SumarNodo(nodo2));
			restaR += std::to_string(n2);
			nodo2 = nodo1->getSiguiente();

		}
	}

	resultado->agregar(restaR); //agrega el String a la lista del la variable a retonar
	return resultado;
}


string Integer::SumaStack(stack* s)  // concatena los numeros de unStack en un String
{
	unsigned int suma = 0;
	string resultado;
	while (!s->isEmpty()) {
		suma += s->pop();
	}
	resultado = std::to_string(suma);

	return resultado;
}

string Integer::SumarNodo(Nodo<stack>* s)
{
	

	return SumaStack(s->getDatos());

}

string Integer::NodotoString(Nodo<stack>* n)
{
	stack* s =n->getDatos();
	stack* aux = new stack();
	aux = s->invertirPila(s);
	string resultado;
	while (!aux->isEmpty()) {
		resultado += std::to_string(aux->pop());
	}


	return resultado;
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

string Integer::CorteString(string s1, string s2, string  n)
{

	int tam = n.size();
	int sizeS1 = s1.length();
	int sizeS2 = s2.length();
	string aux1, aux2;
	if (sizeS2 == 0) {
	
		return s1;
	}
	else
	 aux1 = s1.substr(sizeS1 - tam, sizeS1-1);
	 aux2 = s2.substr(0, (sizeS2));

	return "s";
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
//	int i = 0;
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

Integer* Integer::multiplicacion(Integer* Int1, Integer* Int2)
{
	Nodo<stack>* nodo1;
	Nodo<stack>* nodo2;

	Integer* tmp1 = new Integer();

	Integer* tmp2 = new Integer();
	
	string   aux1="";
	string   aux2="";


	nodo1 = Int1->getLista()->getInicio();
	while (nodo1 != nullptr) {

		unsigned int num1 = stoul(NodotoString(nodo1));
		 nodo2 = Int2->getLista()->getInicio();
		 while (nodo2 != nullptr) {

			 string g = NodotoString(nodo2);
			 int size = g.length();
			 unsigned int num2 = stoul(g);
			 unsigned int multi = 0;
			 multi = num2 * num1;
			

		      
			 string s=std::to_string(multi); // recortar desde n-1 hasta tam;

			 /*CorteString(s, aux2, std::to_string(num1));*/
			 s = s + aux2; // desde 0 (tam-n)-1
			 aux2 = s;
			 nodo2 = nodo2->getSiguiente();
		 
		 }
		
		 
		 tmp2->agregar(aux2);
		 tmp1 = suma(tmp1, tmp2);
		 aux2 = "";

		nodo1 = nodo1->getSiguiente();
 }
	/*if (Int1->get_signo() == '+' && Int2->get_signo() == '+')
		tmp1->set_signo('+');
	if (Int1->get_signo() == '-' && Int2->get_signo() == '+')
		tmp1->set_signo('-');
	if (Int1->get_signo() == '+' && Int2->get_signo() == '-')
		tmp1->set_signo('-');
	if (Int1->get_signo() == '-' && Int2->get_signo() == '-')
		tmp1->set_signo('+');*/



	return tmp1;






	

}

//// Sobrecarga operadores asignacion

Integer& Integer:: operator =(Integer& x)
{
	if (this != &x) {
		if (x.getLista() != nullptr)
			this->setLista(x.ListaStack);
		if (x.get_signo() != '\0')
			this->set_signo(x.signo);
	}
	return *this;
}


Integer& Integer::operator+=(Integer& x)
{
	//if (this == &x) {
		return x = *suma(this, &x);
	//}
}

Integer& Integer::operator-=(Integer& x)
{
	return x = *resta(this->getLista(), x.getLista());
}



// Sobrecarga operadores aritmeticos
Integer& Integer::operator+(Integer& inte)
{
	//this->suma(this->getLista(), inte.getLista()) + inte.suma(inte.);
	return *this->suma(this, &inte);
	//return *this;
}

Integer& Integer::operator-(Integer& inte)
{
	return *this->resta(this->getLista(), inte.getLista());
}

//Integer& Integer::operator*(Integer&)
//{
//	// TODO: insertar una instrucción return aquí
//}
//
//Integer& Integer::operator/(Integer&)
//{
//	// TODO: insertar una instrucción return aquí
//}
//
//bool Integer::operator<(Integer&)
//{
//	return false;
//}
//
//bool Integer::operator>(Integer&)
//{
//	return false;
//}
//
//bool Integer::operator<=(Integer&)
//{
//	return false;
//}
//
//bool Integer::operator>=(Integer&)
//{
//	return false;
//}
//
//bool Integer::operator==(Integer&)
//{
//	return false;
//}
//
//bool Integer::operator!=(Integer&)
//{
//	return false;
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

Integer Integer::parse(string hilera)
{
	return Integer();
}


