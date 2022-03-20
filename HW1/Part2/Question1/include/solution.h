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

        //Destructor
        ~Term(){}
        friend class Polynomial<CoefType, ExpType>;

};

template <typename CoefType, typename ExpType>
class Polynomial{
    private:
        Term<CoefType, ExpType>* term_array;
        int   terms;//the number of non-zero terms
        int   capcaity; //the max-size of term_array
        std::string name;
    public:
        Polynomial(const int &terms=0, const int &capcaity=10, const std::string &name="NULL"):terms(terms), capcaity(capcaity), name(name){
            term_array = new Term<CoefType, ExpType> [capcaity];
        }

        //Copy consturctor
        Polynomial(const Polynomial &p){
            terms    = p.terms;
            capcaity = p.capcaity;
            name     = p.name;

            for(int i=0;i<terms;++i){
                term_array[i] = p.term_array[i];
            }
        }

        //Destructor
        ~Polynomial(){
            delete [] term_array;
        }

        int                                GetTerms            () const {return terms;}
        int                                GetCapacity         () const {return capcaity;}
        std::string                        GetName             () const {return name;}
        Term<CoefType, ExpType>*           GetTermArray        () const {return term_array;}
        void                               SetTerms            (const int &in_terms)          {terms    = in_terms;}
        void                               SetCapacity         (const int &in_caacity)        {capcaity = in_caacity;}
        void                               SetName             (const std::string &in_name)   {name     = in_name;}
        void                               SetTermArray        (const Term<CoefType, ExpType>* const in_term_array, const int &in_terms);
        void                               NewTerm             (const CoefType &in_coef, const ExpType &in_exp);

        Polynomial      Add                 (Polynomial poly){return *this;}
        Polynomial      Mult                (Polynomial poly){return *this;}
        float           Eval                (float f){return 0.0;}
        int             operator!           (){return 0;}
        CoefType        Coef                (ExpType e){return 0.0;}
        ExpType         LeadExp             (){return 0.0;}

        friend std::ostream & operator<<(std::ostream &os, const Polynomial<CoefType, ExpType> &out_polynomial){
            os<<"The Polynomial "<<out_polynomial.name<<" is : ";
            for(int i=0;i<out_polynomial.terms;++i){
                if(i==out_polynomial.terms-1){
                    if(out_polynomial.term_array[i].GetExp()!=0){
                        os<<abs(out_polynomial.term_array[i].GetCoef())<<"X^"<<out_polynomial.term_array[i].GetExp()<<std::endl;
                    }else{
                        os<<abs(out_polynomial.term_array[i].GetCoef())<<std::endl;
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

            in_polynomial.NewTerm(temp_coef, temp_exp);
            return in;
        }
};

#include <solution.hpp>
#endif

