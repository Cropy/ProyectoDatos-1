#pragma once
#include"Stack.h"
#include<sstream>
#include<string>
#include<iostream>
#include"Lista.h"
#include "Integer.h"


using namespace std;


int main() {

	stack* s = new stack();
	stack* s1 = new stack();
	stack* s2 = new stack();
	



	unsigned int n1 = 111;
	unsigned int n2 = 222;
	unsigned int n3 = 33;
	unsigned int n4 = 4;




	//s1->push(n1);
	//s1->push(n1);
	//s1->push(n1);




	//s->push(n2);
	//s2->push(n3);

	//Lista<stack>* ListaStack = new Lista<stack>();

	//ListaStack->agregar(s);
	//ListaStack->agregar(s1);
	//ListaStack->agregar(s2);


	//ListaStack->Print();



	Integer *i1 = new Integer();
	Integer* i2 = new Integer();


	i1->agregar("111122223333444433331111");
	i2->agregar("111122223333444433331111");

	Integer* resultado = i1->suma(i1->getLista(), i2->getLista());
	cout << "efsdf" << endl;

	//i1->getLista()->Print();*/



	/*ListaStack->Print();*/









	system("pause");
	return 0;
}