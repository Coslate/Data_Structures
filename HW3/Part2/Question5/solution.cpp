//solution.cpp
#include <solution.h>
#include <iostream>

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


void Matrix::Insert(int row, int col, int value){
    int count_row = 0;
    int count_col = 0;
    bool insert_row_done = false;
    bool insert_col_done = false;
    MatrixNode *current_row = headnode->right;//first row
    MatrixNode *current_col = headnode->right;//first col
    Triple t;

    t.row = row;
    t.col = col;
    t.value = value;
    MatrixNode *new_node = new MatrixNode(false, &t);

    //Insert the row
    while(current_row != headnode){
        MatrixNode *current_node = current_row->right;//first element
        MatrixNode *prev_node    = current_row;//first element

        if((current_node==current_row) && (count_row==row) && (!insert_row_done)){//empty row
            current_node->right = new_node;
            current_node->right->right = current_row;
            insert_row_done = true;
            break;
        }

        while((current_node != current_row) && (count_row==row) && (!insert_row_done)){//non-empty row
            if(current_node->triple.col > col){//do the insertion
                prev_node->right = new_node;
                prev_node->right->right = current_node;
                insert_row_done = true;
                break;
            }else if(current_node->triple.col == col){//add up the value
                current_node->triple.value += value;
                insert_row_done = true;
                break;
            }

            if(current_node->right == current_row){//insert at the last position
                current_node->right = new_node;
                current_node->right->right = current_row;
                insert_row_done = true;
                break;
            }

            prev_node = current_node;
            current_node = current_node->right;
        }

        if(insert_row_done){
            break;
        }
        current_row = current_row->next;
        count_row++;
    }

    //Insert the col
    while(current_col != headnode){
        MatrixNode *current_node = current_col->down;//first element
        MatrixNode *prev_node    = current_col;//first element

        if((current_node==current_col) && (count_col==col) && (!insert_col_done)){//empty col
            current_node->down = new_node;
            current_node->down->down = current_col;
            insert_col_done = true;
            break;
        }

        while((current_node != current_col) && (count_col==col) && (!insert_col_done)){//non-empty col
            if(current_node->triple.row > row){//do the insertion
                prev_node->down = new_node;
                prev_node->down->down = current_node;
                insert_col_done = true;
                break;
            }else if(current_node->triple.row == row){//add up the value
                //already add up the value in row insertion above
                insert_col_done = true;
                break;
            }

            if(current_node->down == current_col){//insert at the last position
                current_node->down = new_node;
                current_node->down->down = current_col;
                insert_col_done = true;
                break;
            }

            prev_node = current_node;
            current_node = current_node->down;
        }

        if(insert_col_done){
            break;
        }
        current_col = current_col->next;
        count_col++;
    }
}

void Matrix::Initialize(int row, int col, int num){
    int p = std::max(row, col);
    Triple s;
    s.row = row;
    s.col = col;
    s.value = num;

    headnode = new MatrixNode(false, &s);//handler(rows, cols, #nodes)
    if(p==0){//empty
        headnode->right = headnode;
        return;
    }

    //at least one row or one col
    MatrixNode **head = new MatrixNode* [p];
    for(int i=0;i<p;i++){
        head[i] = new MatrixNode(true, NULL);
    }

    //link the header nodes together
    for(int i=0;i<(p-1);i++){
        head[i]->next = head[i+1];
    }

    head[p-1]->next = headnode;
    headnode->right = head[0];

    delete [] head;
}

Matrix Matrix::Transpose() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: "+name+" are empty. Cannot perform Transpose()."));
    }
    Matrix c(NULL, "c_tmp_transpose_result");
    c.Initialize(headnode->triple.col, headnode->triple.row, headnode->triple.value);

    //insert a^T
    MatrixNode *current_row = headnode->right;//first row
    while(current_row != headnode){
        MatrixNode *current_node = current_row->right;//first element
        while(current_node != current_row){
            c.Insert(current_node->triple.col, current_node->triple.row, current_node->triple.value);
            current_node = current_node->right;
        }
        current_row = current_row->next;
    }

    return c;
}

