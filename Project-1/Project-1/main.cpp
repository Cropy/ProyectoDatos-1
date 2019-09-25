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



	Integer *i1 = new Integer();
	Integer* i2 = new Integer();


	i1->agregar("20");
	i2->agregar("3");


	

	string g =i1->multiStack(i1->getLista()->getInicio(), i2->getLista()->getInicio());

	cout << g << endl;

	









	system("pause");
	return 0;
}