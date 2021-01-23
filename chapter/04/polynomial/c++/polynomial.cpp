#include <algorithm>
#include <iostream>
#include <cassert>
#include <math.h>
#include "polynomial.h"


using namespace std;

namespace polynomial_h {

    Polynomial::Polynomial(){
        // creates a polynomial with all zero coefficients
        _degree = 0;
        _coefficients = new double[_degree + 1];
        _coefficients[0] = 0.0;
    }

    Polynomial::Polynomial(double a0, double a1, double a2, double a3, double a4, double a5){
        // This mostly exists as a quick way to create a Polynomial to test
        // if other arithmetic methods work properly.
        if(a5 != 0){
            _degree = 5;
            _coefficients = new double[_degree + 1];
            _coefficients[0] = a0;
            _coefficients[1] = a1;
            _coefficients[2] = a2;
            _coefficients[3] = a3;
            _coefficients[4] = a4;
            _coefficients[5] = a5;
        } else if(a4 != 0){
            _degree = 4;
            _coefficients = new double[_degree + 1];
            _coefficients[0] = a0;
            _coefficients[1] = a1;
            _coefficients[2] = a2;
            _coefficients[3] = a3;
            _coefficients[4] = a4;
        } else if(a3 != 0){
            _degree = 3;
            _coefficients = new double[_degree + 1];
            _coefficients[0] = a0;
            _coefficients[1] = a1;
            _coefficients[2] = a2;
            _coefficients[3] = a3;
        } else if(a2 != 0){
            _degree = 2;
            _coefficients = new double[_degree + 1];
            _coefficients[0] = a0;
            _coefficients[1] = a1;
            _coefficients[2] = a2;
        } else if(a1 != 0){
            _degree = 1;
            _coefficients = new double[_degree + 1];
            _coefficients[0] = a0;
            _coefficients[1] = a1;
        } else {
            _degree = 0;
            _coefficients = new double[_degree + 1];
            _coefficients[0] = a0;
        }
    }

    Polynomial::Polynomial(const Polynomial& source){
        _degree = source.degree();
        size_t count = _degree + 1;
        _coefficients = new double[count];
        for(size_t i = 0; i < count; ++i)
            _coefficients[i] = source.coefficient(i);
    }

    void Polynomial::add_to_coef(double amount, unsigned int k){
        _coefficients[k] += amount;
    }

    void Polynomial::sub_to_coef(double amount, unsigned int k){
        _coefficients[k] -= amount;
    }

    void Polynomial::assign_coef(double new_coefficient, unsigned int k){
        _coefficients[k] = new_coefficient;
    }

    void Polynomial::clear(){
        // sets all coefficients to 0
        unsigned int count = _degree + 1;
        for(size_t i = 0; i < count; ++i)
            _coefficients[i] = 0;
        _degree = 0;
    }

    void Polynomial::reserve(size_t number){
        size_t degree = _degree;
        if(number > _degree){
            double *old_coefficients = _coefficients;
            _coefficients = new double[number + 1];
            for(size_t i = 0; i <= degree; ++i)
                _coefficients[i] = old_coefficients[i];
            for(size_t i = degree; i <= number; ++i)
                _coefficients[i] = 0;
            delete old_coefficients;
        }
        _degree = number;
    }

    double Polynomial::eval(double x) const {
        double output = 0.00;
        for(size_t i = 0; i <= _degree; ++i)
            output += _coefficients[i] * pow(x, i);
        return output;
    }

    double Polynomial::coefficient(unsigned int k) const {
        return _coefficients[k];
    }

    unsigned int Polynomial::degree() const {
        return _degree;
    }

    unsigned int Polynomial::next_term(unsigned int k) const {
        unsigned int output = UINT_MAX;
        for(size_t i = k; i <= _degree; ++i){
            if(_coefficients[i] != 0.0){
                output = i;
                break;
            }
        }
        return output;
    }

    void Polynomial::print() const {
        bool first = true;
        double val = 0.00;
        cout << "(";
        for(int i = _degree; i >= 0; --i){
            val = _coefficients[i];
            if(first){
                cout << val;
                if(i > 1)
                    cout << "x^" << i;
                else if(i == 1)
                    cout << "x";
                first = false;
            } else {
                if(val == 0){
                    //skip it
                } else {
                    if(val < 0)
                        cout << " - ";
                    else
                        cout << " + ";
                    cout << abs(val);

                    if(i > 1)
                        cout << "x^" << i;
                    else if(i == 1)
                        cout << "x";
                    else {
                        break;
                    }
                }
            }
        }
        cout << ")" << endl;
    }

    void Polynomial::correctDegree(){
        for(size_t i = _degree; i >= 0; --i){
            if(_coefficients[i] == 0){
                --_degree;
            } else {
                break;
            }
        }
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
    if(p.eval(27) == 4.0)
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
}

void testPolynomialCreation2(){
    cout << "Test Creation 2:" << endl;
    cout << "(1x^9) == ";
    Polynomial p = Polynomial();
    p.reserve(9);
    p.assign_coef(1.0, 9);
    p.print();
    if(p.eval(3) == 19683)
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
}

void testPolynomialCreation3(){
    cout << "Test Creation 3:" << endl;
    cout << "(3x^5 - 4.3x^4 - 2x + 7) == ";
    Polynomial p = Polynomial(7, -2, 0, 0, -4.3, 3);
    p.print();
    if(areEquals(p.eval(1.2), 3.14848))
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
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
    if(x.eval(1.5) == 31.75)
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
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
    if(x.eval(1.5) == 44.46875)
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
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
    if(x.eval(1.5) == 10)
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
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
    if(x.eval(1.5) == 17)
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
}

}
