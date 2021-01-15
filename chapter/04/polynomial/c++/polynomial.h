#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <cstdlib>
#include <stdexcept>

namespace polynomial_h {
    class Polynomial {
    private:
        double *_coefficients;
        unsigned int _degree;
    public:
        Polynomial();
        Polynomial(double a0);
        Polynomial(const Polynomial& source);
        ~Polynomial(){ delete _coefficients; }

        void add_to_coef(double amount, unsigned int k);
        void assign_coef(double new_coefficient, unsigned int k);
        void clear();
        void reserve(size_t number);
        double eval(double x) const;
        double operator()(double x) const {
            return this->eval(x);
        }

        Polynomial& operator=(const Polynomial& source){
            if(&source == this)
                throw std::runtime_error(std::string("Assignment Failure"));
            return *this;
        }

        Polynomial& operator=(double a0){
            this->clear();
            _coefficients[0] = a0;
            return *this;
        }

        Polynomial operator+(const Polynomial& p) const {
            if(_degree > p.degree()){
                Polynomial q = new Polynomial(this);
                for(size_t i = 0; i <= q.degree(); ++i){
                    if(i <= p.degree())
                        q.add_to_coef(p.coefficient(i), i);
                }
                return q;
            } else {
                Polynomial q = new Polynomial(p);
                for(size_t i = 0; i <= q.degree(); ++i){
                    if(i <= _degree)
                        q.add_to_coef(_coefficient[i], i);
                }
                return q;
            }
        }

        Polynomial operator-(const Polynomial& p) const {
            Polynomial q = new Polynomial(this);
            for(size_t i = 0; i <= q.degree(); ++i){
                if(i <= p.degree())
                    q.add_to_coef((1 - p.coefficient(i)), i);
            }
            return q;
        }

        Polynomial operator*(const Polynomial& p) const {
            //FOIL - FIRST, OUTSIDE, INSIDE, LAST
        }

        double coefficient(unsigned int k) const;
        unsigned int degree() const;
        unsigned int next_term(unsigned int k) const;
    };
}
#endif
