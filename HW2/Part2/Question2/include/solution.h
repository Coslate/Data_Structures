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

template <class T>
class Stack{
    private:
        int         top;    //the top position of the stack
        int         capacity; //the max-size of stack
        std::string name;
        T*          stack;

        void        ArrayDoubling();
    public:
        Stack(const int &stackCapacity=10, const std::string &name="NULL"):top(-1), capacity(stackCapacity), name(name){
            if(capacity < 1) throw std::runtime_error(std::string("Error: Cannot set capacity < 1 ."));
            stack = new T [capacity];
        }

        //Copy consturctor
        Stack(const Stack &p){
            top      = p.top;
            capacity = p.capacity;
            name     = p.name;
            stack = new T [capacity];

            for(int i=0;i<=top;++i){
                stack[i] = p.stack[i];
            }
        }

        //Destructor
        ~Stack(){
            delete [] stack;
            stack = nullptr;
        }

        bool                               IsEmpty             () const {return (top==-1);}
        T&                                 Top                 () const;
        void                               Push                (const T &item);
        void                               Pop                 ();

        int                                Capacity            () const {return capacity;}
        std::string                        Name                () const {return name;}
        void                               SetName             (const std::string &in_name)    {name     = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const Stack &stack);

        friend std::ostream & operator<<(std::ostream &os, const Stack<T> &out_stack){
            if(out_stack.top == -1){
                throw std::runtime_error(std::string("Error: Not available. The Stack is empty."));
                return os;
            }
            os<<out_stack.name<<" = [";
            for(int i=0;i<=out_stack.top;++i){
                if(i==out_stack.top){
                    os<<out_stack.stack[i]<<"], top = "<<out_stack.top<<std::endl;
                }else{
                    os<<out_stack.stack[i]<<" ";
                }
            }

            return os;
        }
};

#include <solution.hpp>
#endif

