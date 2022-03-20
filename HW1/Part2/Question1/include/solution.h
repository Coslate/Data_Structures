#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
#include <string>
#include <iostream>

template <typename CoefType, typename ExpType>
class Polynomial;//forward declaration

template <typename CoefType, typename ExpType>
class Term{
    private:
        CoefType coef;
        ExpType  exp;

    public:
        Matrix() : coef(0), exp(0){}
        Matrix(const CoefType &coef, const ExpType &exp) : coef(coef), exp(exp){}

        //Copy consturctor
        Matrix(const Matrix &p){
            coef = p.coef;
            exp  = p.exp;
        }
        ~Matrix(){}
        friend class Polynomial<T>;

};

template <typename CoefType, typename ExpType>
class Polynomial{
    private:
        Term* term_array;
        int   terms;//the number of non-zero terms
        int   capcaity; //the max-size of term_array
    public:
        Polynomial(const int &terms=0, const int &capcaity=10):terms(terms), capcaity(capcaity){
            term_array = new Term [capcaity];
        }

        //Copy consturctor
        Polynomial(const Polynomial &p){
            terms    = p.terms;
            capcaity = p.capcaity;
            for(int i=0;i<terms;++i){
                term_array[i] = p.term_array[i];
            }
        }

        //Destructor
        ~Polynomial(){
            delete [] term_array;
        }

        int             GetTerms()    const {return terms;}
        int             GetCapacity() const {return capcaity;}
        Term*           GetTermArray()const {return term_array;}
        void            SetTerms    (const int &in_terms)          {terms = in_terms;}
        void            SetCapacity (const int &in_caacity)        {capcaity = in_caacity;}
        void            SetTermArray(const Term* const in_term_array, const int &in_terms) {
                            if(terms != size){
                                throw std::runtime_error(std::string("Error: the size of in_term_array does not equal to the term_array inside the Polunomial."));
                                exit(0);
                                
                            }

                            for(int i=0;i<terms;++i){
                                term_array[i] = in_term_array[i];
                            }
                        }

        void operator=(const Complex_Matrix &Polynomial);

};

#include <solution.hpp>
#endif

