#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include "polynomial.h"

using namespace std;
using namespace polynomial_h;


void testPolynomialCreation1();
void testPolynomialCreation2();
void testPolynomialCreation3();

int main(int argc, char* argv[]){
    testPolynomialCreation1();
    testPolynomialCreation2();
    testPolynomialCreation3();
    return EXIT_SUCCESS;
}


void testPolynomialCreation1(){
    cout << "Testing Polynomail Creation:" << endl;
    cout << "Attempting to build the following:" << endl;
    cout << "Test 1:  (4) == ";
    Polynomial p = Polynomial(4.0);
    p.print();
    cout << "Outcome: ";
    if(p.eval(27) == 4.0){
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}

void testPolynomialCreation2(){
    cout << "Testing Polynomail Creation:" << endl;
    cout << "Attempting to build the following:" << endl;
    cout << "Test 2:  (1x^9) == ";
    Polynomial p = Polynomial();
    p.reserve(9);
    p.assign_coef(1.0, 9);
    p.print();
    cout << "Outcome: ";
    cout << p.eval(3) << " == " << 19683 << " ";
    if(std::fabs(p.eval(3) - 19683) < __DBL_EPSILON__){
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}

void testPolynomialCreation3(){
    cout << "Testing Polynomail Creation:" << endl;
    cout << "Attempting to build the following:" << endl;
    cout << "Test 3:  (3x^5) - (4.3x^4) - (2x) + (7) == ";
    Polynomial p = Polynomial(7, -2, 0, 0, -4.3, 3);
    p.print();
    cout << "Outcome: ";
    cout << p.eval(1.2) << " == " << 3.14848 << " ";
    if(std::fabs(p.eval(1.2) == 3.14848) < __DBL_EPSILON__){
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}
