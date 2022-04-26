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
#include <List.h>

template <class T>
class Stack : public List<T>{
    private:
        Node<T> *top;

    public:
        Stack(const std::string &name="NULL"): List<T>(name){
            std::cout<<"Stack::Stack() is called."<<std::endl;
            top = List<T>::Front();
        }

        //Copy consturctor
        Stack(const Stack &p) : List<T>(p){
            top = p.top;
        }

        //Destructor
        ~Stack(){
            std::cout<<"Stack::~Stack() is called."<<std::endl;
            top = NULL;
        }

        T&                                 Top                 ()              const;
        void                               Pop                 ();
        void                               Push                (const T &item);

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const Stack &array);

        friend std::ostream & operator<<(std::ostream &os, const Stack<T> &out_stack){
            if(out_stack.top == NULL){
                throw std::runtime_error(std::string("Error: Not available. The Stack is empty."));
                return os;
            }

            os<<static_cast<const List<T> &>(out_stack);
            /*
            for(out_stack.List<T>::Iterator y = out_stack.List<T>::Begin(); y!=out_stack.List<T>::End(); y++){
                if(y.next_is_end()){
                    os<<*y<<"]"<<std::endl;
                }else{
                    os<<*y<<" ";
                }
            }
            */
            return os;
        }
};

#include <Stack.hpp>
#endif

