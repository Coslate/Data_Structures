#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>

template <class T>
class BinaryTree; //forward declaration

template <class T>
class BinaryTreeNode; //forward declaration

template <typename T>
T ConvertTo (const std::string &str);

template <typename T>
void Set1(BinaryTree<T> &out_binary_tree);

template <typename T>
void Set2(BinaryTree<T> &out_binary_tree);

template <typename T>
void Display1(const BinaryTree<T> &out_binary_tree);

template <typename T>
void Display2(const BinaryTree<T> &out_binary_tree);

template <typename T>
std::ostream & operator<<(std::ostream &os, const BinaryTreeNode<T> *out_node);

template <class T>
class BinaryTreeNode{
    private:
        T                  data;
        BinaryTreeNode<T>* leftchild;
        BinaryTreeNode<T>* rightchild;
    public:
        BinaryTreeNode(const T &in_data, BinaryTreeNode<T>* const leftchild=NULL, BinaryTreeNode<T>* const rightchild=NULL) : data(in_data), leftchild(leftchild), rightchild(rightchild){}
        ~BinaryTreeNode(){}
        friend class BinaryTree<T>;
        friend void Set1<T>(BinaryTree<T> &out_binary_tree);
        friend void Set2<T>(BinaryTree<T> &out_binary_tree);
        friend void Display1<T>(const BinaryTree<T> &out_binary_tree);
        friend void Display2<T>(const BinaryTree<T> &out_binary_tree);
        friend std::ostream & operator<<<T>(std::ostream &os, const BinaryTreeNode<T> *out_node);
};

template <class T>
class BinaryTree{
    private:
        std::string name;
        BinaryTreeNode<T> *root;

    public:
        BinaryTree():name("NULL"), root(NULL){}
        BinaryTree(const std::string &name):name(name), root(NULL){}
        BinaryTree(BinaryTreeNode<T> *root, const std::string &name = "NULL"):name(name), root(root){}

        //Copy consturctor
        BinaryTree(const BinaryTree &p){
            std::cout<<"("<<p.name<<", Copy Constructor() is called...)"<<std::endl;
            std::queue<BinaryTreeNode<T>* > node_p_queue;
            std::queue<BinaryTreeNode<T>* > node_queue;
            name                              = p.name;
            BinaryTreeNode<T>* current_p_node = p.root;
            BinaryTreeNode<T>* current_node   = root;

            if(current_p_node != NULL){
                current_node = new BinaryTreeNode<T> (current_p_node->data, NULL, NULL);
                root         = current_node;
            }

            while(current_p_node != NULL){
                if(current_p_node->leftchild != NULL){
                    node_p_queue.push(current_p_node->leftchild);
                    current_node->leftchild = new BinaryTreeNode<T> (current_p_node->leftchild->data, NULL, NULL);
                    node_queue.push(current_node->leftchild);
                }
                if(current_p_node->rightchild != NULL){
                    node_p_queue.push(current_p_node->rightchild);
                    current_node->rightchild = new BinaryTreeNode<T> (current_p_node->rightchild->data, NULL, NULL);
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

        //Constructor given the root item and left subtrees bt1 and right subtree bt2
        BinaryTree(BinaryTree<T> &bt1, T &item, BinaryTree<T> &bt2){
            root =new BinaryTreeNode<T>(item, bt1.root, bt2.root);
        }

        //Destructor
        ~BinaryTree(){
            std::cout<<"("<<name<<", Destructor is called...)"<<std::endl;
            std::queue<BinaryTreeNode<T>* > node_queue;
            BinaryTreeNode<T>* current_node   = root;

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

        bool                               IsEmpty             () const {return (root==NULL);}
        T                                  RootData            () const {return (root->data);}
        BinaryTree<T>                      LeftSubtree         ();
        BinaryTree<T>                      RightSubtree        ();

        void                               Inorder             ();
        void                               Inorder             (BinaryTreeNode<T> *t);
        void                               NorecInorder        ();
        void                               NoStackInorder      ();
        void                               Preorder            ();
        void                               Preorder            (BinaryTreeNode<T> *t);
        void                               Postorder           ();
        void                               Postorder           (BinaryTreeNode<T> *t);
        void                               LevelOrder          ();
        bool                               PreorderEqualTest   (BinaryTreeNode<T> *t, BinaryTreeNode<T> *ot) const;
        bool                               InorderEqualTest    (BinaryTreeNode<T> *t, BinaryTreeNode<T> *ot) const;
        bool                               operator==          (const BinaryTree &t) const;


        std::string                        Name                () const {return name;}
        void                               SetName             (const std::string &in_name)    {name = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const BinaryTree &other);
        friend void Set1<T>(BinaryTree<T> &out_binary_tree);
        friend void Set2<T>(BinaryTree<T> &out_binary_tree);
        friend void Display1<T>(const BinaryTree<T> &out_binary_tree);
        friend void Display2<T>(const BinaryTree<T> &out_binary_tree);

};

#include <BinaryTree.hpp>
#endif

