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
#include <List.h>

template <class T>
class Queue : public List<T>{
    private:
        Node<T>*        front;    //the front position of the queue
        Node<T>*        rear;     //the rear position of the queue

    public:
        Queue(const std::string &name="NULL"): List<T>(name), front(NULL), rear(NULL){
            std::cout<<"Queue::Queue() is called."<<std::endl;
            front = List<T>::Front();
            rear  = List<T>::Back();
        }

        //Copy consturctor
        Queue(const Queue &p) : List<T>(p){
            front    = p.front;
            rear     = p.rear;
        }

        //Destructor
        ~Queue(){
            std::cout<<"Queue::~Queue() is called."<<std::endl;
            front = NULL;
            rear  = NULL;
        }

        T&                                 Front               () const;
        T&                                 Rear                () const;
        void                               Push                (const T &item);
        void                               Pop                 ();

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const Queue &queue);

        friend std::ostream & operator<<(std::ostream &os, const Queue<T> &out_queue){
            if(out_queue.IsEmpty()){
                throw std::runtime_error(std::string("Error: Not available. The Queue is empty."));
                return os;
            }

            os<<static_cast<const List<T> &>(out_queue);
            return os;
        }
};

#include <Queue.hpp>
#endif

