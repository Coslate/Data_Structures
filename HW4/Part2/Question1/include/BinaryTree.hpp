//BinaryTree.hpp
#include <BinaryTree.h>
#include <sstream>
#include <cstdlib>

template <class T>
void BinaryTree<T>::NoStackInorder(){
    if(root == NULL) return;//empty binary tree
    BinaryTreeNode<T> *top = NULL;
    BinaryTreeNode<T> *last_right = NULL;
    BinaryTreeNode<T> *p, *q, *r, *r1;
    p = root;
    q = root;

    while(true){
        while(true){
            if((p->leftchild == NULL) && (p->rightchild == NULL)){//leaf node
                std::cout<<p->data<<" ";
                break;
            }
            if(p->leftchild == NULL){//visti p and move to p->rightchild
                std::cout<<p->data<<" ";
                r = p->rightchild;
                p->rightchild = q;
                q = p;
                p = r;
            }else{//move to p->leftchild
                r = p->leftchild;
                p->leftchild = q;
                q = p;
                p = r;
            }
        }//end inner while(true)

        //p is a leaf node, move up to the node of right subtree that has not been checked.
        BinaryTreeNode<T> *av = p;
        while(true){
            if(p == root){
                std::cout<<std::endl;
                return;
            }

            if(q->leftchild == NULL){
                r = q->rightchild;
                q->rightchild = p;
                p = q;
                q = r;
            }else if(q->rightchild == NULL){
                r = q->leftchild;
                q->leftchild = p;
                p = q;
                q = r;
                std::cout<<p->data<<" ";
            }else{
                if(q == last_right){
                    r = top;
                    last_right = r->leftchild;
                    top = r->rightchild;//move out from the stack
                    r->leftchild = NULL;
                    r->rightchild = NULL;
                    r = q->rightchild;
                    q->rightchild = p;
                    p = q;
                    q = r;
                }else{//p is leftchild of q
                    std::cout<<q->data<<" ";
                    av->leftchild = last_right;
                    av->rightchild = top;
                    top = av;
                    last_right = q;
                    r = q->leftchild;
                    q->leftchild = p;
                    r1 = q->rightchild;
                    q->rightchild = r;
                    p = r1;
                    break;
                }

            }

        }
    }//end outer while(true)

    std::cout<<std::endl;
}

template <class T>
void BinaryTree<T>::NorecInorder(){
    std::stack<BinaryTreeNode<T>* > node_stack;
    BinaryTreeNode<T> *current_node = root;

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
        std::cout<<current_node->data<<" ";
        current_node = current_node->rightchild;
    }
    std::cout<<std::endl;
}

template <class T>
bool BinaryTree<T>::operator==(const BinaryTree &t) const {
    bool is_eq = true;
    //Preorder Test
    is_eq = is_eq & PreorderEqualTest(root, t.root);

    //Inorder Test
    is_eq = is_eq & InorderEqualTest(root, t.root);

    return is_eq;
}

template <class T>
bool BinaryTree<T>::PreorderEqualTest(BinaryTreeNode<T> *t, BinaryTreeNode<T> *ot) const {
    bool is_eq = true;

    if((t != NULL) && (ot != NULL)){
        if(t->data == ot->data){
            is_eq = is_eq & PreorderEqualTest(t->leftchild, ot->leftchild);
            is_eq = is_eq & PreorderEqualTest(t->rightchild, ot->rightchild);
        }else{
            is_eq = false;
        }
    }else if((t == NULL) && (ot == NULL)){
        is_eq = true;
    }else{
        is_eq = false;
    }

    return is_eq;
}

template <class T>
bool BinaryTree<T>::InorderEqualTest(BinaryTreeNode<T> *t, BinaryTreeNode<T> *ot) const {
    bool is_eq = true;

    if((t != NULL) && (ot != NULL)){
        is_eq = is_eq & InorderEqualTest(t->leftchild, ot->leftchild);

        if(t->data == ot->data){
            is_eq = is_eq & true;
        }else{
            is_eq = false;
        }

        is_eq = is_eq & InorderEqualTest(t->rightchild, ot->rightchild);
    }else if((t==NULL) &&( ot == NULL)){
        is_eq = true;
    }else{
        is_eq = false;
    }

    return is_eq;
}

