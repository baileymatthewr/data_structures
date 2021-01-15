#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <cstdlib>

namespace polynomial_h {
    class Polynomial {
    public:
        Polynomial();
        Polynomial(double a0);
        Polynomial(const Polynomial& source);
        Polynomial(double);
        ~Polynomial(){ delete coefficients; }

        void add_to_coef(double amount, unsigned int k);
        void assign_coef(double new_coefficient, unsigned int k);
        void clear();
        void reserve(size_t number);
        double eval(double x) const;
        double operator()(double x) const;

        Polynomial& operator =(const Polynomial& source);
        Polynomial& operator =(double a0);
        Polynomial operator+(const Polynomial& p);
        Polynomial operator-(const Polynomial& p);
        Polynomial operator*(const Polynomial& p);

        double coefficient(unsigned int k) const;
        unsigned int degree() const;
        unsigned int next_term(unsigned int k) const;

    private:
        double *coefficients;
        unsigned int degree;
    };
}
#endif
