//solution.cpp
#include <solution.h>

MatrixNode* Matrix::GetNode(const bool &b, Triple * const t){
    MatrixNode *x;
    if(av){
        x = av;
        av = av->right;
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

void Matrix::operator= (const Matrix &b){

}
