
#include <iostream>
#include "polynomial.h"
#include "rational.h"

void testPolynomial()
{
    cout << "----- start testPolynomial ---------" << endl;
    cout << "test0 :" << Polynomial::getMaxDegree() <<endl;
    Polynomial p1;
    cout << "test1: " <<p1;
    Polynomial p2(16);
    p2.setCoeff(2, 0.4);
    cout << "test2: " << p2 << "degree=" << p2.getDegree(false)<<endl;
    double c[5] = { 0.1, 0.2, 0 ,11.5, 1.3};
    Polynomial p3(c,4);
    cout << "test3: " << p3;
    p2.setCoeff(2, 0.0);
    cout << "test4: " << p2;
    p2 = (p1 + 2.5*p3 -0.9*p3)*p3;
    p2[5] = 1;
    cout << "test5 " << p2 << endl << "(2*p2)[6] = " <<(2*p2)[6] <<endl;
    cout << "test6 :maxDegree = " << Polynomial::getMaxDegree() << endl;
    cout << "______________"<< endl;
}

void testRational() {
   cout << "----- start testRational ---------" << endl;
    cout << "test7" << endl;
   rational r1;
    r1.print();
    cout << r1;
    double c[] = { 0,2,2,3,4,5 };
    Polynomial p1(c, 5);
    c[0] = 1.2;
   Polynomial p2(c, 3);
   rational r2(p1, p2);
    cout << "test8" << endl;
    r2.print();
   cout << endl<< r2<<endl;
   cout << "test9" << endl;
   cout << "nom = " << r2.getNom();
    cout << "denom = " << r2.getDenom();
    rational r3 = r2*r2 + r2;
    cout << "test10 : r3 = " << endl << r3 << endl;
    double d[21] = {0};
    d[0] = 1;
    Polynomial p3(d, 20);
    rational r4(p3, p3);
    r4 = (r2+r4)*r2;
    cout << "test11 : r4 = " << endl << r4 << endl;
    cout << "test12 :maxDegree = " << Polynomial::getMaxDegree() << endl;
   cout << "__________________________"<<endl;
}

int main()
{
    testPolynomial();
    testRational();
}

