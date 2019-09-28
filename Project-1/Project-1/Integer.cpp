#include "Integer.h"
#include"Vector.h"

// Constructores y Destructor
Integer::Integer()
{
	ListaVector = new Lista<Vector>();
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

Lista<Vector>* Integer::getLista()
{
	return this->ListaVector;
}

void Integer::setLista(Lista<Vector>* lista)
{
	this->ListaVector = lista;
}

// Metodos
void Integer::agregar(string numero) {
	int n = 3;
	
	Vector* vector = nullptr;
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

	this->setTam((int)numero.size());

	for (int i = 0; i < numero.size(); i += TamVec) {
		if (vector == nullptr) {
			vector = new Vector();
		}
		if (numero.size() - i < n && vector->getCantidad()==0) {
			auxiliar = numero.substr(i, numero.size() - i);
			vector->insertar(stoul(auxiliar));
			ListaVector->agregar(vector);
			return;
		}
		if (vector->getCantidad()!=3) {

			if (numero.size() - i <= n) {
				auxiliar = numero.substr(i, numero.size() - i);
				vector->insertar(stoul(auxiliar));
				ListaVector->agregar(vector);
				return;

			}
			else {
				auxiliar = numero.substr(i, n);
				vector->insertar(stoul(auxiliar));
			}
			cout << "Agregando a  vector " << endl;
		}
		
		if(vector->getCantidad()==3)
		{
			cout << "Agregando a  nodo a Lista" << endl;

			ListaVector->agregar(vector);
			vector = nullptr;
		}
	}


	cout << this->getLista()->toString();
}

Integer* Integer::suma(Integer* i2)
{


	Integer* temp = new Integer();
	bool carry = 0;
	int x = 0, c = 0;
	Nodo<Vector> *tempA = (this->getLista())->getInicio();
	Nodo<Vector>* tempB = (i2->getLista())->getInicio();
	while (tempA || tempB) {
		short* result = new short[3];
		for (int i = 0; i < 3; i++) {
			unsigned int a = 0, b = 0;
			if (tempA) {

				a = tempA->getDatos()->getNumero(i);
			}
			if (tempB) {
				b = tempB->getDatos()->getNumero(i);

			}
			x = a + b + c;
			c = x / 10000;
			x = x % 10000;
			result[i] = x;
			if (c == 0) {
				carry = false;
			}
			else {
				carry = true;
			}
		}
		temp->big_int->insertarElemento(result); // lista
		if (tempA) {
			tempA = tempA->GetNext(); // getSiguiente
		}
		if (tempB) {
			tempB = tempB->GetNext();
		}
	}
	int look;
	if (carry) {
		short p = (short)c;
		short* pp = new short[3];
		pp[0] = p;
		p = 0;
		pp[1] = p;
		pp[2] = p;
		temp->big_int->insertarElemento(pp);
	}
	std::string ss = "[" + temp->toString() + "]";
	temp->reLengh();
	return temp;
}


//	Integer* Integer::resta(Integer* i1, Integer* i2) {
//		
//}






//string Integer::NodotoString(Nodo<Vector>* n)
//{
//	
//}








//Integer* Integer::multiplicacion(Integer* Int1, Integer* Int2)
//{
//
//	
//
//	
//
//	
//
//}

//// Sobrecarga operadores asignacion

Integer& Integer:: operator =(Integer& x)
{
	if (this != &x) {
		if (x.getLista() != nullptr)
			this->setLista(x.ListaVector);
		if (x.get_signo() != '\0')
			this->set_signo(x.signo);
	}
	return *this;
}


//Integer& Integer::operator+=(Integer& x)
//{
//	//if (this == &x) {
//		return x = *suma(this, &x);
//	//}
//}

//Integer& Integer::operator-=(Integer& x)
//{
//	return x = *resta(this->getLista(), x.getLista());
//}



// Sobrecarga operadores aritmeticos
//Integer& Integer::operator+(Integer& inte)
//{
//	////this->suma(this->getLista(), inte.getLista()) + inte.suma(inte.);
//	//return *this->suma(this, &inte);
//	////return *this;
//}

//Integer& Integer::operator-(Integer& inte)
//{
//	return *this->resta(this->getLista(), inte.getLista());
//}

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
	ss << ListaVector->toString() << endl;
	return ss.str();
}

Integer Integer::parse(string hilera)
{
	return Integer();
}


