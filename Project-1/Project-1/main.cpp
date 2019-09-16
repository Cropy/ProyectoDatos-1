#pragma once
#include"Stack.h"
#include<sstream>
#include<string>
#include<iostream>
#include"Lista.h"


using namespace std;


int main() {

	stack* s = new stack();
	stack* s1 = new stack();
	stack* s2 = new stack();
	



	unsigned int n1 = 22465;
	unsigned int n2 = 22;
	unsigned int n3 = 21;
	unsigned int n4 = 22465;




	s1->push(n1);
	s->push(n2);
	s2->push(n3);

	Lista<stack>* ListaStack = new Lista<stack>();

	ListaStack->agregar(s);
	ListaStack->agregar(s1);
	ListaStack->agregar(s2);




	ListaStack->Print();









	system("pause");
	return 0;
}