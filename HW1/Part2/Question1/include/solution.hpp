//solution.hpp
#include <solution.h>
#include <cstdlib>

template <typename CoefType, typename ExpType>
void Polynomial<CoefType, ExpType>::SetTermArray(const Term<CoefType, ExpType>* const in_term_array, const int &in_terms){
    if(terms != in_terms){
        throw std::runtime_error(std::string("Error: the size of in_term_array does not match with the term_array inside the Polunomial."));
        exit(0);
    }
    for(int i=0;i<terms;++i){
        term_array[i] = in_term_array[i];
    }
}

template <typename CoefType, typename ExpType>
void Polynomial<CoefType, ExpType>::NewTerm(const CoefType &in_coef, const ExpType &in_exp){
    if(terms == capcaity){
        capcaity *= 2;
        Term<CoefType, ExpType> *temp = new Term<CoefType, ExpType> [capcaity];
        std::copy(term_array, term_array+terms, temp);
        delete [] term_array;
        term_array = temp;
    }

    term_array[terms].coef = in_coef;
    term_array[terms].exp  = in_exp;
    terms++;
}

/*
template <typename CoefType, typename ExpType>
std::ostream & operator<<<>(std::ostream &os, const Polynomial<CoefType, ExpType> &out_polynomial){
    os<<"The Polynomial is :"<<std::endl;
    for(int i=0;i<out_polynomial.terms;++i){
        if(i==out_polynomial.terms-1){
            os<<out_polynomial.term_array[i].coef<<"X^"<<out_polynomial.term_array[i].exp<<std::endl;
        }else{
            if(i==0){
                if(out_polynomial.term_array[i+1].coef > 0){
                    os<<out_polynomial.term_array[i].coef<<"X^"<<out_polynomial.term_array[i].exp<<"+";
                }else{
                    os<<out_polynomial.term_array[i].coef<<"X^"<<out_polynomial.term_array[i].exp<<"-";
                }
            }else{
                if(out_polynomial.term_array[i+1].coef > 0){
                    os<<abs(out_polynomial.term_array[i].coef)<<"X^"<<out_polynomial.term_array[i].exp<<"+";
                }else{
                    os<<abs(out_polynomial.term_array[i].coef)<<"X^"<<out_polynomial.term_array[i].exp<<"-";
                }
            }
        }
    }
    return os;
}
*/

/*
template <typename CoefType, typename ExpType>
std::istream & operator>><>(std::istream &in, Polynomial<CoefType, ExpType> &in_polunomial){
    Term<CoefType, ExpType> temp;
    std::cout<<"Please enter the coefficient : ";
    in>> temp.coef;
    std::cout<<"Please enter the exponential : ";
    in>> temp.exp;

    if(temp.coef == 0){
        std::cout<<"Warning: The coefficient you just entered is 0, which will not be taken into the Polynomial."<<std::endl;
        return in;
    }

    NewTerm(temp.coef, temp.exp);
    return in;
}
*/
