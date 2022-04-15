#ifndef _BAG_H_
#define _BAG_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>

template <class T>
class Bag{
    protected:
        int         capacity; //the max-size of bag
        int         top;     //the current size of the bag
        std::string name;
        T*          array;

        virtual void        ArrayDoubling();
    public:
        Bag(const int &bagCapacity=10, const std::string &name="NULL"):capacity(bagCapacity), top(-1), name(name){
            std::cout<<"Bag::Bag() is called."<<std::endl;
            if(capacity < 1) throw std::runtime_error(std::string("Error: Cannot set capacity < 1 ."));
            array = new T [capacity];
        }

        //Copy consturctor
        Bag(const Bag &p){
            capacity = p.capacity;
            top      = p.top;
            name     = p.name;
            array = new T [capacity];

            for(int i=0;i<=top;++i){
                array[i] = p.array[i];
            }
        }

        //Destructor
        ~Bag(){
            delete [] array;
            array = nullptr;
            std::cout<<"Bag::~Bag() is called."<<std::endl;
        }

        virtual int                        Size                () const {return (top+1);}
        virtual bool                       IsEmpty             () const {return (top==-1);}
        virtual T&                         Element             () const;
        virtual void                       Push                (const T &item);
        virtual void                       Pop                 ();

        virtual std::string                Name                () const {return name;}
        virtual void                       SetName             (const std::string &in_name)    {name = in_name;}

        void operator=(const Bag &array);

        friend std::ostream & operator<<(std::ostream &os, const Bag<T> &out_bag){
            if(out_bag.IsEmpty()){
                throw std::runtime_error(std::string("Error: Not available. The Bag is empty."));
                return os;
            }
            os<<out_bag.name<<" = [";
            for(int i=0;i<=out_bag.top;++i){
                if(i==out_bag.top){
                    os<<out_bag.array[i]<<"]"<<std::endl;
                }else{
                    os<<out_bag.array[i]<<", ";
                }
            }
            return os;
        }
};

#include <Bag.hpp>
#endif

