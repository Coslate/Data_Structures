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
class Queue{
    private:
        int         front;    //the front position of the queue
        int         rear;     //the rear position of the queue
        int         capacity; //the max-size of queue
        int         size;     //the current size of the queue
        std::string name;
        T*          queue;

        void        ArrayDoubling();
    public:
        Queue(const int &front=0, const int &rear=0, const int &capacity=10, const int &size=0, const std::string &name="NULL"):front(front), rear(rear), capacity(capacity), size(size), name(name){
            if(capacity < 1) throw std::runtime_error(std::string("Error: Cannot set capacity < 1 ."));
            queue = new T [capacity];
        }

        //Copy consturctor
        Queue(const Queue &p){
            front    = p.front;
            rear     = p.rear;
            capacity = p.capacity;
            size     = p.size;
            name     = p.name;
            queue = new T [capacity];

            for(int i=0;i<size;++i){
                queue[i] = p.queue[i];
            }
        }

        //Destructor
        ~Queue(){
            delete [] queue;
            queue = nullptr;
        }

        bool                               IsEmpty             () const {return (front==rear);}
        void                               Push                (const T &item);
        void                               Pop                 ();
        T&                                 Front               () const;
        T&                                 Rear                () const;
        Queue                              MergeQueue          (const Queue &input_queue);

        int                                Size                () const {return size;}
        int                                Capacity            () const {return capacity;}
        std::string                        Name                () const {return name;}
        void                               SetSize             (const int &in_size)            {size     = in_size;}
        void                               SetCapacity         (const int &in_capacity)        {capacity = in_capacity;}
        void                               SetName             (const std::string &in_name)    {name     = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const Queue &queue);

        friend std::ostream & operator<<(std::ostream &os, const Queue<T> &out_queue){
            if(out_queue.size == 0){
                throw std::runtime_error(std::string("Error: Not available. The Queue is empty."));
                return os;
            }
            os<<out_queue.name<<" = [";
            if(rear < front){
                for(int i=front+1;i<capacity;++i){
                    os<<queue[i]<<" ";
                }
                for(int i=0;i<=rear;++i){
                    if(i==rear){
                        os<<queue[i]<<"]"<<std::endl;
                    }else{
                        os<<queue[i]<<" ";
                    }
                }
            }else{
                for(int i=front+i;i<=rear;++i){
                    if(i==rear){
                        os<<queue[i]<<"]"<<std::endl;
                    }else{
                        os<<queue[i]<<" ";
                    }
                }
            }
            os<<"front = "<<front<<std::endl;
            os<<"rear  = "<<rear<<std::endl;
            return os;
        }
};

#include <solution.hpp>
#endif

