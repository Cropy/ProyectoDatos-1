// Utiles.h
// Autores: Jeoffrey Prado, Christian Cruz, Lorenzo Solorzano
// Descripciones: Funciones de utilidad

#ifndef UTILES_H
#define UTILES_H

#include <tuple>
#include <string>
using namespace std;

class Utiles {
public:
	static bool es_numero_valido(const string& num);
	static void eliminar_ceros_izquierda(string& num);
	static void agregar_ceros_izquierda(string& num, size_t cant_ceros);
	static void agregar_ceros_derecha(string& num, size_t cant_ceros);
	static tuple<string, string> igualar_numeros(const string& num1, const string& num2);
};
#endif // !UTILES_H
