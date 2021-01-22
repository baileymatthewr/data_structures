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
        Polynomial(double a0, double a1=0.0, double a2=0.0, double a3=0.0, double a4=0.0, double a5=0.0);
        Polynomial(const Polynomial& source);
        ~Polynomial(){ delete _coefficients; }

        
        void add_to_coef(double amount, unsigned int k);
        void sub_to_coef(double amount, unsigned int k);
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
                Polynomial q = Polynomial(*this);
                for(size_t i = 0; i <= q.degree(); ++i){
                    if(i <= p.degree())
                        q.add_to_coef(p.coefficient(i), i);
                }
                q.correctDegree();
                return q;
            } else {
                Polynomial q = Polynomial(p);
                for(size_t i = 0; i <= q.degree(); ++i){
                    if(i <= _degree)
                        q.add_to_coef(_coefficients[i], i);
                }
                q.correctDegree();
                return q;
            }
        }

        Polynomial operator-(const Polynomial& p) const {
            Polynomial q = Polynomial(*this);
            unsigned int amt = (_degree > p.degree()) ? _degree : p.degree();
            q.reserve(amt);
            for(size_t i = 0; i <= q.degree(); ++i){
                if(i <= p.degree())
                    q.sub_to_coef(p.coefficient(i), i);
            }
            q.correctDegree();
            return q;
        }

        Polynomial operator*(const Polynomial& p) const {
            Polynomial q = Polynomial();
            q.reserve(p.degree() * _degree);
            //FOIL - FIRST + OUTSIDE + INSIDE + LAST
            for(size_t i = 0; i <= _degree; ++i){
                for(size_t j = 0; j <= p.degree(); ++j){
                    size_t k = i + j;
                    double tmp = _coefficients[i] * p.coefficient(j);
                    q.add_to_coef(tmp, k);
                }
            }
            q.correctDegree();
            return q;
        }

        double coefficient(unsigned int k) const;
        unsigned int degree() const;
        unsigned int next_term(unsigned int k) const;
        void print() const;
        void correctDegree();
    };
}
#endif