Matrix Matrix::operator+ (const Matrix &b){
    if(IsEmpty() && b.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Both of "+b.GetName()+" and "+name+" are empty. Cannot perform operator+()."));
    }else if(IsEmpty()){
        return b;
    }else if(b.IsEmpty()){
        return *this;
    }

    //check dimension
    int b_rows = b.headnode->triple.row;
    int b_cols = b.headnode->triple.col;
    int b_nums = b.headnode->triple.value;

    if((headnode->triple.row != b_rows) || (headnode->triple.col != b_cols)){
        throw std::runtime_error(std::string("Error: The dimensions of "+b.GetName()+" does not match with "+name+". Cannot perform operator+()."));
    }

    Matrix c(0, "tmp_c_plus_result");
    c.Initialize(b_rows, b_cols, b_nums);

    //First insert b
    MatrixNode *current_row = b.headnode->right;//first row
    while(current_row != b.headnode){
        MatrixNode *current_node = current_row->right;//first element
        while(current_node != current_row){
            c.Insert(current_node->triple.row, current_node->triple.col, current_node->triple.value);
            current_node = current_node->right;
        }
        current_row = current_row->next;
    }

    //Second insert a
    current_row = headnode->right;//first row
    while(current_row != headnode){
        MatrixNode *current_node = current_row->right;//first element
        while(current_node != current_row){
            c.Insert(current_node->triple.row, current_node->triple.col, current_node->triple.value);
            current_node = current_node->right;
        }
        current_row = current_row->next;
    }

    return c;
}

Matrix Matrix::operator* (const Matrix &b){
    if(IsEmpty() && b.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Both of "+b.GetName()+" and "+name+" are empty. Cannot perform operator*()."));
    }else if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: "+name+" is empty. Cannot perform operator*()."));
    }else if(b.IsEmpty()){
        throw std::runtime_error(std::string("Warning: "+b.GetName()+" is empty. Cannot perform operator*()."));
    }

    if(headnode->triple.col != b.headnode->triple.row){
        throw std::runtime_error(std::string("Error: The dimension of "+name+" and "+b.GetName()+" does not match. Cannot perform operator*()."));
    }

    Matrix c (NULL, "c_tmp_mul_result");
    Matrix bT(NULL, "bT");
    int count_nonz = 0; //non-zero product term

    //Initialize the result
    c.Initialize(headnode->triple.row, b.headnode->triple.col, headnode->triple.row*b.headnode->triple.col);

    //Transpose b
    bT = b.Transpose();

    //Perform a*b
    MatrixNode *current_row    = headnode->right;//first row of a
    MatrixNode *current_node   = current_row->right;//first element of a
    while(current_row != headnode){
        if(current_node != current_row){//not empty row
            MatrixNode *current_row_b  = bT.headnode->right;//first row of bT
            MatrixNode *current_node_b = current_row_b->right; //first element of bT
            while(current_row_b != bT.headnode){
                while((current_node_b != current_row_b) && (current_node != current_row)){//not empty row
                    if(current_node->triple.col == current_node_b->triple.col){
                        c.Insert(current_node->triple.row, current_node_b->triple.row, current_node->triple.value*current_node_b->triple.value);
                        count_nonz++;
                        current_node   = current_node->right;
                        current_node_b = current_node_b->right;
                    }else if(current_node->triple.col < current_node_b->triple.col){
                        current_node = current_node->right;
                    }else{
                        current_node_b = current_node_b->right;
                    }
                }

                if(current_node != current_row){//current_node_b==current_row_b reaches
                    current_node = current_row;//back to first element of a
                }

                current_row_b  = current_row_b->next;
                if(current_row_b != bT.headnode){
                    current_node_b = current_row_b->right;
                }

                current_node   = current_node->right;
            }
        }
        current_row = current_row->next;
        current_node = current_row->right;
    }

    c.SetTotalNum(count_nonz);
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


