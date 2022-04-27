#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>

template <typename CoefType, typename ExpType>
class Polynomial;//forward declaration

template <typename CoefType, typename ExpType>
class Term{
    private:
        CoefType coef;
        ExpType  exp;

    public:
        Term() : coef(0), exp(0){}
        Term(const CoefType &coef, const ExpType &exp) : coef(coef), exp(exp){}

        //Copy consturctor
        Term(const Term &p){
            coef = p.coef;
            exp  = p.exp;
        }

        void SetCoef(const CoefType &in_coef){coef = in_coef;}
        void SetExp (const ExpType  &in_exp) {exp = in_exp;}
        CoefType GetCoef() const {return coef;}
        ExpType  GetExp () const {return exp; }
        void operator=(const Term &in_term){
            coef = in_term.coef;
            exp  = in_term.exp;
        }

        //Destructor
        ~Term(){}
        friend class Polynomial<CoefType, ExpType>;

};

template <typename CoefType, typename ExpType>
class Polynomial{
    private:
        Term<CoefType, ExpType>* term_array;
        int         terms;    //the number of non-zero terms
        int         capacity; //the max-size of term_array
        std::string name;
        ExpType     max_exp;  //record the largest exponential among the terms of the polynomial
        bool        input_at_least_once; //record whether the first time use >> input

        void        FindLeadExp    ();//Determine the max_exp
    public:
        Polynomial(const int &terms=0, const int &capacity=10, const std::string &name="NULL", const ExpType &max_exp=0, const bool &input_at_least_once = false):terms(terms), capacity(capacity), name(name), max_exp(max_exp), input_at_least_once(input_at_least_once){
            term_array = new Term<CoefType, ExpType> [capacity];
            NewTerm(0, 0);
        }

        //Copy consturctor
        Polynomial(const Polynomial &p){
            terms    = p.terms;
            capacity = p.capacity;
            name     = p.name;
            max_exp  = p.max_exp;
            input_at_least_once = p.input_at_least_once;
            term_array = new Term<CoefType, ExpType> [capacity];

            for(int i=0;i<terms;++i){
                term_array[i] = p.term_array[i];
            }
        }

        //Destructor
        ~Polynomial(){
            delete [] term_array;
            term_array = nullptr;
        }

        int                                GetTerms            () const {return terms;}
        int                                GetCapacity         () const {return capacity;}
        std::string                        GetName             () const {return name;}
        Term<CoefType, ExpType>*           GetTermArray        () const {return term_array;}
        void                               SetTerms            (const int &in_terms)          {terms    = in_terms;}
        void                               SetCapacity         (const int &in_capacity)        {capacity = in_capacity;}
        void                               SetName             (const std::string &in_name)   {name     = in_name;}
        void                               SetTermArray        (const Term<CoefType, ExpType>* const in_term_array, const int &in_terms);
        void                               NewTerm             (const CoefType &in_coef, const ExpType &in_exp);

        Polynomial      Add                 (Polynomial b);
        Polynomial      Mult                (Polynomial b);
        float           Eval                (float f);
        int             operator!           (){return (((terms==1) && (term_array[0].coef==0))?1:0);}
        CoefType        Coef                (ExpType e);
        ExpType         LeadExp             (){if(terms==0){throw std::runtime_error(std::string("Error: Not available. The Polynomial is empty."));} return max_exp;}

        static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);

        void operator=(const Polynomial &polynomial);

        friend std::ostream & operator<<(std::ostream &os, const Polynomial<CoefType, ExpType> &out_polynomial){
            if(out_polynomial.terms == 0){
                throw std::runtime_error(std::string("Error: Not available. The Polynomial is empty."));
                return os;
            }
            for(int i=0;i<out_polynomial.terms;++i){
                if(i==out_polynomial.terms-1){
                    if(i==0){
                        if(out_polynomial.term_array[i].GetExp()!=0){
                            os<<out_polynomial.term_array[i].GetCoef()<<"X^"<<out_polynomial.term_array[i].GetExp()<<std::endl;
                        }else{
                            os<<out_polynomial.term_array[i].GetCoef()<<std::endl;
                        }
                    }else{
                        if(out_polynomial.term_array[i].GetExp()!=0){
                            os<<abs(out_polynomial.term_array[i].GetCoef())<<"X^"<<out_polynomial.term_array[i].GetExp()<<std::endl;
                        }else{
                            os<<abs(out_polynomial.term_array[i].GetCoef())<<std::endl;
                        }
                    }
                }else{
                    if(i==0){
                        if(out_polynomial.term_array[i+1].GetCoef() > 0){
                            if(out_polynomial.term_array[i].GetExp()!=0){
                                os<<out_polynomial.term_array[i].GetCoef()<<"X^"<<out_polynomial.term_array[i].GetExp()<<"+";
                            }else{
                                os<<out_polynomial.term_array[i].GetCoef()<<"+";
                            }
                        }else{
                            if(out_polynomial.term_array[i].GetExp()!=0){
                                os<<out_polynomial.term_array[i].GetCoef()<<"X^"<<out_polynomial.term_array[i].GetExp()<<"-";
                            }else{
                                os<<out_polynomial.term_array[i].GetCoef()<<"-";
                            }
                        }
                    }else{
                        if(out_polynomial.term_array[i+1].GetCoef() > 0){
                            if(out_polynomial.term_array[i].GetExp()!=0){
                                os<<abs(out_polynomial.term_array[i].GetCoef())<<"X^"<<out_polynomial.term_array[i].GetExp()<<"+";
                            }else{
                                os<<abs(out_polynomial.term_array[i].GetCoef())<<"+";
                            }
                        }else{
                            if(out_polynomial.term_array[i].GetExp()!=0){
                                os<<abs(out_polynomial.term_array[i].GetCoef())<<"X^"<<out_polynomial.term_array[i].GetExp()<<"-";
                            }else{
                                os<<abs(out_polynomial.term_array[i].GetCoef())<<"-";
                            }
                        }
                    }
                }
            }

            return os;
        }
        friend std::istream & operator>>(std::istream &in, Polynomial<CoefType, ExpType> &in_polynomial){
            CoefType temp_coef;
            ExpType  temp_exp;

            std::cout<<"Please enter the coefficient for "<<in_polynomial.name<<" : ";
            in>> temp_coef;
            std::cout<<"Please enter the exponential for "<<in_polynomial.name<<" : ";
            in>> temp_exp;

            if(temp_coef == 0){
                std::cout<<"Warning: The coefficient you just entered is 0, which will not be taken into the Polynomial."<<std::endl;
                return in;
            }

            if((temp_exp > in_polynomial.max_exp) && (in_polynomial.input_at_least_once)){
                std::cout<<"Warning: You just entered an exponential that is bigger than the largest one you entered before : "<<in_polynomial.max_exp<<". Please enter in decreasing order of exponential. This one will be neglected."<<std::endl;
                return in;
            }

            if(!in_polynomial.input_at_least_once){
                in_polynomial.max_exp = temp_exp;
                in_polynomial.input_at_least_once = true;
                if(in_polynomial.terms > 0){
                    in_polynomial.terms = 0;
                    delete [] in_polynomial.term_array;
                    Term<CoefType, ExpType> *temp = new Term<CoefType, ExpType> [in_polynomial.capacity];
                    in_polynomial.term_array = temp;
                    temp = nullptr;
                }
            }

            in_polynomial.NewTerm(temp_coef, temp_exp);
            return in;
        }
};

#include <solution.hpp>
#endif

