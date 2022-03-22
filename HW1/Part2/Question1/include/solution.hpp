//solution.hpp
#include <solution.h>
#include <cstdlib>

template <typename CoefType, typename ExpType>
void Polynomial<CoefType, ExpType>::SetTermArray(const Term<CoefType, ExpType>* const in_term_array, const int &in_terms){
    if(terms != in_terms){
        throw std::runtime_error(std::string("Error: the size of in_term_array does not match with the term_array inside the Polunomial."));
        //exit(0);
    }
    for(int i=0;i<terms;++i){
        term_array[i] = in_term_array[i];
    }
}

template <typename CoefType, typename ExpType>
void Polynomial<CoefType, ExpType>::NewTerm(const CoefType &in_coef, const ExpType &in_exp){
    if(terms == capacity){
        capacity *= 2;
        Term<CoefType, ExpType> *temp = new Term<CoefType, ExpType> [capacity];
        std::copy(term_array, term_array+terms, temp);
        delete [] term_array;
        term_array = temp;
    }

    term_array[terms].coef = in_coef;
    term_array[terms].exp  = in_exp;
    terms++;
}

template <typename CoefType, typename ExpType>
void Polynomial<CoefType, ExpType>::operator=(const Polynomial &other){
    if(capacity > 0){
        delete [] term_array;
    }

    terms    = other.terms;
    capacity = other.capacity;
    max_exp  = other.max_exp;
    input_at_least_once = other.input_at_least_once;

    Term<CoefType, ExpType> *temp = new Term<CoefType, ExpType> [capacity];
    for(int i=0;i<terms;++i){
        temp[i] = other.term_array[i];
    }

    term_array = temp;
}

template <typename CoefType, typename ExpType>
Polynomial<CoefType, ExpType> Polynomial<CoefType, ExpType>::Add(Polynomial b){
    Polynomial<CoefType, ExpType> c(0, 10, "temp_result");
    int aPos = 0;
    int bPos = 0;

    while((aPos<terms) && (bPos<b.terms)){
        if(term_array[aPos].exp == b.term_array[bPos].exp){
            CoefType t = term_array[aPos].coef + b.term_array[bPos].coef;
            c.NewTerm(t, term_array[aPos].exp);
            aPos++;
            bPos++;
        }else if(term_array[aPos].exp < b.term_array[bPos].exp){
            c.NewTerm(b.term_array[bPos].coef, b.term_array[bPos].exp);
            bPos++;
        }else{
            c.NewTerm(term_array[aPos].coef, term_array[aPos].exp);
            aPos++;
        }
    }

    for(int i=aPos;i<terms;++i){
        c.NewTerm(term_array[i].coef, term_array[i].exp);
    }
    for(int i=bPos;i<b.terms;++i){
        c.NewTerm(b.term_array[i].coef, b.term_array[i].exp);
    }

    try {c.FindLeadExp();}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    return c;
}

template <typename CoefType, typename ExpType>
void Polynomial<CoefType, ExpType>::FindLeadExp(){
    ExpType tmp;

    if(terms == 0){
        throw std::runtime_error(std::string("Error: There is no term in the current Polynomial."));
        //exit(0);
    }

    for(int i=0;i<terms;++i){
        if(i==0){
            tmp = term_array[i].exp;
        }else{
            if(tmp < term_array[i].exp){
                tmp = term_array[i].exp;
            }
        }
    }

    max_exp = tmp;
}

template <typename CoefType, typename ExpType>
Polynomial<CoefType, ExpType> Polynomial<CoefType, ExpType>::Mult(Polynomial b){

}

template <typename CoefType, typename ExpType>
CoefType Polynomial<CoefType, ExpType>::Coef(ExpType e){
    CoefType tmp;
    bool found = false;
    for(int i=0;i<terms;++i){
        if(term_array[i].exp == e){
            found = true;
            tmp = term_array[i].coef;
            break;
        }
    }

    if(found){
        return tmp;
    }else{
        throw std::runtime_error(std::string("Error: No terms in the current Polynomial has the matched exponential."));
        //exit(0);
    }
}
