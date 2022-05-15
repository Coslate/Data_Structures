#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <MaxPQ.h>

template <typename T>
class MaxHeap;

template <typename T>
std::ostream & operator<<(std::ostream &os, const MaxHeap<T> &out_list);

template <class T>
class MaxHeap : public MaxPQ<T>{
    private:
        T* heap;       //element array
        int heap_size; //number of elements in heap
        int capacity;  //size of the element array
        std::string name;

        void        ArrayDoubling();
        void        BobbleUp(const int &pos);
        void        BobbleDown(const int &pos);
        void        Swap(T &item1, T &item2);
    public:
        MaxHeap(const int &in_capacity = 10, const std::string &in_name="NULL"): heap(NULL), heap_size(0), capacity(in_capacity), name(in_name){
            std::cout<<"(MaxHeap::MaxHeap() is called...)"<<std::endl;
            if(capacity < 1) throw std::runtime_error(std::string("Error: Cannot set capacity < 1 ."));
            heap = new T [capacity+1]; //heap[0] unused

            std::cout<<"(MaxHeap::MaxHeap() ended...)"<<std::endl;
        }

        //Copy consturctor
        MaxHeap(const MaxHeap &p) : MaxPQ<T>(){
            std::cout<<"(MaxHeap Copy Constructor() is called...)"<<std::endl;
            capacity = p.capacity;
            heap_size= p.heap_size;
            name     = p.name;
            heap = new T [capacity];

            for(int i=1;i<=heap_size;++i){
                heap[i] = p.heap[i];
            }

            std::cout<<"(MaxHeap Copy Constructor() is ended...)"<<std::endl;
        }

        //Destructor
        ~MaxHeap(){
            std::cout<<"(MaxHeap::~MaxHeap() is called...)"<<std::endl;
            delete [] heap;
            heap = nullptr;
            std::cout<<"(MaxHeap::~MaxHeap() ended...)"<<std::endl;
        }

        bool                               IsEmpty             ()              const {return (heap_size == 0);}
        const T&                           Top                 ()              const {return heap[1];}
        void                               Push                (const T& item);
        void                               Pop                 ()             ;
        void                               BottomUpConstruction(const T *input_array, const int &size);

        std::string                        Name                ()              const {return name;}
        void                               SetName             (const std::string &in_name)    {name = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const MaxHeap &queue);
        friend std::ostream & operator<<<T>(std::ostream &os, const MaxHeap<T> &out_list);
};

#include <MaxHeap.hpp>
#endif

