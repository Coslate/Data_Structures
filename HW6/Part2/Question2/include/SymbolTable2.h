#ifndef _SYMBOLTABLE2_H_
#define _SYMBOLTABLE2_H_

#include <string>
#include <iostream>
#include <Dictionary.h>
#include <Chain.h>

template <class K> //Only key, omitted element in this implementation
class SymbolTable2 : public Dictionary<K>{//hash table using linear probing, assumed slot=1
    private:
        std::string     name;
        int             ht_size;
        int             ht_capacity;
        Chain<pair<K>>* ht; //every element in the hash table is a pair<K>

        int hash_func(const K* in_key, const int key_size) const ;

    public:
        //Constructor
        SymbolTable2(const int ht_capacity=26): Dictionary<K>(), name("NULL"), ht_size(0), ht_capacity(ht_capacity){
            std::cout<<"("<<name<<", Constructor is called...)"<<std::endl;
            ht = new Chain<pair<K>> [ht_capacity];
            std::cout<<"("<<name<<", Constructor ends...)"<<std::endl;
        }
        SymbolTable2(const std::string &name, const int ht_capacity=26): Dictionary<K>(), name(name), ht_size(0), ht_capacity(ht_capacity){
            std::cout<<"("<<name<<", Constructor is called...)"<<std::endl;
            ht = new Chain<pair<K>> [ht_capacity];
            std::cout<<"("<<name<<", Constructor ends...)"<<std::endl;
        }

        //Destructor
        ~SymbolTable2(){
            std::cout<<"("<<name<<", Destructor is called...)"<<std::endl;
            delete [] ht;
            std::cout<<"("<<name<<", Destructor ends...)"<<std::endl;
        }

        std::string                        Name                ()                                 const {return name;}
        void                               SetName             (const std::string &in_name)             {name = in_name;}

        bool                               IsEmpty             ()                                 const {return(ht_size==0);}
        pair<K>*                           Search              (const K *key, const int key_size, int &nxt_bucket) const;
        void                               Insert              (const pair<K>&);
        bool                               Compare             (const K *arr1, const K *arr2, const int key_size1, const int key_size2) const ;
        void                               Display             () const;
};

#include <SymbolTable2.hpp>
#endif

