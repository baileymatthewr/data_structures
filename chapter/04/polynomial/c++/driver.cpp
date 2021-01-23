#include<iostream>
#include<cstdlib>
#include<cassert>

#include "polynomial.h"

using namespace std;
using namespace polynomial_h;

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
