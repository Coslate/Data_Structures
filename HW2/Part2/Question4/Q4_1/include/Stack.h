#ifndef _STACK_H_
#define _STACK_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <Bag.h>

template <class T>
class Stack : public Bag<T>{
    public:
        Stack(const int &stackCapacity=10, const std::string &name="NULL"): Bag<T>(stackCapacity, name){
        }

        //Copy consturctor
        Stack(const Stack &p) : Bag<T>(p){}

        //Destructor
        ~Stack(){
        }

        T&                                 Top                 () const;
        void                               Pop                 ()       override;

        void                               PrintPath           (const int &end_x, const int &end_y);

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const Stack &array);

        friend std::ostream & operator<<(std::ostream &os, const Stack<T> &out_array){
            if(out_array.top == -1){
                throw std::runtime_error(std::string("Error: Not available. The Stack is empty."));
                return os;
            }
            os<<out_array.name<<" = [";
            for(int i=0;i<=out_array.top;++i){
                if(i==out_array.top){
                    os<<out_array.array[i]<<"], top = "<<out_array.top<<std::endl;
                }else{
                    os<<out_array.array[i]<<" ";
                }
            }

            return os;
        }
};

#include <Stack.hpp>
#endif

