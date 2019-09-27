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



	Integer* i1 = new Integer();
	Integer* i2 = new Integer();
	Integer* i3 = new Integer();


	

	i1->agregar("1245644");
	i2->agregar("23");


	//i3 = i1->suma(i1, i2);
	///*i3 = i1->multiplicacion(i2, i1);*/
	//cout << i3->toString() << endl;

	//cout << *i1 << endl;

	//i3 = i1;

	/**i3 = *i2 - *i1;


	cout << *i3 << endl;*/


	/*Integer* g= i1->multiplicacion(i1->getLista(), i2->getLista());*/

   //cout << *g << endl;











	system("pause");
	return 0;
}

