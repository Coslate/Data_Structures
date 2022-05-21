//BST.hpp
#include <BST.h>
#include <cstdlib>
#include <cmath>

template <class K, class E>
void BST<K, E>::Split(const K &k, BST<K, E> &small, pair<K, E> *&mid, BST<K, E> &big){
    //Split the BST by the Key k
    if(root == NULL){
        small.root = NULL;
        big.root   = NULL;
        mid        = NULL;
        return;
    }
    K k_to_delete;
    E e_to_delete;
    pair<K, E> pair_to_delete(k_to_delete, e_to_delete);
    BSTNode<K, E> *s_head            = new BSTNode<K, E>(pair_to_delete);
    BSTNode<K, E> *s                 = s_head;
    BSTNode<K, E> *b_head            = new BSTNode<K, E>(pair_to_delete);
    BSTNode<K, E> *b                 = b_head;
    BSTNode<K, E> *current_node      = root;

    while(current_node){
        if(k < current_node->data.first){
            b->leftchild = current_node;
            b = current_node;
            current_node = current_node->leftchild;
        }else if(k > current_node->data.first){
            s->rightchild = current_node;
            s = current_node;
            current_node = current_node->rightchild;
        }else{
            s->rightchild = current_node->leftchild;
            b->leftchild  = current_node->rightchild;
            small.root    = s_head->rightchild;
            delete s_head;

            big.root      = b_head->leftchild;
            delete b_head;

            mid = new pair<K, E>(current_node->data.first, current_node->data.second);
            delete current_node;
            current_node = NULL;
            root         = NULL;
            return;
        }
    }

    //no pair with key k
    s->rightchild = NULL;
    b->leftchild  = NULL;
    small.root    = s_head->rightchild;
    delete s_head;

    big.root   = b_head->leftchild;
    delete b_head;
    mid  = NULL;
    root = NULL;
    return;
}

template <class K, class E>
int BST<K, E>::BuildRootSize(BSTNode<K, E> *node){
    if((node->leftchild != NULL) && (node->rightchild != NULL)){
        node->root_size = 1 + BuildRootSize(node->leftchild) + BuildRootSize(node->rightchild);
    }else if(node->leftchild != NULL){
        node->root_size = 1 + BuildRootSize(node->leftchild);
    }else if(node->rightchild != NULL){
        node->root_size = 1 + BuildRootSize(node->rightchild);
    }else{
        node->root_size = 1;
    }
    return node->root_size;
}

