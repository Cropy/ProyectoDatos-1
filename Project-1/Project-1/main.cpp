#pragma once
#include"Stack.h"
#include<sstream>
#include<string>
#include<iostream>

using namespace std;


int main() {

	stack* s = new stack();

	unsigned int n1 = 22465;
	unsigned int n2 = 22465;
	unsigned int n3 = 22465;


	s->push(n1);
	s->push(n2);
	s->push(n3);

	cout << s->size() << endl;
	cout << s->peek() << endl;








	system("pause");
	return 0;
}