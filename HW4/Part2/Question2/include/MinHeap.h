#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <MinPQ.h>

template <typename T>
class MinHeap;

template <typename T>
std::ostream & operator<<(std::ostream &os, const MinHeap<T> &out_list);

template <class T>
class MinHeap : public MinPQ<T>{
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
        MinHeap(const int &in_capacity = 10, const std::string &in_name="NULL"): heap(NULL), heap_size(0), capacity(in_capacity), name(in_name){
            std::cout<<"(MinHeap::MinHeap() is called...)"<<std::endl;
            if(capacity < 1) throw std::runtime_error(std::string("Error: Cannot set capacity < 1 ."));
            heap = new T [capacity+1]; //heap[0] unused

            std::cout<<"(MinHeap::MinHeap() ended...)"<<std::endl;
        }

        //Copy consturctor
        MinHeap(const MinHeap &p) : MinPQ<T>(){
            std::cout<<"(MinHeap Copy Constructor() is called...)"<<std::endl;
            capacity = p.capacity;
            heap_size= p.heap_size;
            name     = p.name;
            heap = new T [capacity];

            for(int i=1;i<=heap_size;++i){
                heap[i] = p.heap[i];
            }

            std::cout<<"(MinHeap Copy Constructor() is ended...)"<<std::endl;
        }

        //Destructor
        ~MinHeap(){
            std::cout<<"(MinHeap::~MinHeap() is called...)"<<std::endl;
            delete [] heap;
            heap = nullptr;
            std::cout<<"(MinHeap::~MinHeap() ended...)"<<std::endl;
        }

        bool                               IsEmpty             ()              const {return (heap_size == 0);}
        const T&                           Top                 ()              const {return heap[1];}
        void                               Push                (const T& item);
        void                               Pop                 ()             ;
        void                               BottomUpConstruction(const T *input_array, const int &size);

        std::string                        Name                ()              const {return name;}
        void                               SetName             (const std::string &in_name)    {name = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const MinHeap &queue);
        friend std::ostream & operator<<<T>(std::ostream &os, const MinHeap<T> &out_list);
};

#include <MinHeap.hpp>
#endif

