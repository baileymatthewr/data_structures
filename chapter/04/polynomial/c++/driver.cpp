#include<iostream>
#include<cstdlib>
#include<cassert>
#include "polynomial.h"

using namespace std;
using namespace polynomial_h;

void testPolynomialCreation1();
void testPolynomialCreation2();

int main(int argc, char* argv[]){
    testPolynomialCreation1();
    testPolynomialCreation2();
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
    cout << p.eval(3) << " == " << 19683.0 << " ";
    if(p.eval(3) == 19683.0){
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}