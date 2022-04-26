#ifndef _LIST_H_
#define _LIST_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>

template <class T>
class List; //forward declaration

template <class T>
class Node; //forward declaration

template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &out_list);

template <typename T>
std::ostream & operator<<(std::ostream &os, const Node<T>* const out_node);

template <class T>
class Node{
    private:
        T             data;
        Node<T>*      link;
    public:
        Node(const T &e, Node<T>* const in_link=NULL) : data(e), link(in_link){}
        ~Node(){}
        friend class List<T>;
        friend std::ostream & operator<<<T>(std::ostream &os, const List<T> &out_list);
        friend std::ostream & operator<<<T>(std::ostream &os, const Node<T>* const out_node);
};

template <class T>
class List{
    protected:
        std::string name;
        T&          GetNodeData (Node<T> &in_node) const {return in_node.data;}
        void        DeleteBack  ();

    private:
        Node<T> *first;

    public:
        List(const std::string &name="NULL"):name(name), first(NULL){}

        //Copy consturctor
        List(const List &p){
            name     = p.name;
            first    = p.first;
        }

        //Destructor
        ~List(){
            while(first!=NULL){
                Node<T>* tmp = first;
                first = first->link;
                tmp->link = NULL;
                delete tmp;
            }

        }

        class Iterator{
            private:
                Node<T> *current_node;
            public:
                Iterator(Node<T> *start_node=NULL){
                    current_node = start_node;
                }

                T&         operator  *() const            {return current_node->data;}
                T*         operator ->() const            {return &current_node->data;}//from textbook ppt p.75
                Iterator&  operator ++()                  {current_node = current_node->link; return *this;}
                Iterator   operator ++(int)               {Iterator old = *this; current_node = current_node->link; return old;}
                Iterator   operator +(int i)              {Node<T> *tmp_node = current_node; int count=0; while(count<i && current_node!=NULL){current_node = current_node->link; count++;}  Node<T> *dest_node = current_node; current_node = tmp_node; return Iterator(dest_node);}
                bool       operator !=(const Iterator &r) {return current_node != r.current_node;}
                bool       operator ==(const Iterator &r) {return current_node == r.current_node;}
                bool       next_is_end()                  {return (current_node->link==NULL);}
        };

        Iterator                           Begin() { return Iterator(first);}
        Iterator                           End()   { return Iterator(NULL);}

        virtual bool                       IsEmpty             () const {return (first==NULL);}
        void                               InsertFront         (const T &e);
        void                               InsertBack          (const T &e);
        void                               Insert              (const int i, const T e);
        void                               DeleteFront         ();
        void                               Delete              (const int i);
        void                               Concatenate         (List<T> &b);
        void                               Reverse             ();
        int                                NumOfNodes          ();
        Node<T>*                           Front               () const;
        Node<T>*                           Back                () const;
        Node<T>&                           Get                 (const int i) const;

        virtual std::string                Name                () const {return name;}
        virtual void                       SetName             (const std::string &in_name)    {name     = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const List &chain);
        friend std::ostream & operator<<<T>(std::ostream &os, const List<T> &out_list);

};

#include <List.hpp>
#endif

