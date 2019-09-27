#include "Integer.h"
#include<vector>

// Constructores y Destructor
Integer::Integer()
{
	ListaStack = new Lista<stack>();
	signo = ' ';
	tam = 0;
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

int Integer::getam()
{
	return tam;
}

void Integer::setTam(int t)
{
	tam = t;
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

	this->setTam(numero.size());
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

	
	
}


	Integer* Integer::resta(Integer* i1, Integer* i2) {
		
}






string Integer::NodotoString(Nodo<stack>* n)
{
	
}








Integer* Integer::multiplicacion(Integer* Int1, Integer* Int2)
{

	

	Nodo<stack>* nodo1;
	Nodo<stack>* nodo2;

	Integer* tmp1 = new Integer();
    Integer* tmp2 = new Integer();
	
	string   aux1="";
	string   aux2="";
	 
	unsigned int num1 = 0;
	unsigned int num2 = 0;


	vector<int> result(Int1->getam()+Int2->getam(), 0);
	int i_n1 = 0;
	int i_n2 = 0;


	nodo1 = Int1->getLista()->getInicio();
	nodo2 = Int2->getLista()->getInicio();

	
	nodo1 = Int1->getLista()->getInicio();
	while (nodo1 != nullptr) {

		
		aux1 = NodotoString(nodo1);
		for (int i = 0; i < aux1.length(); i++) {
			unsigned int num1 = (unsigned int) aux1[i] - '0'; /* stoul(NodotoString(nodo1));*/
			int carry = 0;
			i_n2 = 0;
			nodo2 = Int2->getLista()->getInicio();
			while (nodo2 != nullptr) {


				string g = NodotoString(nodo2);
				for (int j = 0; j < g.length(); j++)
				{
					unsigned int num2 = (unsigned int)g[j] - '0';
					unsigned int multi = 0;

					multi = num1 * num2 + result[i_n1+i_n2]+carry;
					carry = multi / 10;


					result[i_n1 +i_n2] = multi % 10;
					string s = std::to_string(multi); // recortar desde n-1 hasta tam;

					i_n2++;
					s = s + aux2; 
					aux2 = s;
				}
				if (carry > 0) 
					result[i_n1+i_n2] += carry;
				i_n1++;
				nodo2 = nodo2->getSiguiente();

			}


			tmp2->agregar(aux2);
			tmp1 = suma(tmp1, tmp2); // SUMA MALA
			aux2 = "";

		}
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


