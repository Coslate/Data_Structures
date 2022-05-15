#ifndef _MINPQ_H_
#define _MINPQ_H_

template <class T>
class MinPQ{
    public:
        MinPQ(){}

        //Destructor, virtual
        ~MinPQ(){}

        virtual bool                       IsEmpty             ()         const = 0;
        virtual const T&                   Top                 ()         const = 0;
        virtual void                       Push                (const T&)       = 0;
        virtual void                       Pop                 ()               = 0;
};

#include <MinPQ.hpp>
#endif

