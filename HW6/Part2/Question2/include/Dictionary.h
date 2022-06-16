#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <string>
#include <iostream>

std::string GenRandomString(const int len);

template <class K>//Only key, the element is omitted now
struct pair {
    int  size;
    K   *arr;

    pair(): size(0), arr(NULL){};
    pair(const int &size): size(size){
        std::string gen_str = GenRandomString(size);
        arr = new K [size+1]();

        for(int i=0; i<size+1; ++i){
            arr[i] = gen_str[i];
        }
    };

    friend std::ostream & operator<< (std::ostream &os, const pair &out_pair){
        for(int i=0; i<out_pair.size; ++i){
            os<<out_pair.arr[i];
        }
        return os;
    }
};

template <class K>
class Dictionary{
    public:
        Dictionary(){}

        //Destructor, virtual
        ~Dictionary(){}

        virtual bool                       IsEmpty             ()                                                    const = 0;
        virtual pair<K>*                   Search              (const K *key, const int key_size, int &nxt_bucket)   const = 0;
        virtual void                       Insert              (const pair<K>&)                           = 0;
};

#include <Dictionary.hpp>
#endif