template <class K, class E>
void BST<K, E>::BuildLeftSize(){
    BuildRootSize(root);

    //Update left_size field of each node in the BST
    std::queue<BSTNode<K, E>* > node_queue;
    BSTNode<K, E>* current_node   = root;

    while(current_node != NULL){
        if(current_node->leftchild != NULL){
            current_node->left_size = 1 + current_node->leftchild->root_size;
            node_queue.push(current_node->leftchild);
        }else{
            current_node->left_size = 1;
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
}

template <class K, class E>
pair<K, E>* BST<K, E>::RankGet(int r){//search for the rth smallest pair
    BuildLeftSize();

    BSTNode<K, E> *current_node = root;
    while(current_node){
        if(r < current_node->left_size){
            current_node = current_node->leftchild;
        }else if(r > current_node->left_size){
            r -= current_node->left_size;
            current_node = current_node->rightchild;
        }else{
            return &current_node->data;
        }
    }

    return NULL;
}

template <class K, class E>
BSTNode<K, E>* BST<K, E>::SearchLeftMostEngine(BSTNode<K, E>* current_node, BSTNode<K, E> *&parent_node){
    parent_node = NULL;
    while((current_node != NULL) && (current_node->leftchild != NULL)){
        parent_node = current_node;
        current_node = current_node->leftchild;
    }
    return current_node;
}

template <class K, class E>
BSTNode<K, E>* BST<K, E>::SearchRightMostEngine(BSTNode<K, E>* current_node, BSTNode<K, E> *&parent_node){
    parent_node = NULL;
    while((current_node != NULL) && (current_node->rightchild != NULL)){
        parent_node = current_node;
        current_node = current_node->rightchild;
    }
    return current_node;
}

template <class K, class E>
void BST<K, E>::SwapData(BSTNode<K, E> *node1, BSTNode<K, E> *node2){
    pair<K, E> tmp = node1->data;
    node1->data = node2->data;
    node2->data = tmp;
}

template <class K, class E>
void BST<K, E>::DeleteNode(BSTNode<K, E> *the_node, BSTNode<K, E> *the_parent_node){
    if(the_node == NULL){
        throw std::runtime_error(std::string("Warning: input the_node does not exist in the BST. Cannot perform DeleteNode()."));
    }

    if((the_node->leftchild != NULL) && (the_node->rightchild != NULL)){
        //Find the largest key in the left subtree
        BSTNode<K, E> *successor_node = SearchRightMostEngine(the_node->leftchild, the_parent_node);
        if(the_parent_node == NULL){//the leftchild of the_node does not have rightchild
            the_parent_node = the_node;
        }
        SwapData(successor_node, the_node);
        DeleteNode(successor_node, the_parent_node);
    }else if(the_node->leftchild != NULL){
        if(the_parent_node->leftchild == the_node){
            the_parent_node->leftchild = the_node->leftchild;
        }else{
            the_parent_node->rightchild = the_node->leftchild;
        }

        the_node->leftchild = NULL;
        delete the_node;
        the_node = NULL;
    }else if(the_node->rightchild != NULL){
        if(the_parent_node->leftchild == the_node){
            the_parent_node->leftchild = the_node->rightchild;
        }else{
            the_parent_node->rightchild = the_node->rightchild;
        }

        the_node->rightchild = NULL;
        delete the_node;
        the_node = NULL;
    }else{//leaf node
        if(the_parent_node->leftchild == the_node){
            the_parent_node->leftchild = NULL;
        }else{
            the_parent_node->rightchild = NULL;
        }

        delete the_node;
        the_node = NULL;
    }
}

template <class K, class E>
void BST<K, E>::Delete(const K &k) {
    BSTNode<K, E> *the_parent_node = NULL;
    BSTNode<K, E> *the_node = GetNode(k, the_parent_node);

    if(the_node == NULL){
        throw std::runtime_error(std::string("Warning: No node with the key exists in the BST."));
    }

    if((the_node->leftchild != NULL) && (the_node->rightchild != NULL)){
        //Find the largest key in the left subtree
        BSTNode<K, E> *successor_node = SearchRightMostEngine(the_node->leftchild, the_parent_node);
        if(the_parent_node == NULL){//the leftchild of the_node does not have rightchild
            the_parent_node = the_node;
        }
        SwapData(successor_node, the_node);
        DeleteNode(successor_node, the_parent_node);
    }else if(the_node->leftchild != NULL){
        if(the_parent_node->leftchild == the_node){
            the_parent_node->leftchild = the_node->leftchild;
        }else{
            the_parent_node->rightchild = the_node->leftchild;
        }

        the_node->leftchild = NULL;
        delete the_node;
        the_node = NULL;
    }else if(the_node->rightchild != NULL){
        if(the_parent_node->leftchild == the_node){
            the_parent_node->leftchild = the_node->rightchild;
        }else{
            the_parent_node->rightchild = the_node->rightchild;
        }

        the_node->rightchild = NULL;
        delete the_node;
        the_node = NULL;
    }else{//leaf node
        if(the_parent_node->leftchild == the_node){
            the_parent_node->leftchild = NULL;
        }else{
            the_parent_node->rightchild = NULL;
        }

        delete the_node;
        the_node = NULL;
    }
}

template <class K, class E>
BSTNode<K, E>* BST<K, E>::GetNode(const K &k, BSTNode<K, E> *&the_parent_node){
    BSTNode<K, E> *current_node = root;
    the_parent_node             = NULL;
    while(current_node){
        if(k < current_node->data.first){
            the_parent_node = current_node;
            current_node = current_node->leftchild;
        }else if(k > current_node->data.first){
            the_parent_node = current_node;
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
void BST<K, E>::Inorder(bool print_left_size){
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
        if(print_left_size){
            current_node->PrintWithLeftSize();
            std::cout<<" ";
        }else{
            std::cout<<current_node<<" ";
        }
        current_node = current_node->rightchild;
    }
    std::cout<<std::endl;
}

template <class K, class E>
void BST<K, E>::LevelOrder(bool print_left_size){
    std::queue<BSTNode<K, E>* > node_queue;
    BSTNode<K, E>* current_node   = root;

    while(current_node != NULL){
        if(print_left_size){
            current_node->PrintWithLeftSize();
            std::cout<<" ";
        }else{
            std::cout<<current_node<<" ";
        }

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
void BST<K, E>::Preorder(bool print_left_size){
    Preorder(root, print_left_size);
    std::cout<<std::endl;
}

template <class K, class E>
void BST<K, E>::Preorder(BSTNode<K, E> *t, bool print_left_size){
    if(t != NULL){
        if(print_left_size){
            t->PrintWithLeftSize();
            std::cout<<" ";
        }else{
            std::cout<<t<<" ";
        }
        Preorder(t->leftchild, print_left_size);
        Preorder(t->rightchild, print_left_size);
    }
}

template <class K, class E>
void BST<K, E>::Postorder(bool print_left_size){
    Postorder(root, print_left_size);
    std::cout<<std::endl;
}

template <class K, class E>
void BST<K, E>::Postorder(BSTNode<K, E> *t, bool print_left_size){
    if(t != NULL){
        Postorder(t->leftchild, print_left_size);
        Postorder(t->rightchild, print_left_size);
        if(print_left_size){
            t->PrintWithLeftSize();
            std::cout<<" ";
        }else{
            std::cout<<t<<" ";
        }
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
        current_node = new BSTNode<K, E> (current_p_node->data, NULL, NULL, current_p_node->left_size, current_p_node->root_size);
        root         = current_node;
    }

    while(current_p_node != NULL){
        if(current_p_node->leftchild != NULL){
            node_p_queue.push(current_p_node->leftchild);
            current_node->leftchild = new BSTNode<K, E> (current_p_node->leftchild->data, NULL, NULL, current_p_node->leftchild->left_size, current_p_node->leftchild->root_size);
            node_queue.push(current_node->leftchild);
        }
        if(current_p_node->rightchild != NULL){
            node_p_queue.push(current_p_node->rightchild);
            current_node->rightchild = new BSTNode<K, E> (current_p_node->rightchild->data, NULL, NULL, current_p_node->rightchild->left_size, current_p_node->rightchild->root_size);
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

