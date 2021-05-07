#pragma once
using namespace std;

#include <iostream>
#include "polynomial.h"

class rational
{
	friend ostream& operator << (ostream& out, const rational& other);

private:
	Polynomial __p1;
	Polynomial __p2;

public:
	rational();
	rational(Polynomial nom, Polynomial denom);
	rational(const rational&);
	const Polynomial& getNom() const;
	const Polynomial& getDenom() const;
	void print();
	rational operator *(const rational&);
	rational operator +(const rational&);
	rational & operator = (const rational&);
};