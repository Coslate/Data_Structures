#ifndef _CIRCULAR_HEADERLIST_H_
#define _CIRCULAR_HEADERLIST_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>

template <typename T>
class CircularHeaderList; //forward declaration

template <typename T>
std::ostream & operator<<(std::ostream &os, const CircularHeaderList<T> &out_list);

template <typename T>
class CHLNode{
    private:
        T           data;
        CHLNode<T>* link;
    public:
        CHLNode(const T &data, CHLNode<T>* const in_link=NULL) : data(data), link(in_link){}

        ~CHLNode(){}

        friend class CircularHeaderList<T>;
        friend std::ostream & operator<<<T>(std::ostream &os, const CircularHeaderList<T> &out_list);
};

template <typename T>
class CircularHeaderList{
    private:
        std::string name;
        CHLNode<T> *header;
        CHLNode<T> *av;

    public:
        CircularHeaderList(const std::string &name="NULL"):name(name), header(NULL), av(NULL){
            T  unknown_data;
            header = new CHLNode<T> (unknown_data, NULL);
            header->link = header;
        }

        CircularHeaderList(const T &data, const std::string &name="NULL"):name(name), header(NULL), av(NULL){
            header = new CHLNode<T> (data, NULL);
            header->link = header;
        }

        //Copy consturctor
        CircularHeaderList(const CircularHeaderList &p){
            name     = p.name;
            header   = p.header;
            av       = p.av;
        }

        //Destructor
        ~CircularHeaderList(){
            CHLNode<T> *current_node = header->link;
            //Find the last node
            while(current_node->link != header){
                current_node = current_node->link;
            }
            current_node->link = av;
            av = header->link;
            header->link = header;
        }

        bool                               IsEmpty             () const {return (header->link==header);}
        void                               InsertFront         (const T &data);
        void                               InsertBack          (const T &data);
        void                               DeleteFirst         ();
        void                               DeleteLast          ();
        int                                NumOfNodes          ();
        CHLNode<T>*                        Get                 (const int i) const;

        CHLNode<T>*                        GetNode             ();
        void                               RetNode             (CHLNode<T> *&x);
        void                               CleanAV             ();

        std::string                        Name                () const {return name;}
        void                               SetName             (const std::string &in_name)    {name     = in_name;}

        //static bool SortFunction(const Term<T> &a, const Term<T> &b);
        void operator=(const CircularHeaderList &chain);
        friend std::ostream & operator<<<T>(std::ostream &os, const CircularHeaderList<T> &out_chain);

};

#include <circular_headerlist.hpp>
#endif

