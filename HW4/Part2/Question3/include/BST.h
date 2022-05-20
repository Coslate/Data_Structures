#ifndef _BST_H_
#define _BST_H_

#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <Dictionary.h>

template <class K, class E>
class BST;

template <class K, class E>
class BSTNode;

template <class K, class E>
std::ostream & operator<<(std::ostream &os, const BSTNode<K, E> *out_node);

template <class K, class E>
class BSTNode{
    private:
        pair<K, E>         data;
        BSTNode<K, E>*     leftchild;
        BSTNode<K, E>*     rightchild;
    public:
        BSTNode(const pair<K, E> &in_data, BSTNode<K, E>* const leftchild=NULL, BSTNode<K, E>* const rightchild=NULL) : data(in_data), leftchild(leftchild), rightchild(rightchild){}
        ~BSTNode(){}

        friend class BST<K, E>;
        friend std::ostream & operator<<<K, E>(std::ostream &os, const BSTNode<K, E> *out_node);
};

template <class K, class E>
class BST : public Dictionary<K, E>{
    private:
        std::string    name;
        BSTNode<K, E> *root;

    public:
        BST():name("NULL"), root(NULL){}
        BST(const std::string &name):name(name), root(NULL){}
        BST(BSTNode<K, E> *root, const std::string &name = "NULL"):name(name), root(root){}

        //Copy consturctor
        BST(const BST &p) : Dictionary<K, E>(){
            std::cout<<"("<<p.name<<", Copy Constructor() is called...)"<<std::endl;
            std::queue<BSTNode<K, E>* > node_p_queue;
            std::queue<BSTNode<K, E>* > node_queue;
            name                       = p.name;
            BSTNode<K, E>* current_p_node = p.root;
            BSTNode<K, E>* current_node   = root;

            if(current_p_node != NULL){
                current_node = new BSTNode<K, E> (current_p_node->data, NULL, NULL);
                root         = current_node;
            }

            while(current_p_node != NULL){
                if(current_p_node->leftchild != NULL){
                    node_p_queue.push(current_p_node->leftchild);
                    current_node->leftchild = new BSTNode<K, E> (current_p_node->leftchild->data, NULL, NULL);
                    node_queue.push(current_node->leftchild);
                }
                if(current_p_node->rightchild != NULL){
                    node_p_queue.push(current_p_node->rightchild);
                    current_node->rightchild = new BSTNode<K, E> (current_p_node->rightchild->data, NULL, NULL);
                    node_queue.push(current_node->rightchild);
                }

                if(node_p_queue.empty()){
                    break;
                }

                current_p_node = node_p_queue.front();
                node_p_queue.pop();
                current_node = node_queue.front();
                node_queue.pop();
            }
            std::cout<<"("<<name<<", Copy Constructor() ends...)"<<std::endl;
        }

        //Destructor
        ~BST(){
            std::cout<<"("<<name<<", Destructor is called...)"<<std::endl;
            std::queue<BSTNode<K, E>* > node_queue;
            BSTNode<K, E>* current_node   = root;

            while(current_node != NULL){
                if(current_node->leftchild != NULL){
                    node_queue.push(current_node->leftchild);
                }
                if(current_node->rightchild != NULL){
                    node_queue.push(current_node->rightchild);
                }

                //Delete the current node
                current_node->leftchild  = NULL;
                current_node->rightchild = NULL;
                delete current_node;

                if(node_queue.empty()){
                    break;
                }

                current_node = node_queue.front();
                node_queue.pop();
            }
            std::cout<<"("<<name<<", Destructor ends...)"<<std::endl;
        }

        bool                               IsEmpty             ()              const {return (root==NULL);}

        void                               Inorder             ();
        void                               Preorder            ();
        void                               Preorder            (BSTNode<K, E> *t);
        void                               Postorder           ();
        void                               Postorder           (BSTNode<K, E> *t);
        void                               LevelOrder          ();

        pair<K, E>*                        Get                 (const K &)     const;
        BSTNode<K, E>*                     GetNode             (const K &k, BSTNode<K, E> *&the_parent_node);
        void                               Insert              (const pair<K, E>&);
        void                               Delete              (const K &);
        void                               DeleteNode          (BSTNode<K, E> *the_node, BSTNode<K, E> *the_parent_node);


        BSTNode<K, E>*                     SearchLeftMostEngine (BSTNode<K, E>* current_node, BSTNode<K, E> *&parent_node);
        BSTNode<K, E>*                     SearchRightMostEngine(BSTNode<K, E>* current_node, BSTNode<K, E> *&parent_node);
        void                               SwapData             (BSTNode<K, E> *node1, BSTNode<K, E> *node2);

        std::string                        Name                ()              const {return name;}
        void                               SetName             (const std::string &in_name)    {name = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const BST &queue);
};

#include <BST.hpp>
#endif

