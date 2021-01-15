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

    Polynomial::Polynomial(double a0){
        // creates a polynomial with the specified parameter as the coefficient
        // of the x^0 term
        _degree = 0;
        _coefficients = new double[_degree + 1];
        _coefficients[0] = a0;
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
        if(number > _degree){
            unsigned int count = _degree + 1;
            double *old_coefficients = _coefficients;
            _coefficients = new double[number];
            for(size_t i = 0; i < count; ++i)
                _coefficients[i] = old_coefficients[i];
            delete old_coefficients;
        }
    }

    double Polynomial::eval(double x) const {
        double output = 0.00;
        unsigned int count = _degree + 1;
        for(size_t i = 0; i < count; ++i)
            output += _coefficients[i] * pow(x, i);
        return output;
    }

    double Polynomial::coefficient(unsigned int k) const {
        return *(_coefficients + k);
    }

    unsigned int Polynomial::degree() const {
        return _degree;
    }

    unsigned int Polynomial::next_term(unsigned int k) const {
        unsigned int output = UINT_MAX;
        unsigned int count = _degree + 1;
        for(size_t i = k; i < count; ++i){
            if(_coefficients[i] != 0.0){
                output = i;
                break;
            }
        }
        return output;
    }
}
