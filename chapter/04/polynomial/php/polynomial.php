<?php

namespace polynomial_h {
    class Polynomial {
        public $_coefficients; // Array
        public $_degree = 0;
        private function __construct(){
            $this->_coefficients = [];
        }

        public static function createByValue($a0, $a1=0.0, $a2=0.0, $a3=0.0, $a4=0.0, $a5=0.0){
            //Do something
            $p = self::__construct();
            for($i = 0; $i < 6; ++$i){
                $var = 'a'.$i;
                if($$var != 0){
                    ++$p->_degree;
                    $p->_coefficients[$i] == $$var;
                }
            }
            return $p;
        }

        public static function createByPoly($q){
            $p = self::__construct();
            $p->_degree = $q->_degree;
            for($i = 0; $i < ($q->_degree + 1); ++$i){
                $p->_coefficients[$i] = $q->_coefficients[$i];
            }
            return $p;
        }

        public function __destruct(){
            unset($this->_coefficients);
            unset($this->_degree);
        }
    
        public function add_to_coef($amt, $k){
            $this->_coefficients[$k] += $amt;
        }
        
        public function sub_to_coef($amt, $k){
            $this->_coefficients[$k] -= $amt;
        }

        public function assign_coef($new_coef, $k){
            $this->_coefficients[$k] = $new_coef;
        }

        public function clear(){
            unset($this->_coefficients);
            $this->_coefficients = [0.0];
            $this->_degree = 0;
        }

        public function eval($x){
            $output = 0.00;
            for($i = 0; $i <= $this->_degree; ++$i)
                $output += $this->_coefficients[$i] * pow($x, $i);
            return output;
        }
        
        /*
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
        */
        public function coefficient($k){
            return $this->_coefficients[$k];
        }

        public function degree(){
            return $this->_degree;
        }

        public function next_term($k){
            $output = PHP_INT_MAX;
            for($i = $k; $i <= $this->_degree; ++$i){
                if($this->_coefficients[$i] != 0.0){
                    $output = $i;
                    break;
                }
            }
            return $output;
        }

        public function print(){
            $first = true;
            $val = 0.00;
            echo "(";
            for($i = $this->_degree; $i >= 0; --$i){
                $val = $this->_coefficients[$i];
                if($first){
                    echo "$val";
                    if($i > 1)
                        echo "x^$i";
                    else if($i == 1)
                        echo "x";
                    $first = false;
                } else {
                    if($val == 0){
                        //skip it
                    } else {
                        if($val < 0)
                            echo " - ";
                        else
                            echo " + ";
                        echo abs($val);

                        if($i > 1)
                            echo "x^$i";
                        else if($i == 1)
                            echo "x";
                        else {
                            break;
                        }
                    }
                }
            }
            echo ")\n";
        }

        public function correctDegree(){
            for($i = $this->_degree; $i >= 0; --$i){
                if($this->_coefficients[$i] == 0){
                    --$this->_degree;
                } else {
                    break;
                }
            }
        }
    };
    
    // Function Prototypes for Library
    function areEquals($x, $y){

    }

    function testPolynomialCreation(){

    }

    function testPolynomialAddition(){

    }

    function testPolynomialSubtraction(){

    }

    function testPolynomialMultiplication(){

    }

}
