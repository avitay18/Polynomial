#pragma once
#include <iostream>

using namespace std;

class Polynomial
{
	friend ostream& operator << (ostream& out, const Polynomial& other);
	friend Polynomial operator * (double, const Polynomial& other);

private:
	static int __MaxDegree;
	const int __Degree;
	double* __arr;
	int counter = 0;

public:
	~Polynomial();
	Polynomial();
	Polynomial(int x);
	Polynomial(double*, int);
	Polynomial(const Polynomial &);
	static int k;
	static int getMaxDegree();
	int getDegree(bool maxDegree) const;
	void setMaxDegree(int);
	void setCoeff(int, double);
	int __MaxValidCoeff;
	Polynomial operator + (const Polynomial&) const;
	Polynomial operator - (const Polynomial&) const;
	Polynomial operator *(const Polynomial&) const;
	Polynomial & operator =(const Polynomial&);
	double& operator[](int);
	double& operator[](int)const;
};