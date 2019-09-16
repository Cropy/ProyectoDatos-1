#pragma once
#include"Stack.h"
#include<sstream>
#include<string>
#include<stream>

using namespace std;


int main() {

	stack* stack = new stack();

	stack->push(2);
	stack->push(4);
	stack->push(3);

	cout << stack->size() << endl;
	cout << stack->peek() << endl;








	system("pause");
	return 0;
}