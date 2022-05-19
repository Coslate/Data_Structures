#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

template <class K, class E>
struct pair { 
    K first; 
    E second; 
    pair(const K &first, const E &second):first(first), second(second){};
    friend std::ostream & operator<< (std::ostream &os, const pair<K, E> &out_pair){
        os<<"("<<out_pair.first<<", "<<out_pair.second<<")";
        return os;
    }
};

template <class K, class E>
class Dictionary{
    public:
        Dictionary(){}

        //Destructor, virtual
        ~Dictionary(){}

        virtual bool                       IsEmpty             ()         const = 0;
        virtual pair<K, E>*                Get                 (const K &)const = 0;
        virtual void                       Insert              (const pair<K, E>&)        = 0;
        virtual void                       Delete              (const K &)                = 0;
};

#include <Dictionary.hpp>
#endif

