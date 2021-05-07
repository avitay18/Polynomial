#include "rational.h"

rational::rational() : __p1(0), __p2(new double[1]{1.0} , 0){}
rational::rational(Polynomial nom, Polynomial denom) : __p1(nom), __p2(denom){}
rational::rational(const rational &other) : __p1(other.__p1), __p2(other.__p2){}

const Polynomial& rational::getNom() const
{
	return __p1;
}
const Polynomial& rational::getDenom() const
{
	return __p2;
}
void rational::print()
{
	cout << __p1 << "--------------------------" << endl << __p2;
}
rational rational::operator*(const rational &other)
{
	Polynomial nom(__p1 * other.__p1);
	Polynomial denom(__p2 * other.__p2);
	rational temp(nom , denom);
	return temp;
}
rational rational::operator+(const rational &other)
{
	Polynomial nom1(__p1 * other.__p2);
	Polynomial nom2(__p2 * other.__p1);
	Polynomial sum(nom1 + nom2);
	Polynomial mullDenom(__p2 * other.__p2);
	rational r1(sum, mullDenom);
	return r1;
}
rational & rational::operator=(const rational &other)
{
	this->__p1 = other.__p1;
	this->__p2 = other.__p2;
	return *this;
}
ostream& operator << (ostream& out, const rational& other)
{
	out << other.__p1 << "--------------------------" << endl << other.__p2;
	return out;
}