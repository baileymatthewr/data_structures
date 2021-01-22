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
        for(size_t i = _degree; i >= 0; --i){
            cout << "(" << _coefficients[i];
            if(i > 1){
                cout << "x^" << i; 
            } else if(i == 1){
                cout << "x";
            }
            cout << ")";
            if(i == 0){
                cout << endl;
                break;
            } else {
                cout << " + ";
            }
        }
    }

    void Polynomial::correctDegree(){
        while(_degree > 0){
            if(_coefficients[_degree] == 0){
                _degree = _degree - 1;
            } else {
                break;
            }
        }
    }
}
