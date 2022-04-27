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

class Term{
    private:
        float coef;
        int   exp;

    public:
        Term() : coef(0), exp(0){}
        Term(const float &coef, const int &exp) : coef(coef), exp(exp){}

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
            os<<"("<<out_term.coef<<", "<<out_term.exp<<")";
            return os;
        }
};


#include <solution.hpp>
#endif

