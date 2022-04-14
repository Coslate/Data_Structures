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
#include <Bag.h>

template <class T>
class Queue : public Bag<T>{
    private:
        int         front;    //the front position of the queue
        int         rear;     //the rear position of the queue
        int         size;     //the current size of the queue

        void        ArrayDoubling() override;
    public:
        Queue(const int &queueCapacity=10, const std::string &name="NULL"): Bag<T>(queueCapacity, name), front(queueCapacity-1), rear(queueCapacity-1), size(0){
            std::cout<<"Queue::Queue() is called."<<std::endl;
        }

        //Copy consturctor
        Queue(const Queue &p) : Bag<T>(p){
            front    = p.front;
            rear     = p.rear;
            size     = p.size;
        }

        //Destructor
        ~Queue(){
            std::cout<<"Queue::~Queue() is called."<<std::endl;
        }

        bool                               IsEmpty             () const        override {return (front==rear);}
        T&                                 Front               () const;
        T&                                 Rear                () const;
        void                               Push                (const T &item) override;
        void                               Pop                 ()              override;

        int                                Size                () const        override {return size;}
        int                                Capacity            () const                 {return Bag<T>::capacity;}

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
                    os<<out_queue.Bag<T>::array[i]<<" ";
                }
                for(int i=0;i<=out_queue.rear;++i){
                    if(i==out_queue.rear){
                        os<<out_queue.Bag<T>::array[i]<<"]"<<", front = "<<out_queue.front<<", rear = "<<out_queue.rear<<std::endl;
                    }else{
                        os<<out_queue.Bag<T>::array[i]<<" ";
                    }
                }
            }else{
                for(int i=out_queue.front+1;i<=out_queue.rear;++i){
                    if(i==out_queue.rear){
                        os<<out_queue.Bag<T>::array[i]<<"]"<<", front = "<<out_queue.front<<", rear = "<<out_queue.rear<<std::endl;
                    }else{
                        os<<out_queue.Bag<T>::array[i]<<" ";
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

