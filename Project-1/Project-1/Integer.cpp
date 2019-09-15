#include "Integer.h"

// Constructores y Destructor
Integer::Integer()
{

}

Integer::Integer(const Integer& inte)
{

}

Integer::Integer(const long long& num)
{

}

Integer::Integer(const string& hil)
{

}

Integer::~Integer()
{

}

// Sets y Gets
string Integer::get_numero() { return numero; }
char Integer::get_signo() { return signo; }
void Integer::set_numero(string num) { numero = num; }
void Integer::set_signo(char sig) { signo = sig; }

// Sobrecarga operadores asignacion
Integer& Integer::operator =(const Integer& inte)
{

}

Integer& Integer::operator+=(const Integer& inte)
{

}

Integer& Integer::operator-=(const Integer& inte)
{

}

Integer& Integer::operator*=(const Integer& inte)
{

}

Integer& Integer::operator/=(const Integer& inte)
{

}

Integer& Integer::operator =(const long long& inte)
{

}

Integer& Integer::operator+=(const long long& inte)
{

}

Integer& Integer::operator-=(const long long& inte)
{

}

Integer& Integer::operator*=(const long long& inte)
{

}

Integer& Integer::operator/=(const long long& inte)
{

}

Integer& Integer::operator =(const string& inte)
{

}

Integer& Integer::operator+=(const string& inte)
{

}

Integer& Integer::operator-=(const string& inte)
{

}

Integer& Integer::operator*=(const string& inte)
{

}

Integer& Integer::operator/=(const string& inte)
{

}

// Sobrecarga operadores aritmeticos
Integer Integer::operator+(const Integer& inte) const
{

}

Integer Integer::operator-(const Integer& inte) const
{

}

Integer Integer::operator*(const Integer& inte) const
{

}

Integer Integer::operator/(const Integer& inte) const
{

}

Integer Integer::operator+(const long long& inte) const
{

}

Integer Integer::operator-(const long long& inte) const
{

}

Integer Integer::operator*(const long long& inte) const
{

}

Integer Integer::operator/(const long long& inte) const
{

}

Integer Integer::operator+(const string& inte) const
{

}

Integer Integer::operator-(const string& inte) const
{

}

Integer Integer::operator*(const string& inte) const
{

}

Integer Integer::operator/(const string& inte) const
{

}

// Sobrecarga operadores comparacion
bool Integer::operator<(const Integer& inte) const
{

}

bool Integer::operator>(const Integer&) const
{

}

bool Integer::operator<=(const Integer& inte) const
{

}

bool Integer::operator>=(const Integer& inte) const
{

}

bool Integer::operator==(const Integer& inte) const
{

}

bool  Integer::operator!=(const Integer& inte) const
{

}

bool  Integer::operator<(const long long& inte) const
{

}

bool  Integer::operator>(const long long& inte) const
{

}

bool  Integer::operator<=(const long long& inte) const
{

}

bool  Integer::operator>=(const long long& inte) const
{

}

bool  Integer::operator==(const long long& inte) const
{

}

bool  Integer::operator!=(const long long& inte) const
{

}

bool  Integer::operator<(const string& inte) const
{

}

bool  Integer::operator>(const string& inte) const
{

}

bool  Integer::operator<=(const string& inte) const
{

}

bool  Integer::operator>=(const string& inte) const
{

}

bool  Integer::operator==(const string& inte) const
{

}

bool  Integer::operator!=(const string& inte) const
{

}

// Sobrecarga operadores E/S
friend istream& operator>>(istream& o, Integer& obj)
{

}

friend ostream& operator<<(ostream& o, const Integer& obj)
{

}

// Extras
string Integer::toString()
{

}

Integer Integer::parse(string)
{

}

/*string to_string() const;
int to_int() const;
long to_long() const;
long long to_long_long() const;*/
