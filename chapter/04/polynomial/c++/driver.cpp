#include<iostream>
#include<cstdlib>
#include<cassert>

#include "polynomial.h"

using namespace std;
using namespace polynomial_h;

// Main
int main(int argc, char* argv[]){
    cout << "CREATION" << endl;
    testPolynomialCreation1();
    testPolynomialCreation2();
    testPolynomialCreation3();
    cout << "\n\n===============" << endl;
    cout << "===============" << endl;
    cout << "ADDITION" << endl;
    testPolynomialAddition1();
    testPolynomialAddition2();
    cout << "\n\n===============" << endl;
    cout << "===============" << endl;
    cout << "SUBTRACTION" << endl;
    testPolynomialSubtraction1();
    testPolynomialSubtraction2();
    cout << "\n\n===============" << endl;
    cout << "===============" << endl;
    cout << "MULTIPLICATION" << endl;
    testPolynomialMultiplication1();
    testPolynomialMultiplication2();
    return EXIT_SUCCESS;
}
