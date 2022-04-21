#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>

template <class T>
class Chain; //forward declaration

template <typename T>
std::ostream & operator<<(std::ostream &os, const Chain<T> &out_queue);

template <class T>
class ChainNode{
    private:
        T             data;
        ChainNode<T>* link;
    public:
        ChainNode(const T &in_data, ChainNode<T>* const in_link=NULL) : data(in_data), link(in_link){}
        ~ChainNode(){}
        friend class Chain<T>;
        friend std::ostream & operator<<<T>(std::ostream &os, const Chain<T> &out_queue);
};

template <class T>
class Chain{
    private:
        std::string name;
        ChainNode<T> *first;

    public:
        Chain(const std::string &name="NULL"):name(name), first(NULL){}

        //Copy consturctor
        Chain(const Chain &p){
            name     = p.name;
            first    = p.first;
        }

        //Destructor
        ~Chain(){
            while(first!=NULL){
                ChainNode<T>* tmp = first;
                first = first->link;
                tmp->link = NULL;
                delete tmp;
            }

        }

        bool                               IsEmpty             () const {return (first==NULL);}
        void                               InsertFront         (const T &in_data);
        void                               DeleteFront         ();
        T&                                 Front               () const;
        T&                                 Back                () const;
        T&                                 Get                 (const int i) const;


        std::string                        Name                () const {return name;}
        void                               SetName             (const std::string &in_name)    {name     = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const Chain &chain);
        friend std::ostream & operator<<<T>(std::ostream &os, const Chain<T> &out_chain);

};

#include <linkedlist.hpp>
#endif