template <class T>
BinaryTree<T> BinaryTree<T>::LeftSubtree(){
    BinaryTree<T> binary_tree_left_tmp(*this);
    binary_tree_left_tmp.SetName("binary_tree_left_tmp");
    binary_tree_left_tmp.root = binary_tree_left_tmp.root->leftchild;

    return binary_tree_left_tmp;
}

template <class T>
BinaryTree<T> BinaryTree<T>::RightSubtree(){
    BinaryTree<T> binary_tree_right_tmp(*this);
    binary_tree_right_tmp.SetName("binary_tree_right_tmp");
    binary_tree_right_tmp.root = binary_tree_right_tmp.root->rightchild;

    return binary_tree_right_tmp;
}

template <class T>
void BinaryTree<T>::LevelOrder(){
    std::queue<BinaryTreeNode<T>* > node_queue;
    BinaryTreeNode<T>* current_node   = root;

    while(current_node != NULL){
        std::cout<<current_node->data<<" ";
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

template <class T>
void BinaryTree<T>::Inorder(){
    Inorder(root);
    std::cout<<std::endl;
}

template <class T>
void BinaryTree<T>::Inorder(BinaryTreeNode<T> *t){
    if(t != NULL){
        Inorder(t->leftchild);
        std::cout<<t->data<<" ";
        Inorder(t->rightchild);
    }
}

template <class T>
void BinaryTree<T>::Preorder(){
    Preorder(root);
    std::cout<<std::endl;
}

template <class T>
void BinaryTree<T>::Preorder(BinaryTreeNode<T> *t){
    if(t != NULL){
        std::cout<<t->data<<" ";
        Preorder(t->leftchild);
        Preorder(t->rightchild);
    }
}

template <class T>
void BinaryTree<T>::Postorder(){
    Postorder(root);
    std::cout<<std::endl;
}

template <class T>
void BinaryTree<T>::Postorder(BinaryTreeNode<T> *t){
    if(t != NULL){
        Postorder(t->leftchild);
        Postorder(t->rightchild);
        std::cout<<t->data<<" ";
    }
}

template <class T>
void BinaryTree<T>::operator=(const BinaryTree &other){
    std::queue<BinaryTreeNode<T>* > node_p_queue;
    std::queue<BinaryTreeNode<T>* > node_queue;
    BinaryTreeNode<T>* current_p_node = other.root;
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
}

template <class T>
std::ostream & operator<<(std::ostream &os, const BinaryTreeNode<T>* out_node){
    if(out_node==NULL){
        throw std::runtime_error(std::string("Warning: Not available. The node does not exist."));
        return os;
    }

    os<<out_node->data;
    return os;
}

template <typename T>
T ConvertTo (const std::string &str){
    std::istringstream ss(str);
    T num;
    ss >> num;
    return num;
}

template <class T>
void Set1(BinaryTree<T> &out_binary_tree){
    BinaryTreeNode<T> *A    = new BinaryTreeNode<T>(ConvertTo<T>("A"), NULL, NULL);
    BinaryTreeNode<T> *B    = new BinaryTreeNode<T>(ConvertTo<T>("B"), NULL, NULL);
    BinaryTreeNode<T> *C    = new BinaryTreeNode<T>(ConvertTo<T>("C"), NULL, NULL);
    BinaryTreeNode<T> *D    = new BinaryTreeNode<T>(ConvertTo<T>("D"), NULL, NULL);
    BinaryTreeNode<T> *E    = new BinaryTreeNode<T>(ConvertTo<T>("E"), NULL, NULL);

    BinaryTreeNode<T> *sub   = new BinaryTreeNode<T>(ConvertTo<T>("-"), A, B);
    BinaryTreeNode<T> *mul2  = new BinaryTreeNode<T>(ConvertTo<T>("*"), sub, C);
    BinaryTreeNode<T> *mul1  = new BinaryTreeNode<T>(ConvertTo<T>("*"), mul2, D);
    BinaryTreeNode<T> *plus  = new BinaryTreeNode<T>(ConvertTo<T>("+"), mul1, E);

    out_binary_tree.root = plus;
}

template <class T>
void Set2(BinaryTree<T> &out_binary_tree){
    BinaryTreeNode<T> *J    = new BinaryTreeNode<T>(ConvertTo<T>("J"), NULL, NULL);
    BinaryTreeNode<T> *H    = new BinaryTreeNode<T>(ConvertTo<T>("H"), NULL, NULL);
    BinaryTreeNode<T> *G    = new BinaryTreeNode<T>(ConvertTo<T>("G"), NULL, NULL);
    BinaryTreeNode<T> *F    = new BinaryTreeNode<T>(ConvertTo<T>("F"), NULL, NULL);
    BinaryTreeNode<T> *E    = new BinaryTreeNode<T>(ConvertTo<T>("E"), NULL, NULL);
    BinaryTreeNode<T> *D    = new BinaryTreeNode<T>(ConvertTo<T>("D"), H, J);
    BinaryTreeNode<T> *C    = new BinaryTreeNode<T>(ConvertTo<T>("C"), F, G);
    BinaryTreeNode<T> *B    = new BinaryTreeNode<T>(ConvertTo<T>("B"), D, E);
    BinaryTreeNode<T> *A    = new BinaryTreeNode<T>(ConvertTo<T>("A"), B, C);

    out_binary_tree.root = A;
}

template <class T>
void Display1(const BinaryTree<T> &out_binary_tree){
    if(out_binary_tree.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Not available. The BinaryTree is empty."));
    }

    std::cout<<out_binary_tree.name<<" = "<<std::endl;
    BinaryTreeNode<T> *plus = out_binary_tree.root;
    BinaryTreeNode<T> *mul1 = plus->leftchild;
    BinaryTreeNode<T> *mul2 = mul1->leftchild;
    BinaryTreeNode<T> *sub  = mul2->leftchild;
    BinaryTreeNode<T> *A    = sub->leftchild;
    BinaryTreeNode<T> *B    = sub->rightchild;
    BinaryTreeNode<T> *C    = mul2->rightchild;
    BinaryTreeNode<T> *D    = mul1->rightchild;
    BinaryTreeNode<T> *E    = plus->rightchild;

    std::cout<<"\t\t\t\t\t"<<plus->data<<std::endl;
    std::cout<<"--------------------------------------------------------------"<<std::endl;
    std::cout<<"\t\t\t\t"<<mul1->data<<"\t\t"<<E->data<<std::endl;
    std::cout<<"--------------------------------------------------------------"<<std::endl;
    std::cout<<"\t\t\t"<<mul2->data<<"\t\t"<<D->data<<std::endl;
    std::cout<<"--------------------------------------------------------------"<<std::endl;
    std::cout<<"\t\t"<<sub->data<<"\t\t"<<C->data<<std::endl;
    std::cout<<"--------------------------------------------------------------"<<std::endl;
    std::cout<<"\t"<<A->data<<"\t\t"<<B->data<<std::endl;
}

template <class T>
void Display2(const BinaryTree<T> &out_binary_tree){
    if(out_binary_tree.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Not available. The BinaryTree is empty."));
    }

    std::cout<<out_binary_tree.name<<" = "<<std::endl;
    BinaryTreeNode<T> *A = out_binary_tree.root;
    BinaryTreeNode<T> *B = A->leftchild;
    BinaryTreeNode<T> *C = A->rightchild;
    BinaryTreeNode<T> *D = B->leftchild;
    BinaryTreeNode<T> *E = B->rightchild;
    BinaryTreeNode<T> *F = C->leftchild;
    BinaryTreeNode<T> *G = C->rightchild;
    BinaryTreeNode<T> *H = D->leftchild;
    BinaryTreeNode<T> *J = D->rightchild;

    std::cout<<"\t\t\t\t\t"<<A->data<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    std::cout<<"\t\t\t"<<B->data<<"\t\t\t\t"<<C->data<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    std::cout<<"\t\t"<<D->data<<"\t\t"<<E->data<<"\t\t"<<F->data<<"\t\t"<<G->data<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    std::cout<<"\t"<<H->data<<"\t\t"<<J->data<<std::endl;
}

/*
template <typename CoefType, typename ExpType>
bool Polynomial<CoefType, ExpType>::SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b){
    return (a.exp > b.exp);
}
*/

