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
        temp = nullptr;
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
    temp = nullptr;
}

template <typename CoefType, typename ExpType>
Polynomial<CoefType, ExpType> Polynomial<CoefType, ExpType>::Add(Polynomial b){
    if(terms == 0 && b.terms == 0){
        throw std::runtime_error(std::string("Error: all the input Polynomial of Add() are empty."));
    }

    Polynomial<CoefType, ExpType> c(0, 10, "temp_result");
    int aPos = 0;
    int bPos = 0;

    //Reset c to remove 0 term because of the default constructor.
    if(c.terms > 0){
        c.terms = 0;
        delete [] c.term_array;
        Term<CoefType, ExpType> *temp = new Term<CoefType, ExpType> [c.capacity];
        c.term_array = temp;
        temp = nullptr;
    }

    //Begin the algorithm
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
        throw std::runtime_error(std::string("Error: Not available. The Polynomial is empty."));
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
bool Polynomial<CoefType, ExpType>::SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b){
    return (a.exp > b.exp);
}

template <typename CoefType, typename ExpType>
Polynomial<CoefType, ExpType> Polynomial<CoefType, ExpType>::Mult(Polynomial b){
    if(terms == 0 && b.terms == 0){
        throw std::runtime_error(std::string("Error: all the input Polynomial of Mult() are empty."));
    }

    Polynomial<CoefType, ExpType> c(0, 10, "temp_result");
    std::unordered_map<ExpType, int> map_exp2pos; //to record the exp stored in which position in c

    //Reset c to remove 0 term because of the default constructor.
    if(c.terms > 0){
        c.terms = 0;
        delete [] c.term_array;
        Term<CoefType, ExpType> *temp = new Term<CoefType, ExpType> [c.capacity];
        c.term_array = temp;
        temp = nullptr;
    }

    for(int i=0;i<terms;++i){
        for(int j=0;j<b.terms;++j){
            ExpType exp_result   = term_array[i].exp + b.term_array[j].exp;
            CoefType coef_result = term_array[i].coef * b.term_array[j].coef;

            if(map_exp2pos.find(exp_result) == map_exp2pos.end()){//not found
                map_exp2pos[exp_result] = c.terms;
                c.NewTerm(coef_result, exp_result);
            }else{
                c.term_array[map_exp2pos[exp_result]].coef += coef_result;
            }
        }
    }

    std::sort(c.term_array, c.term_array+c.terms, c.SortFunction);
    try {c.FindLeadExp();}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    return c;
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

template <typename CoefType, typename ExpType>
float Polynomial<CoefType, ExpType>::Eval(float f){
    if(terms == 0){
        throw std::runtime_error(std::string("Error: Not available. The Polynomial is empty."));
    }

    float tmp_sum = 0;
    for(int i=0;i<terms;++i){
        ExpType pow_term = term_array[i].exp;
        tmp_sum += term_array[i].coef*pow(f, (double)pow_term);
    }

    return tmp_sum;
}
