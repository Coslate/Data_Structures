#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>

struct Triple {
    int row, col, value;
};

class Matrix; //forward declaration

std::istream & operator>>(std::istream &is, Matrix &in_matrix);//forward declaration
std::ostream & operator<<(std::ostream &os, const Matrix &out_matrix); //forward declaration

class MatrixNode{
    private:
        MatrixNode *down;
        MatrixNode *right;
        bool        head;
        union {//union without a name
            MatrixNode* next;
            Triple triple;
        };

    public:
        MatrixNode(const bool &b, Triple *t){
            head = b;
            if(b){
                right = this;
                down  = this;
                next  = this;
            }else{
                right = NULL;
                down  = NULL;
                triple = *t;
            }
        }

        //Copy consturctor
        MatrixNode(const MatrixNode &p){
            down  = p.down;
            right = p.right;
            head  = p.head;

            if(head){
                next = p.next;
            }else{
                triple = p.triple;
            }
        }

        void operator=(const MatrixNode &p){
            down  = p.down;
            right = p.right;
            head  = p.head;

            if(head){
                next = p.next;
            }else{
                triple = p.triple;
            }
        }

        //Destructor
        ~MatrixNode(){
            down  = NULL;
            right = NULL;
            if(head){
                next = NULL;
                head = false;
            }
        }

        friend std::istream & operator>>(std::istream &is, Matrix &in_matrix);
        friend std::ostream & operator<<(std::ostream &os, const Matrix &out_matrix);

        friend std::ostream & operator<<(std::ostream &os, const MatrixNode &out_node){
            if(!out_node.head){
                os<<"("<<out_node.triple.row<<", "<<out_node.triple.col<<", "<<out_node.triple.value<<")";
            }else{
                os<<"";
            }

            return os;
        }

        friend class Matrix;
};

class Matrix{
    private:
        MatrixNode               *headnode;
        MatrixNode               *av;
        std::string              name;

    public:
        Matrix(MatrixNode *in_headnode=NULL, const std::string &name="NULL"): headnode(in_headnode), av(NULL), name(name){}

        //Copy consturctor
        Matrix(const Matrix &in_matrix){
            std::cout<<"> Copy constructor of Matrix is called."<<std::endl;
            av = NULL;

            //copy all the nodes
            Triple s;
            s.row = 0; s.col = 0; s.value = 0;
            if(in_matrix.headnode!=NULL){
                s.row   = in_matrix.headnode->triple.row;
                s.col   = in_matrix.headnode->triple.col;
                s.value = in_matrix.headnode->triple.value;
            }
            int p = std::max(s.row, s.col);

            headnode = new MatrixNode(false, &s);//handler(rows, cols, #nodes)
            if(p==0){//empty
                headnode->right = headnode;
            }else{
                int cur_row_num        = 0;
                MatrixNode *last       = NULL;
                MatrixNode **head      = new MatrixNode* [p];

                for(int i=0;i<p;i++){
                    head[i] = new MatrixNode(true, NULL);
                }

                MatrixNode *current_row = in_matrix.headnode->right;//first row
                while(current_row != in_matrix.headnode){
                    MatrixNode *current_node = current_row->right;//first element

                    if(current_node != current_row){
                        last = head[current_node->triple.row];
                        cur_row_num = current_node->triple.row;
                    }

                    while(current_node != current_row){
                        //Insert the row element
                        last->right = new MatrixNode(false, &current_node->triple);
                        last        = last->right;

                        //Insert the col element
                        head[current_node->triple.col]->next->down = last;
                        head[current_node->triple.col]->next = head[current_node->triple.col]->next->down;

                        //Next element
                        current_node = current_node->right;

                        if(current_node == current_row){
                            last->right = head[cur_row_num];//close the row
                        }
                    }

                    //Next row
                    current_row = current_row->next;
                }

                for(int i=0;i<s.col;i++){
                    head[i]->next->down = head[i];//close all column lists
                }

                //link the header nodes together
                for(int i=0;i<(p-1);i++){
                    head[i]->next = head[i+1];
                }

                head[p-1]->next = headnode;
                headnode->right = head[0];

                delete [] head;
            }
        }

        //Destructor
        ~Matrix(){
            if(!headnode){
                //Clean the av list;
                CleanAV();
                return;
            }

            //Return all nodes to av list
            DeleteAllNode();

            //Clean the av list
            CleanAV();
        }

        bool                               IsEmpty             () const {return ((headnode==NULL) || (headnode!=NULL && headnode->triple.value==0));}
        std::string                        GetName             () const {return name;}
        void                               SetName             (const std::string &in_name)   {name     = in_name;}

        Matrix                             Transpose           (); //Clean all the nodes in av;
        Matrix                             operator+           (const Matrix &b);
        Matrix                             operator*           (const Matrix &b);
        void                               operator=           (const Matrix &b);

        MatrixNode*                        GetNode             (const bool &b, Triple * const t);
        void                               RetNode             (MatrixNode *&x);
        void                               CleanAV             ();
        void                               DeleteAllNode       ();

        void                               Initialize          (int row, int col, int num);
        void                               Insert              (int row, int col, int value);

//        static bool SortFunction(const Term &a, const Term &b);

        friend std::ostream & operator<<(std::ostream &os, const Matrix &out_matrix){
            if(out_matrix.IsEmpty()){
                throw std::runtime_error(std::string(out_matrix.name+" = Warning: Not available. The Matrix is empty."));
                return os;
            }

            os<<out_matrix.name<<" = "<<std::endl;
            MatrixNode *current_row = out_matrix.headnode->right;//first row
            while(current_row != out_matrix.headnode){
                MatrixNode *current_node = current_row->right;//first element
                while(current_node != current_row){
                    os<<*current_node;
                    os<<std::endl;
                    current_node = current_node->right;
                }
                current_row = current_row->next;
            }
            return os;
        }

        friend std::istream & operator>>(std::istream &is, Matrix &in_matrix){
            Triple s;
            std::cout<<"Please enter {rows} {cols} {#nodes} of the matrix."<<std::endl;
            is >> s.row >> s.col >> s.value; //matrix dimensions
            int p = std::max(s.row, s.col);

            in_matrix.headnode = new MatrixNode(false, &s);//handler(rows, cols, #nodes)
            if(p==0){//empty
                in_matrix.headnode->right = in_matrix.headnode;
                return is;
            }

            //at least one row or one col
            MatrixNode **head = new MatrixNode* [p];
            for(int i=0;i<p;i++){
                head[i] = new MatrixNode(true, NULL);
            }

            int current_row = 0;
            MatrixNode *last = head[0]; //start from head[0]
            for(int i=0;i<s.value;i++){
                Triple t;
                std::cout<<"Please enter {row} {col} {value} of the matrix node."<<std::endl;
                is >> t.row >> t.col >> t.value;
                if(t.row > current_row){
                    last->right = head[current_row]; //close the current_row
                    current_row = t.row;
                    last = head[current_row];//point to the current_row;
                }

                //Insert the row element
                last->right = new MatrixNode(false, &t);
                last        = last->right;

                //Insert the col element
                head[t.col]->next->down = last;
                head[t.col]->next = head[t.col]->next->down;
            }
            last->right = head[current_row];//close the last row

            for(int i=0;i<s.col;i++){
                head[i]->next->down = head[i];//close all column lists
            }

            //link the header nodes together
            for(int i=0;i<(p-1);i++){
                head[i]->next = head[i+1];
            }

            head[p-1]->next = in_matrix.headnode;
            in_matrix.headnode->right = head[0];

            delete [] head;
            return is;
        }
};

#endif

