#ifndef _DEQUEUE_H_
#define _DEQUEUE_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <Queue.h>

template <class T>
class Dequeue : public Queue<T>{
    public:
        Dequeue(const int &queueCapacity=10, const std::string &name="NULL"): Queue<T>(queueCapacity, name){
            std::cout<<"Dequeue::Dequeue() is called."<<std::endl;
        }

        //Copy consturctor
        Dequeue(const Dequeue &p) : Queue<T>(p){}

        //Destructor
        ~Dequeue(){
            std::cout<<"Dequeue::~Dequeue() is called."<<std::endl;
        }

        void                               PushFront               (const T &item) ;
        void                               PopRear                 ()              ;
//Use the implemented Push(at rear) and Pop(from front) inheriting from Queue
        void                               PushRear                (const T &item) ;
        void                               PopFront                ()              ;

//The following functions are inherited from Queue.
//        bool                               IsEmpty             () const        override {return (front==rear);}
//        T&                                 Front               () const;
//        T&                                 Rear                () const;
//        int                                Size                () const        override {return size;}
//        int                                Capacity            () const                 {return capacity;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        //void operator=(const Dequeue &dequeue);

        friend std::ostream & operator<<(std::ostream &os, const Dequeue<T> &out_queue){
            if(out_queue.size == 0){
                throw std::runtime_error(std::string("Error: Not available. The Dequeue is empty."));
                return os;
            }
            os<<out_queue.name<<" = [";
            if(out_queue.rear < out_queue.front){
                for(int i=out_queue.front+1;i<out_queue.capacity;++i){
                    os<<out_queue.array[i]<<" ";
                }
                for(int i=0;i<=out_queue.rear;++i){
                    if(i==out_queue.rear){
                        os<<out_queue.array[i]<<"]"<<", front = "<<out_queue.front<<", rear = "<<out_queue.rear<<std::endl;
                    }else{
                        os<<out_queue.array[i]<<" ";
                    }
                }
            }else{
                for(int i=out_queue.front+1;i<=out_queue.rear;++i){
                    if(i==out_queue.rear){
                        os<<out_queue.array[i]<<"]"<<", front = "<<out_queue.front<<", rear = "<<out_queue.rear<<std::endl;
                    }else{
                        os<<out_queue.array[i]<<" ";
                    }
                }
            }
            //os<<"front = "<<out_queue.front<<std::endl;
            //os<<"rear  = "<<out_queue.rear<<std::endl;
            return os;
        }
};

#include <Dequeue.hpp>
#endif

