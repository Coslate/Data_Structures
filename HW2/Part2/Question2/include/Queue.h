#ifndef _QUEUE_H_
#define _QUEUE_H_

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
        Queue(const int &queueCapacity=10, const std::string &name="NULL"):front(queueCapacity-1), rear(queueCapacity-1), capacity(queueCapacity), size(0), name(name){
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
        T&                                 Front               () const;
        T&                                 Rear                () const;
        void                               Push                (const T &item);
        void                               Pop                 ();
        Queue                              MergeQueue          (const Queue &input_queue);

        int                                Size                () const {return size;}
        int                                Capacity            () const {return capacity;}
        std::string                        Name                () const {return name;}
        void                               SetName             (const std::string &in_name)    {name     = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const Queue &queue);

        friend std::ostream & operator<<(std::ostream &os, const Queue<T> &out_queue){
            if(out_queue.size == 0){
                throw std::runtime_error(std::string("Error: Not available. The Queue is empty."));
                return os;
            }
            os<<out_queue.name<<" = [";
            if(out_queue.rear < out_queue.front){
                for(int i=out_queue.front+1;i<out_queue.capacity;++i){
                    os<<out_queue.queue[i]<<" ";
                }
                for(int i=0;i<=out_queue.rear;++i){
                    if(i==out_queue.rear){
                        os<<out_queue.queue[i]<<"]"<<", front = "<<out_queue.front<<", rear = "<<out_queue.rear<<std::endl;
                    }else{
                        os<<out_queue.queue[i]<<" ";
                    }
                }
            }else{
                for(int i=out_queue.front+1;i<=out_queue.rear;++i){
                    if(i==out_queue.rear){
                        os<<out_queue.queue[i]<<"]"<<", front = "<<out_queue.front<<", rear = "<<out_queue.rear<<std::endl;
                    }else{
                        os<<out_queue.queue[i]<<" ";
                    }
                }
            }
            //os<<"front = "<<out_queue.front<<std::endl;
            //os<<"rear  = "<<out_queue.rear<<std::endl;
            return os;
        }
};

#include <Queue.hpp>
#endif

