#ifndef _MAXPQ_H_
#define _MAXPQ_H_

template <class T>
class MaxPQ{
    public:
        MaxPQ(){}

        //Destructor, virtual
        ~MaxPQ(){}

        virtual bool                       IsEmpty             ()         const = 0;
        virtual const T&                   Top                 ()         const = 0;
        virtual void                       Push                (const T&)       = 0;
        virtual void                       Pop                 ()               = 0;
};

#include <MaxPQ.hpp>
#endif

