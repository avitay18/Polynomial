#include "polynomial.h"

int Polynomial::__MaxDegree = 0;
int Polynomial::k = 0;

Polynomial::Polynomial() : __Degree(0)
{
	__MaxValidCoeff = 0;
	__arr = new double[1];
	__arr[0] = 0;
}
Polynomial::Polynomial(int x) : __Degree(x)
{
	__MaxDegree = __Degree;
	__arr = new double[__Degree + 1];
	__MaxValidCoeff = 0;
	for (int i = 0; i <= __Degree; i++)
	{
		__arr[i] = 0;
	}
}
Polynomial::Polynomial(double* coeff, int Degree) : __Degree(Degree)
{
	__arr = new double[Degree + 1];
	for (int i = 0; i <= Degree; i++)
	{
		__arr[i] = coeff[i];
		if (__arr[i] != 0) {
			counter++;
			__MaxValidCoeff = i;
		}
	}
	__MaxDegree = __MaxValidCoeff;
}
Polynomial::Polynomial(const Polynomial & otherPoly) : __Degree(otherPoly.__Degree)
{
	__arr = new double[otherPoly.__Degree + 1];
	for (int i = 0; i <= otherPoly.__Degree; i++)
	{
		__arr[i] = otherPoly.__arr[i];
		if (__arr[i] != 0) {
			counter++;
			__MaxValidCoeff = i;
		}
	}
	__MaxDegree = otherPoly.__Degree;
}
int Polynomial::getMaxDegree()
{
	return k;
}
void Polynomial::setMaxDegree(int x)
{
	if (x < 0) throw "Degree cannot be a negative !";
	__MaxDegree = x;
}
int Polynomial::getDegree(bool maxDegree) const
{
	if (maxDegree) {
		return __MaxDegree;
	}
	else {
		return __Degree;
	}
}
void Polynomial::setCoeff(int Degree, double Coeff)
{
	counter = 0;
	for (int i = 0; i <= __Degree; i++) {
		if (i == Degree) {
			__arr[i] = Coeff;
		}
		if (__arr[i] != 0) {
			counter++;
			__MaxValidCoeff = i;
		}
	}
}
Polynomial Polynomial::operator+(const Polynomial & other) const
{
	Polynomial p1(other.__Degree <= this->__Degree ? this->__Degree : other.__Degree);
	if (other.__Degree <= this->__Degree)
	{
		for (int i = 0; i <= this->__Degree; i++)
		{
			if (i <= other.__Degree) {
				p1.setCoeff(i, this->__arr[i] + other.__arr[i]);
			}
			else {
				p1.setCoeff(i, this->__arr[i]);
			}
		}
	}
	else {
		for (int i = 0; i <= other.__Degree; i++)
		{
			if (i <= this->__Degree) {
				p1.setCoeff(i, this->__arr[i] + other.__arr[i]);
			}
			else {
				p1.setCoeff(i, other.__arr[i]);
			}
		}
	}
	return p1;
}
Polynomial Polynomial::operator-(const Polynomial & other) const
{
	Polynomial p1(other.__Degree <= this->__Degree ? this->__Degree : other.__Degree);
	if (other.__Degree <= this->__Degree)
	{
		for (int i = 0; i <= this->__Degree; i++)
		{
			if (i <= other.__Degree) {
				p1.setCoeff(i, this->__arr[i] - other.__arr[i]);
			}
			else {
				p1.setCoeff(i, this->__arr[i]);
			}
		}
	}
	else {
		for (int i = 0; i <= other.__Degree; i++)
		{
			if (i <= this->__Degree) {
				p1.setCoeff(i, this->__arr[i] - other.__arr[i]);
			}
			else {
				p1.setCoeff(i, other.__arr[i]);
			}
		}
	}
	return p1;
}

Polynomial Polynomial::operator*(const Polynomial &other) const
{
	int sumDegree = this->__Degree + other.__Degree;
	Polynomial p1(sumDegree);
	for (int i = 0; i <= this->__Degree; i++)
	{
		for (int j = 0; j <= other.__Degree; j++) {
			p1.setCoeff(i + j, p1.__arr[i + j] += this->__arr[i] * other.__arr[j]);
		}
	}
	return p1;
}
Polynomial & Polynomial::operator=(const Polynomial & other)
{
	for (int i = 0; i <= other.__Degree; i++)
	{
		if (i <= __Degree) {
			this->setCoeff(i, other.__arr[i]);
		}
	}
	if (this->__Degree > __MaxDegree)
		__MaxDegree = this->__Degree;

	return *this;
}
double& Polynomial::operator[](int num)
{
	return this->__arr[num];
}
double& Polynomial::operator[](int num)const
{
	return this->__arr[num];
}
ostream& operator << (ostream& out, const Polynomial& other)
{
	int i;
	if (other.__MaxValidCoeff >= Polynomial::k)
	{
		Polynomial::k = other.__MaxValidCoeff;
	}
	if (other.counter == 0)
	{
		out << "polynomial = ";
		out << "0";
	}
	else
	{
		out << "polynomial = ";
		for (i = 0; i <= other.__Degree; i++)
		{
			if (i == 0) {
				out << other.__arr[i];
			}
			else {
				if (i <= other.__MaxValidCoeff)
				{
					out << "+" <<"("<< other.__arr[i]<<")" <<"*"<< "X^" << i;
				}
			}
		}
		other.__MaxDegree = other.__MaxValidCoeff;
		
	}
	
	out << endl;
	
	return out;
}

Polynomial operator*(double number, const Polynomial & other)
{
	Polynomial p1(other.__Degree);
	for (int i = 0; i <= other.__Degree; i++)
	{
		p1.setCoeff(i, number * other.__arr[i]);
	}
	return p1;
}
Polynomial::~Polynomial() {
	delete[]__arr;
}