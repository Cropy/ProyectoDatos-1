#pragma once


#include "Integer.h"




using namespace std;

int main() {


	Integer* i1 = new Integer();
	Integer* i2 = new Integer();
	Integer* i3 = new Integer();


	

	i1->agregar("9999");
	i2->agregar("9999");

	i3 = i1->suma(i2);



	//i3 = i1->suma(i1, i2);
	///*i3 = i1->multiplicacion(i2, i1);*/
	cout << i3->toString() << endl;

	










	system("pause");
	return 0;
}

