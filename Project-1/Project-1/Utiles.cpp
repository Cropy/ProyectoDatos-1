#include "Utiles.h"

bool Utiles::es_numero_valido(const string& num)
{
	for (char digito : num)
		if (digito < '0' || digito > '9')
			return false;
	return true;
}

void Utiles::eliminar_ceros_izquierda(string& num)
{
	size_t i;
	for (i = 0; i < num.size(); i++)
		if (num[i] != '0')
			break;

	if (i == num.size())
		num = "0";
	else
		num = num.substr(i);
}

void Utiles::agregar_ceros_izquierda(string& num, size_t cant_ceros)
{
	num = string(cant_ceros, '0') + num;
}

void Utiles::agregar_ceros_derecha(string& num, size_t cant_ceros)
{
	num += string(cant_ceros, '0');
}

tuple<string, string> Utiles::igualar_numeros(const string& num1, const string& num2)
{
	string grande, peque;
	if (num1.size() > num2.size() || (num1.size() == num2.size() and num1 > num2)) {
		grande = num1;
		peque = num2;
	}
	else {
		grande = num2;
		peque = num1;
	}
	agregar_ceros_izquierda(peque, grande.size() - peque.size());
	return make_tuple(grande, peque);
}
