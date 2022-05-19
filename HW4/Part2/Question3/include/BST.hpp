//BST.hpp
#include <BST.h>
#include <cstdlib>
#include <cmath>

template <class K, class E>
void BST<K, E>::Delete(const K &k) const {
    BSTNode<K, E> *the_node = GetNode(k);

    if(the_node == NULL){
        throw std::runtime_error(std::string("Warning: No node with the key exists in the BST."));
    }

    if((the_node->leftchild != NULL) && (the_node->rightchild != NULL)){
        //Find the largest key in the left subtree

    }else if(the_node->leftchild != NULL){
    
    }else if(the_node->rightchild != NNULL){
    
    }else{
        delete the_node;
        the_node = NULL;
    }
}

template <class K, class E>
BSTNode<K, E>* BST<K, E>::GetNode(const K &k) const {
    BSTNode<K, E> *current_node = root;
    while(current_node){
        if(k < current_node->data.first){
            current_node = current_node->leftchild;
        }else if(k > current_node->data.first){
            current_node = current_node->rightchild;
        }else{
            return current_node;
        }
    }

    return NULL;
}

template <class K, class E>
pair<K, E>* BST<K, E>::Get(const K &k) const {
    BSTNode<K, E> *current_node = root;
    while(current_node){
        if(k < current_node->data.first){
            current_node = current_node->leftchild;
        }else if(k > current_node->data.first){
            current_node = current_node->rightchild;
        }else{
            return &current_node->data;
        }
    }

    return NULL;
}

template <class K, class E>
void BST<K, E>::Inorder(){
    std::stack<BSTNode<K, E>* > node_stack;
    BSTNode<K, E> *current_node = root;

    while(true){
        while(current_node){
            node_stack.push(current_node);
            current_node = current_node->leftchild;
        }

        if(node_stack.empty()){
            break;
        }

        current_node = node_stack.top();
        node_stack.pop();
        std::cout<<current_node<<" ";
        current_node = current_node->rightchild;
    }
    std::cout<<std::endl;
}

template <class K, class E>
void BST<K, E>::LevelOrder(){
    std::queue<BSTNode<K, E>* > node_queue;
    BSTNode<K, E>* current_node   = root;

    while(current_node != NULL){
        std::cout<<current_node<<" ";
        if(current_node->leftchild != NULL){
            node_queue.push(current_node->leftchild);
        }
        if(current_node->rightchild != NULL){
            node_queue.push(current_node->rightchild);
        }

        if(node_queue.empty()){
            break;
        }

        current_node = node_queue.front();
        node_queue.pop();
    }
    std::cout<<std::endl;
}

template <class K, class E>
void BST<K, E>::Preorder(){
    Preorder(root);
    std::cout<<std::endl;
}

template <class K, class E>
void BST<K, E>::Preorder(BSTNode<K, E> *t){
    if(t != NULL){
        std::cout<<t<<" ";
        Preorder(t->leftchild);
        Preorder(t->rightchild);
    }
}

template <class K, class E>
void BST<K, E>::Postorder(){
    Postorder(root);
    std::cout<<std::endl;
}

template <class K, class E>
void BST<K, E>::Postorder(BSTNode<K, E> *t){
    if(t != NULL){
        Postorder(t->leftchild);
        Postorder(t->rightchild);
        std::cout<<t<<" ";
    }
}

template <class K, class E>
void BST<K, E>::Insert(const pair<K, E>& the_pair){
    BSTNode<K, E> *p = root, *pp = 0;
    while(p){
        pp = p;
        if(the_pair.first < p->data.first){
            p = p->leftchild;
        }else if(the_pair.first > p->data.first){
            p = p->rightchild;
        }else{
            p->data.second = the_pair.second;
            return;
        }
    }

    p = new BSTNode<K, E>(the_pair, NULL, NULL);
    if(root){
        if(the_pair.first < pp->data.first){
            pp->leftchild = p;
        }else{
            pp->rightchild = p;
        }
    }else{
        root = p;
    }
}

template <class K, class E>
void BST<K, E>::operator=(const BST &other){
    std::cout<<"("<<name<<", Assignment operator=() is called...)"<<std::endl;
    std::queue<BSTNode<K, E>* > node_p_queue;
    std::queue<BSTNode<K, E>* > node_queue;
    BSTNode<K, E>* current_p_node = other.root;
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
    std::cout<<"("<<name<<", Assignment operator=() ends...)"<<std::endl;
}

template <class K, class E>
std::ostream & operator<<(std::ostream &os, const BSTNode<K, E>* out_node){
    if(out_node==NULL){
        throw std::runtime_error(std::string("Warning: Not available. The node does not exist."));
        return os;
    }

    os<<"("<<out_node->data.first<<", "<<out_node->data.second<<")";
    return os;
}

