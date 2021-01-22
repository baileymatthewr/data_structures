#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include "polynomial.h"

using namespace std;
using namespace polynomial_h;

// Function Prototypes
bool areEquals(double x, double y);
void testPolynomialCreation1();
void testPolynomialCreation2();
void testPolynomialCreation3();

void testPolynomailAddition1();
void testPolynomailAddition2();
void testPolynomailSubtraction1();
void testPolynomailSubtraction2();

// Main
int main(int argc, char* argv[]){
    testPolynomialCreation1();
    testPolynomialCreation2();
    testPolynomialCreation3();

    testPolynomailAddition1();
    testPolynomailAddition2();
    testPolynomailSubtraction1();
    testPolynomailSubtraction2();
    return EXIT_SUCCESS;
}


//--------------------- Function Definitions ------------------
bool areEquals(double x, double y){
    return std::fabs(x - y) > __DBL_EPSILON__;
}

void testPolynomialCreation1(){
    cout << "Test Creation 1:" << endl;
    cout << "(4) == ";
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
    cout << "Test Creation 2:" << endl;
    cout << "(1x^9) == ";
    Polynomial p = Polynomial();
    p.reserve(9);
    p.assign_coef(1.0, 9);
    p.print();
    cout << "Outcome: ";
    cout << p.eval(3) << " == " << 19683 << " ";
    if(p.eval(3) == 19683){
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}

void testPolynomialCreation3(){
    cout << "Test Creation 3:" << endl;
    cout << "(3x^5) - (4.3x^4) - (2x) + (7) == ";
    Polynomial p = Polynomial(7, -2, 0, 0, -4.3, 3);
    p.print();
    cout << "Outcome: ";
    cout << p.eval(1.2) << " == " << 3.14848 << " ";
    if(areEquals(p.eval(1.2), 3.14848)){
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}

void testPolynomailAddition1(){
    cout << "Test Addition 1:" << endl;
    cout << "(2x^4 + 3x^3 + 1x) + (4x^3 + 2x^2 - 8) => 2x^4 + 7x^3 + 2x^2 + x - 8" << endl;
    cout << "====================================================================" << endl;
    cout << " 2x^4 + 7x^3 + 2x^2 + x - 8 == ";
    Polynomial p = Polynomial(0, 1, 0, 3, 2);
    Polynomial q = Polynomial(-8, 0, 2, 4);
    Polynomial x = p + q;
    x.print();
    if(x.eval(1.5) == 31.75){
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}

void testPolynomailAddition2(){
    cout << "Test Addition 2:" << endl;
    cout << "(x^5 + 5x^3 + 2x) + (4x^3 - 2x^2 + 8) => x^5 + 9x^3 - 2x^2 + 2x + 8" << endl;
    cout << "====================================================================" << endl;
    cout << " x^5 + 9x^3 - 2x^2 + 2x + 8 == ";
    Polynomial p = Polynomial(0, 2, 0, 5, 0, 1);
    Polynomial q = Polynomial(8, 0, -2, 4);
    Polynomial x = p + q;
    x.print();
    if(x.eval(1.5) == 44.46875){
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}


void testPolynomailSubtraction1(){
    cout << "Test Subtraction 1:" << endl;
    cout << "(2x^4 + 7x^3 + 2x^2 + x - 8) - (2x^4 + 3x^3 + 1x) => (4x^3 + 2x^2 - 8)" << endl;
    cout << "====================================================================" << endl;
    cout << " (4x^3 + 2x^2 - 8) == ";
    Polynomial p = Polynomial(-8, 1, 2, 7, 2);
    Polynomial q = Polynomial(0, 1, 0, 3, 2);
    Polynomial x = p - q;
    x.print();
    if(x.eval(1.5) == 10){
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}

void testPolynomailSubtraction2(){
    cout << "Test Subtraction 2:" << endl;
    cout << "(x^5 + 9x^3 - 2x^2 + 2x + 8) - (x^5 + 5x^3 + 2x) => (4x^3 - 2x^2 + 8)" << endl;
    cout << "====================================================================" << endl;
    cout << "(4x^3 - 2x^2 + 8) == ";
    Polynomial p = Polynomial(8, 2, -2, 9, 0, 1);
    Polynomial q = Polynomial(0, 2, 0, 5, 0, 1);
    Polynomial x = p - q;
    x.print();
    if(x.eval(1.5) == 17){
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}