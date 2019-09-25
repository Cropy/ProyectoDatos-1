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


	i1->agregar("666688886666444466668888");
	i2->agregar("333344443333222233334444");


	

	Integer* resultado = i1->resta(i1->getLista(), i2->getLista());
	cout << "efsdf" << endl;

	resultado->getLista()->Print();



	









	system("pause");
	return 0;
}