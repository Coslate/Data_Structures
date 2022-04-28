#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <circular_headerlist.h>


class Term{
    private:
        double coef;
        int    exp;

    public:
        Term() : coef(0), exp(0){}
        Term(const double &coef, const int &exp) : coef(coef), exp(exp){}

        //Copy consturctor
        Term(const Term &p){
            coef  = p.coef;
            exp   = p.exp;
        }

        void operator=(const Term &in_term){
            coef   = in_term.coef;
            exp    = in_term.exp;
        }

        //Destructor
        ~Term(){}
        friend std::ostream & operator<<(std::ostream &os, const Term &out_term){
            os<<out_term.coef<<", "<<out_term.exp;
            return os;
        }

        friend class Polynomial;
};

class Polynomial{
    private:
        CircularHeaderList<Term> term_list;
        int                      terms;    //the number of non-zero terms
        std::string              name;
        int                      max_exp;  //record the largest exponential among the terms of the polynomial
        bool                     input_at_least_once; //record whether the first time use >> input

        void                     FindLeadExp    ();//Determine the max_exp

    public:
        Polynomial(const int &terms=0, const std::string &name="NULL", const int &max_exp=0, const bool &input_at_least_once = false):terms(terms), name(name), max_exp(max_exp), input_at_least_once(input_at_least_once){
        }

        //Copy consturctor
        Polynomial(const Polynomial &p){
            terms               = p.terms;
            name                = p.name;
            max_exp             = p.max_exp;
            input_at_least_once = p.input_at_least_once;
            term_list           = p.term_list;
            std::cout<<"> Copy constructor of Polynomial is called."<<std::endl;
        }

        //Destructor
        ~Polynomial(){
            while(!term_list.IsEmpty()){
                term_list.DeleteFirst();
            }
            terms = 0;
            std::cout<<"> Destructor of Polynomial is called."<<std::endl;
        }

        int                                GetTerms            () const {return terms;}
        std::string                        GetName             () const {return name;}
        void                               SetTerms            (const int &in_terms)          {terms    = in_terms;}
        void                               SetName             (const std::string &in_name)   {name     = in_name;}
        void                               NewTerm             (const double &in_coef, const int &in_exp);
        void                               CleanAll            ()       {term_list.CleanAV();}
        void                               DeleteAll           ()       {while(!term_list.IsEmpty()){term_list.DeleteFirst();} terms = 0;}

        Polynomial                         operator+           (const Polynomial &b);
        Polynomial                         operator-           (const Polynomial &b);
        Polynomial                         operator*           (const Polynomial &b);
        void                               operator=           (const Polynomial &b);
        double                             Eval                (double x);
        int                                LeadExp             (){if(terms==0){throw std::runtime_error(std::string("Warning: Not available. The Polynomial is empty."));} return max_exp;}

        static bool SortFunction(const Term &a, const Term &b);

        friend std::ostream & operator<<(std::ostream &os, const Polynomial &out_polynomial){
            if(out_polynomial.terms == 0){
                throw std::runtime_error(std::string("Warning: Not available. The Polynomial is empty."));
                return os;
            }

            os<<out_polynomial.terms<<", ";
            for(CircularHeaderList<Term>::Iterator i=out_polynomial.term_list.Begin(); i != out_polynomial.term_list.End(); i++){
                if((i+1) == out_polynomial.term_list.End()){
                    os<<*i<<std::endl;
                }else{
                    os<<*i<<", ";
                }
            }

            return os;
        }

        friend std::istream & operator>>(std::istream &in, Polynomial &in_polynomial){
            double temp_coef;
            int    temp_exp;

            std::cout<<"Please enter the coefficient for "<<in_polynomial.name<<" : ";
            in>> temp_coef;
            std::cout<<"Please enter the exponential for "<<in_polynomial.name<<" : ";
            in>> temp_exp;

            if(temp_coef == 0){
                std::cout<<"Warning: The coefficient you just entered is 0, which will not be taken into the Polynomial."<<std::endl;
                return in;
            }

            if((temp_exp >= in_polynomial.max_exp) && (in_polynomial.input_at_least_once)){
                std::cout<<"Warning: You just entered an exponential that is bigger than the largest one you entered before : "<<in_polynomial.max_exp<<". Please enter in decreasing order of exponential. This one will be neglected."<<std::endl;
                return in;
            }

            if(!in_polynomial.input_at_least_once){
                in_polynomial.max_exp = temp_exp;
                in_polynomial.input_at_least_once = true;
                if(in_polynomial.terms > 0){
                    in_polynomial.DeleteAll();
                }
            }

            in_polynomial.NewTerm(temp_coef, temp_exp);
            return in;
        }
};

#include <polynomial.hpp>
#endif

