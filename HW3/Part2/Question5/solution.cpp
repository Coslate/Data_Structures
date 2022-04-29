//solution.cpp
#include <solution.h>

MatrixNode* Matrix::GetNode(const bool &b, Triple * const t){
    MatrixNode *x;
    if(av){
        x = av;
        av = av->right;

        //update x
        x->head = b;
        if(b){
            x->triple = *t;
        }
    }else{
        x = new MatrixNode (b, t);
    }

    return x;
}

void Matrix::RetNode(MatrixNode *&x){
    x->right = av;
    x->down  = NULL;
    av      = x;
    x       = NULL;
}

void Matrix::CleanAV(){
    while(av != NULL){
        MatrixNode *tmp_nxt = av->right;
        av->right = NULL;
        delete av;
        av = tmp_nxt;
    }
}

Matrix Matrix::Transpose(){
    Matrix c(NULL, "c_tmp_transpose_result");

    return c;
}

Matrix Matrix::operator+ (const Matrix &b){
    Matrix c(NULL, "c_tmp_transpose_result");
    return c;
}

Matrix Matrix::operator* (const Matrix &b){
    Matrix c(NULL, "c_tmp_transpose_result");
    return c;
}

void Matrix::DeleteAllNode(){
    if(!headnode){
        return;
    }

    MatrixNode *x = headnode->right;

    //return headnode
    headnode->right = av;
    av = headnode;

    //return nodes by rows
    while(x!=headnode){
        MatrixNode *y = x->right;
        x->right = av;
        av = y;
        x = x->next;//next row;
    }
    headnode = NULL;
}

void Matrix::operator= (const Matrix &b){
    std::cout<<"> Assignment operator=() of Matrix is called."<<std::endl;
    if(!IsEmpty()){
        DeleteAllNode();
    }

    //copy all the nodes
    Triple s;
    s.row = 0; s.col = 0; s.value = 0;
    if(b.headnode!=NULL){
        s.row   = b.headnode->triple.row;
        s.col   = b.headnode->triple.col;
        s.value = b.headnode->triple.value;
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

        MatrixNode *current_row = b.headnode->right;//first row
        while(current_row != b.headnode){
            MatrixNode *current_node = current_row->right;//first element

            if(current_node != current_row){
                last = head[current_node->triple.row];
                cur_row_num = current_node->triple.row;
            }

            while(current_node != current_row){
                //Insert the row element
                //last->right = new MatrixNode(false, &current_node->triple);
                last->right = GetNode(false, &current_node->triple);
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


